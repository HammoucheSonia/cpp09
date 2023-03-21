#include "PmergeMe.hpp"

void sort_queue(int argc, char **argv)
{
    clock_t begin = clock();
    std :: queue<int> list;
    int i = 1;
    while (i < argc)
    {
        list.push(atoi(argv[i]));
        i++;
    }
    sortQueue(list);
    /*while (list.empty() == false)
    {
        std :: cout << list.front() << " ";
        list.pop();
    }
    std :: cout << "\n";*/
    clock_t end = clock();
    std :: cout << "Time to process a range of " << \
    argc - 1 << " elements with std::queue: "<< end-begin << "us\n"; 

}

void sort_list(int argc, char **argv)
{
    int i = 1;
    std::list<int> file;
    clock_t begin = clock(); 
    while (i < argc)
    {
        file.push_back(atoi(argv[i]));
        i++;
    }
    std :: cout << "After : " ;
    file.sort();
    while (!file.empty())
    {
        std :: cout << file.front() << " ";
        file.pop_front();
    }
    std :: cout << "\n";
    clock_t end = clock();
    std :: cout << "Time to process a range of " << \
    argc - 1 << " elements with std::list: "<< end-begin << "us\n";
}

int is_number(int argc, char **argv)
{
    int  j = 1;
    int  i = 0;
    while (j < argc)
    {
        while (argv[j][i])
        {
            if (!isdigit(argv[j][i]))
                return (0);
            i++;
        }
        i = 0;
        j++;
    }
    return (1);
}

int minIndex(std :: queue<int> &q, int sortedIndex)
{
    int min_index = -1;
    int min_val = INT_MAX;
    int n = q.size();
    for (int i=0; i<n; i++)
    {
        int curr = q.front();
        q.pop();
        if (curr <= min_val && i <= sortedIndex)
        {
            min_index = i;
            min_val = curr;
        }
        q.push(curr);
    }
    return min_index;
}

void insertMinToRear(std :: queue<int> &q, int min_index)
{
    int min_val;
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        int curr = q.front();
        q.pop();
        if (i != min_index)
            q.push(curr);
        else
            min_val = curr;
    }
    q.push(min_val);
}

void sortQueue(std :: queue<int> &q)
{
    for (long unsigned int i = 1; i <= q.size(); i++)
    {
        int min_index = minIndex(q, q.size() - i);
        insertMinToRear(q, min_index);
    }
}

int parsing(int argc, char **argv)
{
    int  i = 1;
    if (!is_number(argc, argv))
        return (0);
    while (i < argc)
    {
        if (atoi(argv[i]) < 0)
            return (0);
        i++;
    }
    return (1);
}