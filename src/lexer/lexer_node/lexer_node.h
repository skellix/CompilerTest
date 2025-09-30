#ifndef COMPILER_TEST_LEXER_LEXER_NODE_H_
#define COMPILER_TEST_LEXER_LEXER_NODE_H_

#include "../../token/token.h"

#include <memory>

namespace lexer_node
{
    class LexerNode
    {
        std::shared_ptr<token::Token> token_ = nullptr;
        std::shared_ptr<LexerNode> next_ = nullptr;
        std::shared_ptr<LexerNode> next_digit_ = nullptr;
        std::shared_ptr<LexerNode> next_whitespace_char_ = nullptr;
        std::shared_ptr<LexerNode> next_plus_ = nullptr;
        std::shared_ptr<LexerNode> next_minus_ = nullptr;
        std::shared_ptr<LexerNode> next_multiply_ = nullptr;
        std::shared_ptr<LexerNode> next_divide_ = nullptr;
        std::shared_ptr<LexerNode> next_whitespace_ = nullptr;
        std::shared_ptr<LexerNode> next_integer_ = nullptr;
        std::shared_ptr<LexerNode> next_lr_operator_ = nullptr;
        std::shared_ptr<LexerNode> next_operation_ = nullptr;

    public:
        LexerNode();
        std::shared_ptr<token::Token> token();
        void set_token(std::shared_ptr<token::Token> token);

        std::shared_ptr<LexerNode> next();
        void set_next(std::shared_ptr<LexerNode> next);

        std::shared_ptr<LexerNode> digit();
        void set_digit(std::shared_ptr<LexerNode> next);

        std::shared_ptr<LexerNode> whitespace_char();
        void set_whitespace_char(std::shared_ptr<LexerNode> next);

        std::shared_ptr<LexerNode> plus();
        void set_plus(std::shared_ptr<LexerNode> next);

        std::shared_ptr<LexerNode> minus();
        void set_minus(std::shared_ptr<LexerNode> next);

        std::shared_ptr<LexerNode> multiply();
        void set_multiply(std::shared_ptr<LexerNode> next);

        std::shared_ptr<LexerNode> divide();
        void set_divide(std::shared_ptr<LexerNode> next);

        std::shared_ptr<LexerNode> whitespace();
        void set_whitespace(std::shared_ptr<LexerNode> next);

        std::shared_ptr<LexerNode> integer();
        void set_integer(std::shared_ptr<LexerNode> next);

        std::shared_ptr<LexerNode> lr_operator();
        void set_lr_operator(std::shared_ptr<LexerNode> next);

        std::shared_ptr<LexerNode> operation();
        void set_operation(std::shared_ptr<LexerNode> next);
    };
}

#endif//COMPILER_TEST_LEXER_LEXER_NODE_H_