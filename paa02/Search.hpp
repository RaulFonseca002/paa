#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <ctime>  
#include <algorithm>
#include "Log.hpp"

using namespace std;

template <typename T>
class Search {

private:

    Log logger;
    
    void logBinarySearch(vector<T> *vec, T *element);
    bool binarySearch(vector<T> *vec, T *element);
    int linearSearch(vector<T> *vec, T *element);
    bool randomSearch(vector<T> *vec, T *element);

public:
    Search();
    ~Search();

    bool linear(vector<T> vec, T element);
    bool binary(vector<T> vec, T element);
    bool random(vector<T> vec, T element);

};

#include "Search.tpp"

#endif 
