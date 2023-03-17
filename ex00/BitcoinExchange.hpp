#include <ostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h> 

class btc 
{
    private:
        std::vector<std::string> tokens;
        std::string input;
    public:
        btc(std::vector<std::string> tokens, std::string input);
        ~btc();
        btc(const btc &src);
        btc &operator=(const btc &src);
        void first_function();
        int egalite(std :: string token, std :: string input);
};

std::vector<std::string> split(const std::string& s, char delimiter);