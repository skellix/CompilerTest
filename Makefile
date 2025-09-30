CC = g++
srcdir = src
includeDir = include
buildDir = build
std = -std=c++20
debug = -g -fdiagnostics-color=always

$(buildDir)/compiler_test.o: $(srcdir)/main.cc
	$(CC) -fPIC $(debug) $(std) -c $^ -o $@ -I$(srcdir) -I$(includeDir) -I$(buildDir)

$(buildDir)/lexer.o: $(srcdir)/lexer/lexer.cc
	$(CC) -fPIC $(debug) $(std) -c $^ -o $@ -I$(srcdir) -I$(includeDir) -I$(buildDir)

$(buildDir)/lexer_node.o: $(srcdir)/lexer/lexer_node/lexer_node.cc
	$(CC) -fPIC $(debug) $(std) -c $^ -o $@ -I$(srcdir) -I$(includeDir) -I$(buildDir)

$(buildDir)/token.o: $(srcdir)/token/token.cc
	$(CC) -fPIC $(debug) $(std) -c $^ -o $@ -I$(srcdir) -I$(includeDir) -I$(buildDir)

$(buildDir)/token_stream.o: $(srcdir)/token_stream/token_stream.cc
	$(CC) -fPIC $(debug) $(std) -c $^ -o $@ -I$(srcdir) -I$(includeDir) -I$(buildDir)

bin/compiler_test.exe: $(buildDir)/compiler_test.o $(buildDir)/lexer.o $(buildDir)/lexer_node.o $(buildDir)/token.o $(buildDir)/token_stream.o
	$(CC) $(debug) $(std) $^ -o $@ -I$(srcdir) -I$(includeDir) -I$(buildDir)

all: bin/compiler_test.exe

run: all
	bin/compiler_test.exe -s test.src