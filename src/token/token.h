#ifndef COMPILER_TEST_TOKEN_TOKEN_H
#define COMPILER_TEST_TOKEN_TOKEN_H

namespace token
{
    class Token
    {
        char c_;
        bool is_eof_;
        int row_;
        int col_;
        int index_;

    public:
        Token();
        Token(char c, int index, int row, int col);
        Token(char c, int index, int row, int col, bool is_eof);
        char c();
        bool is_eof();
        int row();
        int col();
        int index();
        void set(char c, int index, int row, int col);
        void set(char c, int index, int row, int col, bool is_eof);
        void set_eof(bool is_eof);
    };
}

#endif//COMPILER_TEST_TOKEN_TOKEN_H