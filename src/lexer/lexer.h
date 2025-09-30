#ifndef COMPILER_TEST_LEXER_LEXER_H
#define COMPILER_TEST_LEXER_LEXER_H

#include <memory>

#include "../token_stream/token_stream.h"
#include "lexer_node/lexer_node.h"

namespace lexer
{
    class Lexer
    {
        std::unique_ptr<std::vector<std::shared_ptr<lexer_node::LexerNode>>> nodes_;

    public:
        Lexer(std::shared_ptr<token_stream::TokenStream> token_stream);
        int num_nodes();
        std::shared_ptr<lexer_node::LexerNode> GetNode(int index);
        void PrintDebugInfo();
    };

    std::shared_ptr<Lexer> Lex(std::shared_ptr<token_stream::TokenStream> token_stream);
    void LexDigit(std::shared_ptr<lexer_node::LexerNode> lexer_node);
    void LexWhitespaceChar(std::shared_ptr<lexer_node::LexerNode> lexer_node);
    void LexPlus(std::shared_ptr<lexer_node::LexerNode> lexer_node);
    void LexMinus(std::shared_ptr<lexer_node::LexerNode> lexer_node);
    void LexMultiply(std::shared_ptr<lexer_node::LexerNode> lexer_node);
    void LexDivide(std::shared_ptr<lexer_node::LexerNode> lexer_node);
    void LexWhitespace(std::shared_ptr<lexer_node::LexerNode> lexer_node);
    void LexInteger(std::shared_ptr<lexer_node::LexerNode> lexer_node);
    void LexLrOperator(std::shared_ptr<lexer_node::LexerNode> lexer_node);
    void LexOperation(std::shared_ptr<lexer_node::LexerNode> lexer_node);
}

#endif//COMPILER_TEST_LEXER_LEXER_H