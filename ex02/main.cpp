#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std :: cout << "Error\n";
        return (0);
    }
    else if (!parsing(argc, argv))
    {
        std :: cout << "Error\n";
        return (0);
    }
    int i = 1;
    std :: cout << "Before : ";
    while (i < argc)
    {
        std :: cout << argv[i] << " ";
        i++;
    }
    std :: cout << "\n";
    sort_list(argc, argv);
    sort_queue(argc, argv);
    return (0);
}