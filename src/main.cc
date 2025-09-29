#include <stdio.h>
#include <string.h>

#include "token_stream/token_stream.h"
#include "lexer/lexer.h"

void ShowHelp() {
    fprintf(stdout, "ussage:\n");
    fprintf(stdout, "  main.exe\n");
    fprintf(stdout, "  main.exe --help        : Show this help text and exit\n");
}

int main(int argc, char **argv)
{
    bool found_help_arg = false;

    for (int i = 0 ; i < argc ; ++ i)
    {
        char* arg = argv[i];

        fprintf(stdout, "arg[%d] = \"%s\"\n", i, arg);

        if (arg[0] == '-')
        {
            if (arg[1] == '-')
            {
                if (strncmp(arg + 2, "help", strlen("help")))
                {
                    found_help_arg = true;
                }
            }
        }
    }

    if (found_help_arg || argc <= 1)
    {
        ShowHelp();
        return 0;
    }

    fprintf(stdout, "Starting...\n");

    auto source = "1 + 1";
    auto token_stream = std::make_shared<token_stream::TokenStream>(source);
    auto lexer = lexer::Lex(token_stream);

    fprintf(stdout, "Done!\n");
}