#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream> 
#include <climits>
#include <fstream>

int32_t generate_random_32bit_integer() {
    return rand() % INT32_MAX;  // Generate a random number
}

std::string generate_random_expression() {
    std::vector<std::string> operators = {"+", "-", "*"};
    int op_index = rand() % operators.size();
    long left = generate_random_32bit_integer();
    long right = generate_random_32bit_integer();

    std::ostringstream oss;
    oss << "(simplify (" << operators[op_index] << " " << left << " " << right << "))";
    return oss.str();
}

int main() {
    std::srand(std::time(0));

    //std::ofstream file("fuzzer_test.smt2");

    for (int i = 0; i < 100000; ++i) {
        std::string expr = generate_random_expression();
        std::cout << expr << std::endl;
        //file << expr << std::endl;
    }

    //file.close();

    return 0;
}