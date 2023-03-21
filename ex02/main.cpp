#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#define INT_MAX 2147483647

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
    std :: queue<int> list;
    int i = 1;
    while (i < argc)
    {
        list.push(atoi(argv[i]));
        i++;
    }
    sortQueue(list);
    while (list.empty() == false)
    {
        std :: cout << list.front() << " ";
        list.pop();
    }
    std :: cout << " " << std :: endl;
    return (0);
}