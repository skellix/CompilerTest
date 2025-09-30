#include "token_stream.h"

#include <stdio.h>

#include <string>
#include <memory>
#include <stdexcept>

#include "../token/token.h"

namespace token_stream
{
    TokenStream::TokenStream(std::string input)
    {
        this->stream_data_ = std::make_unique<std::vector<std::shared_ptr<token::Token>>>();
        int row = 0;
        int col = 0;

        for (int i = 0 ; i < input.length() ; ++ i)
        {
            char c = input[i];

            this->stream_data_->push_back(std::make_shared<token::Token>(c, i, row, col, false));

            if (c == '\n')
            {
                ++ row;
                col = 0;
            }
            else
            {
                ++ col;
            }
        }

        this->stream_data_->push_back(std::make_shared<token::Token>(0, input.length(), row, col, true));
    }

    int TokenStream::stream_length()
    {
        return this->stream_data_->size();
    }

    std::shared_ptr<token::Token> TokenStream::GetToken(int index)
    {
        if (index < 0 || this->stream_data_->size() <= index)
        {
            throw std::invalid_argument("Index must be between 0 and streamLength");
        }

        return this->stream_data_->at(index);
    }

    void TokenStream::PrintDebugInfo()
    {
        for (int i = 0 ; i < this->stream_length() ; ++ i)
        {
            auto item = this->GetToken(i);

            if (item->is_eof())
            {
                fprintf(stdout, "%d:%d EOF\n", item->col(), item->row(), item->c());
            }
            else
            {
                fprintf(stdout, "%d:%d '%c'\n", item->col(), item->row(), item->c());
            }
        }
    }
}