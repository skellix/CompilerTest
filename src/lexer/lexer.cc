#include "lexer.h"

#include <stdio.h>

#include <stdexcept>
#include <memory>
#include <sstream>
#include <iostream>
#include <format>

#include "../token_stream/token_stream.h"
#include "lexer_node/lexer_node.h"

namespace lexer
{
    Lexer::Lexer(std::shared_ptr<token_stream::TokenStream> token_stream)
    {
        this->nodes_ = std::make_unique<std::vector<std::shared_ptr<lexer_node::LexerNode>>>();
        this->nodes_->reserve(token_stream->stream_length());

        // fprintf(stdout, "stream_length = %d\n", token_stream->stream_length());

        for (int i = 0 ; i < token_stream->stream_length() ; ++ i)
        {
            this->nodes_->push_back(std::make_shared<lexer_node::LexerNode>());
        }
    }

    int Lexer::num_nodes()
    {
        return this->nodes_->size();
    }

    std::shared_ptr<lexer_node::LexerNode> Lexer::GetNode(int index)
    {
        if (index < 0 || this->nodes_->size() <= index)
        {
            throw std::invalid_argument("Index must be between 0 and streamLength");
        }
        
        return this->nodes_->at(index);
    }

    inline std::string PadRightToWidth(std::shared_ptr<lexer_node::LexerNode> value, int width)
    {
        std::stringstream ss1;

        ss1 << ((value != nullptr) ? value->token()->index() : 0);

        auto current_length = ss1.tellp();

        for (int i = current_length ; i < width ; ++ i)
        {
            ss1 << ' ';
        }

        return ss1.str();
    }

    void Lexer::PrintDebugInfo()
    {
        std::vector<std::string> headers;

        headers.push_back("#");
        headers.push_back("c  ");
        headers.push_back("digit");
        headers.push_back("whitespace_char");
        headers.push_back("plus");
        headers.push_back("minus");
        headers.push_back("multiply");
        headers.push_back("divide");
        headers.push_back("whitespace");
        headers.push_back("integer");
        headers.push_back("lr_operator");
        headers.push_back("operation");

        for (int i = 0 ; i < headers.size() ; ++ i)
        {
            if (i > 0)
            {
                std::cout << " | ";
            }

            std::cout << headers[i];
        }

        std::cout << std::endl;

        for (int i = 0 ; i < this->num_nodes() ; ++ i)
        {
            auto lexer_node = this->GetNode(i);
            auto token = lexer_node->token();

            std::stringstream ss;

            ss << std::format("{}", token->index()) << " | ";

            if (token->is_eof())
            {
                ss << "EOF";
            }
            else
            {
                ss << token->c() << "  ";
            }
            
            ss
            << " | "
            << PadRightToWidth(lexer_node->digit(), headers[2].length())
            << " | "
            << PadRightToWidth(lexer_node->whitespace_char(), headers[3].length())
            << " | "
            << PadRightToWidth(lexer_node->plus(), headers[4].length())
            << " | "
            << PadRightToWidth(lexer_node->minus(), headers[5].length())
            << " | "
            << PadRightToWidth(lexer_node->multiply(), headers[6].length())
            << " | "
            << PadRightToWidth(lexer_node->divide(), headers[7].length())
            << " | "
            << PadRightToWidth(lexer_node->whitespace(), headers[8].length())
            << " | "
            << PadRightToWidth(lexer_node->integer(), headers[9].length())
            << " | "
            << PadRightToWidth(lexer_node->lr_operator(), headers[10].length())
            << " | "
            << PadRightToWidth(lexer_node->operation(), headers[11].length())
            ;

            std::cout << ss.str() << std::endl;
        }
    }

    std::shared_ptr<Lexer> Lex(std::shared_ptr<token_stream::TokenStream> token_stream)
    {
        auto lexer = std::make_shared<Lexer>(token_stream);

        // initialize the nodes
        for (int i = lexer->num_nodes() - 1 ; i >= 0 ; -- i)
        {
            // fprintf(stdout, "i = %d\n", i);

            auto lexer_node = lexer->GetNode(i);
            lexer_node->set_token(token_stream->GetToken(i));

            if (i + 1 < lexer->num_nodes())
            {
                auto next = lexer->GetNode(i + 1);
                lexer_node->set_next(next);
                LexDigit(lexer_node);
                LexWhitespaceChar(lexer_node);
                LexPlus(lexer_node);
                LexMinus(lexer_node);
                LexMultiply(lexer_node);
                LexDivide(lexer_node);
                LexWhitespace(lexer_node);
                LexInteger(lexer_node);
                LexLrOperator(lexer_node);
                LexOperation(lexer_node);
            }
        }

        return lexer;
    }

