#include "BitcoinExchange.hpp"
#include <stdlib.h>
#include <cstring>
#include <errno.h>
#define INT_MAX 2147483647

btc :: btc(std::vector<std::string> tokens, std::string input)
{
    this->tokens = tokens;
    this->input = input;
}

btc :: ~btc()
{

}

btc :: btc(const btc &src)
{
    *this = src;
}

btc & btc :: operator=(const btc &src)
{
    if (this != &src)
    {
        this->input = src.input;
        this->tokens = src.tokens; 
    }
    return *this;
}

static int charinstr(const char *str, char c)
{
    int  i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}



int btc :: egalite(std :: string token, std :: string input)
{
    std::vector<std::string> tokens = split(token, '-');
    std::vector<std::string> inputs = split(input, '-');
    int i = 0;
    if (tokens.size() == 3)
    {
        if (tokens[0]== inputs[0])
            i++;
        if (tokens[1]== inputs[1])
            i++;
        if (i == 2 && !(tokens[2] == inputs[2]) \
            && atoi(tokens[2].c_str())>atoi(inputs[2].c_str()))
            return (-1);
        if (tokens[2]== inputs[2])
            i++;
        if (i == 3)
            return (1);
    }
    return (0);

}


void btc :: first_function()
{
    int i = 0;
    int j = this->tokens.size() - 1;
    std :: ifstream monFlux(this->input.c_str());
    if(monFlux)
    {
        std :: string ligne;
        getline(monFlux,ligne);
        while(getline(monFlux,ligne))
        {
            std::vector<std::string> inputs = split(ligne, '-');
            if (atoi(inputs[0].c_str()) < 2009 )
                std :: cout << "fausse date" << std :: endl;
            else if (atoi(inputs[1].c_str()) > 12 )
                std :: cout  << "fausse date" << std :: endl;
            else if (atoi(inputs[2].c_str()) > 31)
                std ::cout << "fausse date" << std :: endl;
            else if (!charinstr(ligne.c_str(),'|'))
                std :: cout << "Error: bad input => "<< ligne << std :: endl;
            else if (ligne[13] == '-')
                std :: cout << "Error: not a positive number." << std :: endl;
            else if (atoll(&ligne[12]) > INT_MAX)
                std :: cout << "Error: too large a number." << std :: endl;
            else
            {
                while (i < j)
                {
                    if (this->tokens[i].c_str() != NULL)
                    {
                        if (egalite(this->tokens[i], ligne.substr(0, 10)) == 1)
                        {
                            std :: cout << ligne.substr(0, 10) <<  " => " << atof(&ligne[12]) << \
                            " = " << atof(tokens[i+1].c_str()) * atof(&ligne[12]) << std :: endl;
                            i = 0;
                                break;
                        }
                        else if (egalite(this->tokens[i], ligne.substr(0, 10)) == -1)
                        {
                            std :: cout << ligne.substr(0, 10) <<  " => " <<  atof(&ligne[12]) << \
                            " = " << atof(tokens[i-1].c_str()) * atof(&ligne[12]) << std :: endl;
                            i = 0;
                                break;
                        }
                    }
                    i++;
                }
            }
        }
        monFlux.close();
    }
    else 
    {
        std :: cout << "Error: could not open file." << std :: endl;
        exit(1);
    }
} 

std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
        tokens.push_back(token);
   return tokens;
}
