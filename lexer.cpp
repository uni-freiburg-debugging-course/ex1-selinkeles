#include <iostream>
#include <string>
#include <vector>
#include <cctype>

enum class TokenType {
    TNUMBER,
    TPLUS,
    TKEYWORD,
    TMINUS,
    TMULTIPLY,
    TLPAREN,  // '('
    TRPAREN,  // ')'
    TEND      // End of input
};

struct Token {
    TokenType type;
    std::string tokenName;
    int value;
    
    Token(TokenType t, std::string name = "", double val = 0) : type(t), tokenName(name), value(val) {}
};

std::vector<Token> tokenize(const std::string& input) {
    std::vector<Token> tokens;
    size_t i = 0;

    while (i < input.size()) {
        if (std::isspace(input[i])) {
            ++i;
        } else if (std::isdigit(input[i])) {
            size_t start = i;
            while (i < input.size() && (std::isdigit(input[i]))) {
                ++i;
            }
            tokens.push_back(Token(TokenType::TNUMBER, std::string("number"), std::stoi(input.substr(start, i - start))));
        } else if (input[i] == 's') {
            if(input.substr(i, i + 7) == "simplify") {
                tokens.push_back(Token(TokenType::TKEYWORD, std::string("keyword")));
                i += 8;
            }
        } else if (input[i] == '+') {
            tokens.push_back(Token(TokenType::TPLUS, std::string("+")));
            ++i;
        } else if (input[i] == '-') {
            tokens.push_back(Token(TokenType::TMINUS, std::string("-")));
            ++i;
        } else if (input[i] == '*') {
            tokens.push_back(Token(TokenType::TMULTIPLY, std::string("*")));
            ++i;
        } else if (input[i] == '(') {
            tokens.push_back(Token(TokenType::TLPAREN, std::string("left_paran")));
            ++i;
        } else if (input[i] == ')') {
            tokens.push_back(Token(TokenType::TRPAREN, std::string("right_paran")));
            ++i;
        } else {
            throw std::runtime_error("Unknown character in input");
        }
    }
    
    tokens.push_back(Token(TokenType::TEND));
    return tokens;
}