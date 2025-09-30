#ifndef COMPILER_TEST_TOKEN_STREAM_TOKEN_STREAM_H
#define COMPILER_TEST_TOKEN_STREAM_TOKEN_STREAM_H

#include <string>
#include <memory>
#include <vector>

#include "../token/token.h"

namespace token_stream
{
    class TokenStream
    {
        std::unique_ptr<std::vector<std::shared_ptr<token::Token>>> stream_data_;

    public:
        TokenStream(std::string input);
        int stream_length();
        std::shared_ptr<token::Token> GetToken(int index);
        void PrintDebugInfo();
    };
}

#endif//COMPILER_TEST_TOKEN_STREAM_TOKEN_STREAM_H