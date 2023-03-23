#include "RPN.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Error: No inverted Polish mathematical expression provided." << \
        std::endl;
        return 1;
    }
    unique_fonction(argv);
}
