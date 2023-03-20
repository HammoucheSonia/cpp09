#include<iostream>
#include<string>
#include <deque>
#include <cstring>



int parsing(char *str)
{
    int i = 0;
    while(str[i])
    {
        if (!(isdigit(str[i]) || str[i] == '-' || str[i] =='+' 
        || str[i] == '/' || str[i] == '*' || str[i] == ' '))
            return(0);
        i++;
    }
    return (1);
}

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
    return 0;
}