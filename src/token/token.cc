#include "token.h"

namespace token
{
    Token::Token() {
        this->is_eof_ = false;
    }

    Token::Token(char c, int index, int row, int col) {
        this->is_eof_ = false;
        this->c_ = c;
        this->index_ = index;
        this->row_ = row;
        this->col_ = col;
    }

    Token::Token(char c, int index, int row, int col, bool is_eof)
    {
        Token(c, index, row, col);
        this->is_eof_ = is_eof;
    }

    char Token::c()
    {
        return this->c_;
    }

    bool Token::is_eof()
    {
        return this->is_eof_;
    }

    int Token::row()
    {
        return this->row_;
    }

    int Token::col()
    {
        return this->col_;
    }

    int Token::index()
    {
        return this->index_;
    }

    void Token::set(char c, int index, int row, int col)
    {
        this->is_eof_ = false;
        this->c_ = c;
        this->index_ = index;
        this->row_ = row;
        this->col_ = col;
    }

    void Token::set(char c, int index, int row, int col, bool isEof)
    {
        Token(c, index, row, col);
        this->is_eof_ = isEof;
    }

    void Token::set_eof(bool isEof)
    {
        this->is_eof_ = isEof;
    }
}