#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std :: cout << "Error" << std :: endl;
        return (0);
    }
    else if (parsing(argv[1]) == 0)
    {
        std :: cout << "Error" << std :: endl;
        return (0);
    }
    
    if (deux_operateurs(argv[1]))
    {
        std :: string str1 = argv[1];
        std :: string str2 = argv[1];
        str1 = str1.substr(0,ft_strlen(argv[1])-8);
        str2 = str2.substr(ft_strlen(argv[1])-7\
        ,6);
        std :: cout << le_calcul(polonaise(str1.c_str()),\
        polonaise(str2.c_str()),argv[1][ft_strlen(argv[1])-1]) \
        << std :: endl;
    }
    else
	    std :: cout << polonaise(argv[1]) << std :: endl;
    return 0;
}