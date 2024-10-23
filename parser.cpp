#include <iostream>
#include <string>
#include <vector>

#include "lexer.cpp"  // Include your lexer code here

enum Operator { ADD, SUBTRACT, MULTIPLY, NONE };


struct Expression {
    Operator op;
    long left;
    long right;

    Expression() : op(NONE), left(0), right(0) {}
};

Operator parse_operator(const std::string& op) {
    if (op == "+") return ADD;
    if (op == "-") return SUBTRACT;
    if (op == "*") return MULTIPLY;
    return NONE;
}

// Function to evaluate the parsed expression
long evaluate(const Expression& expr) {
    switch (expr.op) {
        case ADD:
            return expr.left + expr.right;
        case SUBTRACT:
            return expr.left - expr.right;
        case MULTIPLY:
            return expr.left * expr.right;
        default:
            throw std::runtime_error("Unknown operator");
    }
}

// Function to parse the input expression
long parse_expression(const std::vector<Token>& tokens) {
    std::string op = tokens[3].tokenName;
    Expression expr;

    expr.op = parse_operator(op);

    expr.left = tokens[4].value;
    expr.right = tokens[5].value;

    return evaluate(expr);
}