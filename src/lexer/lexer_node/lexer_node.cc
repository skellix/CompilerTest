#include "lexer_node.h"

namespace lexer_node
{
    LexerNode::LexerNode()
    {
    }

    token::Token *LexerNode::token()
    {
        return this->token_;
    }

    void LexerNode::set_token(token::Token *token)
    {
        this->token_ = token;
    }

    LexerNode *LexerNode::next()
    {
        return this->next_;
    }

    void LexerNode::set_next(LexerNode *next)
    {
        this->next_ = next;
    }

    LexerNode *LexerNode::digit()
    {
        return this->next_digit_;
    }

    void LexerNode::set_digit(LexerNode *next)
    {
        this->next_digit_ = next;
    }

    LexerNode *LexerNode::whitespace_char()
    {
        return this->next_whitespace_char_;
    }

    void LexerNode::set_whitespace_char(LexerNode *next)
    {
        this->next_whitespace_char_ = next;
    }

    LexerNode *LexerNode::plus()
    {
        return this->next_plus_;
    }

    void LexerNode::set_plus(LexerNode *next)
    {
        this->next_plus_ = next;
    }

    LexerNode *LexerNode::minus()
    {
        return this->next_minus_;
    }

    void LexerNode::set_minus(LexerNode *next)
    {
        this->next_minus_ = next;
    }

    LexerNode *LexerNode::multiply()
    {
        return this->next_multiply_;
    }

    void LexerNode::set_multiply(LexerNode *next)
    {
        this->next_multiply_ = next;
    }

    LexerNode *LexerNode::divide()
    {
        return this->next_divide_;
    }

    void LexerNode::set_divide(LexerNode *next)
    {
        this->next_divide_ = next;
    }

    LexerNode *LexerNode::whitespace()
    {
        return this->next_whitespace_;
    }

    void LexerNode::set_whitespace(LexerNode *next)
    {
        this->next_whitespace_ = next;
    }

    LexerNode *LexerNode::integer()
    {
        return this->next_integer_;
    }

    void LexerNode::set_integer(LexerNode *next)
    {
        this->next_integer_ = next;
    }

    LexerNode *LexerNode::lr_operator()
    {
        return this->next_lr_operator_;
    }

    void LexerNode::set_lr_operator(LexerNode * next)
    {
        this->next_lr_operator_ = next;
    }

    LexerNode *LexerNode::operation()
    {
        return this->next_operation_;
    }

    void LexerNode::set_operation(LexerNode *next)
    {
        this->next_operation_ = next;
    }
}