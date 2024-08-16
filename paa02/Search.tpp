#include "Search.hpp"

template <typename T>
Search<T>::Search() {
    srand(time(0));

}

template <typename T>
Search<T>::~Search() {
}

template <typename T>
bool Search<T>::binary(vector<T> vec, T element) {

    bool resp;
    sort(vec.begin(), vec.end());

    resp = binarySearch(&vec, &element);

    logBinarySearch(&vec, &element);

    return resp;
}

template <typename T>
bool Search<T>::binarySearch(vector<T> *vec, T *element) {

    int left = 0;
    int right = vec->size() -1;
    int middle;

    while(left <= right){

        middle = left + ((right - left)/2);

        if(vec->at(middle) == *element){
            return true;
        }

        if(vec->at(middle) < *element){
            left = ++middle;
        }else{
            right = --middle;
        }
    }

    return false;
}

template <typename T>
void Search<T>::logBinarySearch(vector<T> *vec, T *element) {

    int left = 0;
    int right = vec->size() -1;
    int middle;

    while(left <= right){

        middle = left + ((right - left)/2);

        if(vec->at(middle) == *element){
            return;
        }

        if(vec->at(middle) < *element){
            left = ++middle;
        }else{
            right = --middle;
        }
    }
    

}


template <typename T>
bool Search<T>::linear(vector<T> vec, T element) {

    bool resp;
    vec.push_back(element);

    resp = linearSearch(&vec, &element);
    return (resp >= 0);
}


template <typename T>
int Search<T>::linearSearch(vector<T>* vec, T* element) {

    int index = 0;

    while(*element != vec->at(index)){
        index++;
    }

    return (index != (vec->size() -1)) ? index : (index * -1);
}

template <typename T>
bool Search<T>::random(vector<T> vec, T element){

    bool resp;

    resp = randomSearch(&vec, &element);

    return resp;
}

template <typename T>
bool Search<T>::randomSearch(vector<T> *vec, T *element) {

    int i = rand() % vec->size();
    return (vec->at(i) == *element);
}

