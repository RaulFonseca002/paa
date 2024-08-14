#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

template <typename T>
class Search {

private:
    ofstream logFile;
    long time;

    
public:
    Search(string logFileName);
    ~Search();
    bool binarySearch(vector<T> vec, T element);
    bool linearSearch(vector<T> vec, T element);
    void logLinear(vector<T> vec, T element);
    bool randomSearch(vector<T> vec, T element);
};

#include "Search.tpp"

#endif 
