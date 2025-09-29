#ifndef COMPILER_TEST_LEXER_LEXER_H
#define COMPILER_TEST_LEXER_LEXER_H

#include <memory>

#include "../token_stream/token_stream.h"
#include "lexer_node/lexer_node.h"

namespace lexer
{
    class Lexer
    {
        std::unique_ptr<std::vector<lexer_node::LexerNode>> nodes_;

    public:
        Lexer(std::shared_ptr<token_stream::TokenStream> token_stream);
        int num_nodes();
        lexer_node::LexerNode *GetNode(int index);
    };

    std::shared_ptr<Lexer> Lex(std::shared_ptr<token_stream::TokenStream> token_stream);
    void LexDigit(lexer_node::LexerNode *lexer_node);
    void LexWhitespaceChar(lexer_node::LexerNode *lexer_node);
    void LexPlus(lexer_node::LexerNode *lexer_node);
    void LexMinus(lexer_node::LexerNode *lexer_node);
    void LexMultiply(lexer_node::LexerNode *lexer_node);
    void LexDivide(lexer_node::LexerNode *lexer_node);
    void LexWhitespace(lexer_node::LexerNode *lexer_node);
    void LexInteger(lexer_node::LexerNode *lexer_node);
    void LexLrOperator(lexer_node::LexerNode *lexer_node);
    void LexOperation(lexer_node::LexerNode *lexer_node);
}

#endif//COMPILER_TEST_LEXER_LEXER_H