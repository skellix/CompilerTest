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

    // token_stream->PrintDebugInfo();

    auto lexer = lexer::Lex(token_stream);

    if (lexer == nullptr)
    {
        fprintf(stderr, "Source file could not be lexed\n");
        return 1;
    }

    auto first_node = lexer->GetNode(0);

    if (first_node == nullptr)
    {
        fprintf(stderr, "Source file contains no tokens\n");
        return 1;
    }

    auto operation_end = first_node->operation();

    if (operation_end == nullptr)
    {
        auto token = first_node->token();
        // fprintf(stderr, "Expected expression at %d:%d\n", token->row() + 1, token->col() + 1);
        fprintf(stderr, "Expected expression at %d:%d\n", 1, 1);
        return 1;
    }

    auto operation_end_token = operation_end->token();

    if (operation_end_token->is_eof())
    {
        fprintf(stdout, "Lex successful!\n");
    }
    else
    {
        fprintf(stdout, "Lex failed!\n");
        return 1;
    }

    return 0;
}