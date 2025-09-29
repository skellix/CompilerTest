#ifndef COMPILER_TEST_LEXER_LEXER_NODE_H_
#define COMPILER_TEST_LEXER_LEXER_NODE_H_

#include "../../token/token.h"

namespace lexer_node
{
    class LexerNode
    {
        token::Token *token_ = nullptr;
        LexerNode *next_ = nullptr;
        LexerNode *next_digit_ = nullptr;
        LexerNode *next_whitespace_char_ = nullptr;
        LexerNode *next_plus_ = nullptr;
        LexerNode *next_minus_ = nullptr;
        LexerNode *next_multiply_ = nullptr;
        LexerNode *next_divide_ = nullptr;
        LexerNode *next_whitespace_ = nullptr;
        LexerNode *next_integer_ = nullptr;
        LexerNode *next_lr_operator_ = nullptr;
        LexerNode *next_operation_ = nullptr;

    public:
        LexerNode();
        token::Token *token();
        void set_token(token::Token *token);

        LexerNode *next();
        void set_next(LexerNode *next);

        LexerNode *digit();
        void set_digit(LexerNode *next);

        LexerNode *whitespace_char();
        void set_whitespace_char(LexerNode *next);

        LexerNode *plus();
        void set_plus(LexerNode *next);

        LexerNode *minus();
        void set_minus(LexerNode *next);

        LexerNode *multiply();
        void set_multiply(LexerNode *next);

        LexerNode *divide();
        void set_divide(LexerNode *next);

        LexerNode *whitespace();
        void set_whitespace(LexerNode *next);

        LexerNode *integer();
        void set_integer(LexerNode *next);

        LexerNode *lr_operator();
        void set_lr_operator(LexerNode *next);

        LexerNode *operation();
        void set_operation(LexerNode *next);
    };
}

#endif//COMPILER_TEST_LEXER_LEXER_NODE_H_