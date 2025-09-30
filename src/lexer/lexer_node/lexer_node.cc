#include "lexer_node.h"

namespace lexer_node
{
    LexerNode::LexerNode()
    {
    }

    std::shared_ptr<token::Token> LexerNode::token()
    {
        return this->token_;
    }

    void LexerNode::set_token(std::shared_ptr<token::Token> token)
    {
        this->token_ = token;
    }

    std::shared_ptr<LexerNode> LexerNode::next()
    {
        return this->next_;
    }

    void LexerNode::set_next(std::shared_ptr<LexerNode> next)
    {
        this->next_ = next;
    }

    std::shared_ptr<LexerNode> LexerNode::digit()
    {
        return this->next_digit_;
    }

    void LexerNode::set_digit(std::shared_ptr<LexerNode> next)
    {
        this->next_digit_ = next;
    }

    std::shared_ptr<LexerNode> LexerNode::whitespace_char()
    {
        return this->next_whitespace_char_;
    }

    void LexerNode::set_whitespace_char(std::shared_ptr<LexerNode> next)
    {
        this->next_whitespace_char_ = next;
    }

    std::shared_ptr<LexerNode> LexerNode::plus()
    {
        return this->next_plus_;
    }

    void LexerNode::set_plus(std::shared_ptr<LexerNode> next)
    {
        this->next_plus_ = next;
    }

    std::shared_ptr<LexerNode> LexerNode::minus()
    {
        return this->next_minus_;
    }

    void LexerNode::set_minus(std::shared_ptr<LexerNode> next)
    {
        this->next_minus_ = next;
    }

    std::shared_ptr<LexerNode> LexerNode::multiply()
    {
        return this->next_multiply_;
    }

    void LexerNode::set_multiply(std::shared_ptr<LexerNode> next)
    {
        this->next_multiply_ = next;
    }

    std::shared_ptr<LexerNode> LexerNode::divide()
    {
        return this->next_divide_;
    }

    void LexerNode::set_divide(std::shared_ptr<LexerNode> next)
    {
        this->next_divide_ = next;
    }

    std::shared_ptr<LexerNode> LexerNode::whitespace()
    {
        return this->next_whitespace_;
    }

    void LexerNode::set_whitespace(std::shared_ptr<LexerNode> next)
    {
        this->next_whitespace_ = next;
    }

    std::shared_ptr<LexerNode> LexerNode::integer()
    {
        return this->next_integer_;
    }

    void LexerNode::set_integer(std::shared_ptr<LexerNode> next)
    {
        this->next_integer_ = next;
    }

    std::shared_ptr<LexerNode> LexerNode::lr_operator()
    {
        return this->next_lr_operator_;
    }

    void LexerNode::set_lr_operator(std::shared_ptr<LexerNode>  next)
    {
        this->next_lr_operator_ = next;
    }

    std::shared_ptr<LexerNode> LexerNode::operation()
    {
        return this->next_operation_;
    }

    void LexerNode::set_operation(std::shared_ptr<LexerNode> next)
    {
        this->next_operation_ = next;
    }
}