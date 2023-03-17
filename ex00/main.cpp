#include <ostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h> 
#include "BitcoinExchange.hpp"



int main(int argc,char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file."<< std::endl;
		exit(1);
    }
    std::vector<std::string> tokens;
    std :: ifstream fichier("./data.csv", std :: ios :: in);
    std :: string ligne;
    getline(fichier, ligne);
    while(std::getline(fichier, ligne))
    {
        tokens.push_back(split(ligne, ',')[0]);
        tokens.push_back(split(ligne, ',')[1]);
    }
    fichier.close();
    btc Exchange(tokens, argv[1]);
    Exchange.first_function();
    return (0);
}