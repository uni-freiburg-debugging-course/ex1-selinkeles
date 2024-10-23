#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>

#include "parser.cpp"

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::vector<Token>> tokens;

    while (std::getline(file, line)) {
        std::vector<Token> tokensLISP = tokenize(line);
        tokens.push_back(tokensLISP);
    }

    file.close();

    for(int i = 0; i < tokens.size(); i++) {
        std::vector<Token> tokensLISP = tokens[i];
        long result = parse_expression(tokensLISP);
        if (result < 0) {
            std::cout << "(- " + std::to_string(result * -1) + ")" << std::endl;
        }
        else {
            std::cout << result << std::endl;
        }
    }
    
    return 0;
}
