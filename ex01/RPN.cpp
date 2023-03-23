#include "RPN.hpp"

void unique_fonction(char **argv)
{
    std::stack<int> numbers;

    std::istringstream ss(argv[1]);

    std::string token;
    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (numbers.size() < 2) {
                std::cout << "Error: Insufficient operands for " << token << " operator." << std::endl;
                exit(1);
            }
            int n2 = numbers.top(); numbers.pop();
            int n1 = numbers.top(); numbers.pop();
            int result;
            if (token == "+")
                result = n1 + n2;
            else if (token == "-")
                result = n1 - n2;
            else if (token == "*")
                result = n1 * n2;
            else if (token == "/") {
                if (n2 == 0) {
                    std::cout << "Error: Division by zero." << std::endl;
                    exit(1);
                }
                result = n1 / n2;
            }
            numbers.push(result);
        }
        else {
            for(int i=0; token[i] !='\0'; i++) {
                if(token[i] < 48 || token[i] > 57) {
                    std::cout << "Error: bad input." << std::endl;
                    exit(1);
                }
            }
            int num = atoi(token.c_str());
            numbers.push(num);
        }
    }

    if (numbers.size() != 1) {
        std::cout << "Error: Invalid input expression." << std::endl;
        exit(1);
    }
    
    std::cout << numbers.top() << std::endl;
}