    void LexDigit(std::shared_ptr<lexer_node::LexerNode> lexer_node)
    {
        auto token = lexer_node->token();
        auto c = token->c();
        
        if ('0' <= c && c <= '9')
        {
            lexer_node->set_digit(lexer_node->next());
        }
    }

    void LexWhitespaceChar(std::shared_ptr<lexer_node::LexerNode> lexer_node)
    {
        auto token = lexer_node->token();
        auto c = token->c();
        
        if (c == ' ' || c == '\t' || c == '\r' || c == '\n')
        {
            lexer_node->set_whitespace_char(lexer_node->next());
        }
    }

    void LexPlus(std::shared_ptr<lexer_node::LexerNode> lexer_node)
    {
        auto token = lexer_node->token();
        auto c = token->c();
        
        if (c == '+')
        {
            lexer_node->set_plus(lexer_node->next());
        }
    }

    void LexMinus(std::shared_ptr<lexer_node::LexerNode> lexer_node)
    {
        auto token = lexer_node->token();
        auto c = token->c();
        
        if (c == '-')
        {
            lexer_node->set_minus(lexer_node->next());
        }
    }

    void LexMultiply(std::shared_ptr<lexer_node::LexerNode> lexer_node)
    {
        auto token = lexer_node->token();
        auto c = token->c();
        
        if (c == '*')
        {
            lexer_node->set_multiply(lexer_node->next());
        }
    }

    void LexDivide(std::shared_ptr<lexer_node::LexerNode> lexer_node)
    {
        auto token = lexer_node->token();
        auto c = token->c();
        
        if (c == '/')
        {
            lexer_node->set_divide(lexer_node->next());
        }
    }

    void LexWhitespace(std::shared_ptr<lexer_node::LexerNode> lexer_node)
    {
        auto current_node = lexer_node;

        while (current_node != nullptr)
        {
            auto whitespace_char = current_node->whitespace_char();

            if (whitespace_char == nullptr)
            {
                break;
            }
            else
            {
                current_node = whitespace_char;
            }
        }

        if (current_node != lexer_node)
        {
            lexer_node->set_whitespace(current_node);
        }
    }

    void LexInteger(std::shared_ptr<lexer_node::LexerNode> lexer_node)
    {
        auto current_node = lexer_node;

        while (current_node != nullptr)
        {
            auto digit = current_node->digit();

            if (digit == nullptr)
            {
                break;
            }
            else
            {
                current_node = digit;
            }
        }

        if (lexer_node != current_node)
        {
            lexer_node->set_integer(current_node);
        }
    }

    void LexLrOperator(std::shared_ptr<lexer_node::LexerNode> lexer_node)
    {
        auto current_node = lexer_node->plus();

        if (current_node != nullptr)
        {
            lexer_node->set_lr_operator(current_node);
            return;
        }

        current_node = lexer_node->minus();

        if (current_node != nullptr)
        {
            lexer_node->set_lr_operator(current_node);
            return;
        }

        current_node = lexer_node->multiply();

        if (current_node != nullptr)
        {
            lexer_node->set_lr_operator(current_node);
            return;
        }

        current_node = lexer_node->divide();

        if (current_node != nullptr)
        {
            lexer_node->set_lr_operator(current_node);
            return;
        }
    }

    void LexOperation(std::shared_ptr<lexer_node::LexerNode> lexer_node)
    {
        auto current_node = lexer_node;

        if (current_node == nullptr)
        {
            return;
        }

        current_node = current_node->integer();

        if (current_node == nullptr)
        {
            return;
        }

        auto whitespace = current_node->whitespace();

        if (whitespace != nullptr)
        {
            current_node = whitespace;
        }

        current_node = current_node->lr_operator();

        if (current_node == nullptr)
        {
            return;
        }

        whitespace = current_node->whitespace();

        if (whitespace != nullptr)
        {
            current_node = whitespace;
        }

        current_node = current_node->integer();

        if (current_node == nullptr)
        {
            return;
        }

        lexer_node->set_operation(current_node);
    }
}