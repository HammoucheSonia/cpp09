#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <ctime>
#include <list>
#include <time.h>
#include <cstdio>
#define INT_MAX 2147483647

int is_number(int argc, char **argv);
int minIndex(std :: queue<int> &q, int sortedIndex);
void insertMinToRear(std :: queue<int> &q, int min_index);
void sortQueue(std :: queue<int> &q);
int parsing(int argc, char **argv);
void sort_list(int argc, char **argv);
void sort_queue(int argc, char **argv);

#endif
