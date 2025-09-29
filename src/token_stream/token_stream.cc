#include "token_stream.h"

#include <string>
#include <memory>
#include <stdexcept>

#include "../token/token.h"

namespace token_stream
{
    TokenStream::TokenStream(std::string input)
    {
        this->stream_data_ = std::make_unique<std::vector<token::Token>>();
        this->stream_data_->reserve(input.length() + 1);
        int row = 0;
        int col = 0;

        for (int i = 0 ; i < this->stream_data_->size() ; ++ i)
        {
            char c = input[i];
            auto stream_data_item = this->stream_data_->at(i);
            stream_data_item.set(c, i, row, col);

            if (c == '\n')\
            {
                ++ row;
                col = 0;
            }
            else
            {
                ++ col;
            }
        }

        this->stream_data_->back().set(0, input.length(), row, col, true);
    }

    int TokenStream::stream_length()
    {
        return this->stream_data_->size();
    }

    token::Token *TokenStream::GetToken(int index)
    {
        if (index < 0 || this->stream_data_->size() <= index)
        {
            throw std::invalid_argument("Index must be between 0 and streamLength");
        }

        return &this->stream_data_->at(index);
    }
}