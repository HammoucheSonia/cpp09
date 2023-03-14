#include <ostream>
#include <iostream>
#include <fstream>



int main(int argc,char **argv)
{
    if (argc == 2)
    {
        std :: ifstream fichier(argv[1], std :: ios :: in);
        if (fichier)
        {
            std :: string ligne;
            getline(fichier, ligne);
            while(getline(fichier, ligne))
            {
                std :: cout << ligne << std :: endl;
            }
        }
        else
            std :: cout << "Error: could not open file." << std :: endl;
    }
    else 
        std :: cout << "Error: could not open file." << std :: endl;

    return (0);
}