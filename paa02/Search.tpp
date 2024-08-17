#include "Search.hpp"
#define binary_log_id "binary"
#define random_log_id "random"
#define linear_log_id "linear"

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

    logger.init(binary_log_id);
    resp = binarySearch(&vec, &element);
    logger.end(binary_log_id);

    logBinarySearch(&vec, &element);

    logger.printLog(binary_log_id);

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

    logger.incrementAttribuition(binary_log_id, 3);
    logger.incrementInstance(binary_log_id, 3);


    while(left <= right){
    logger.incrementCompare(binary_log_id, 1);

        middle = left + ((right - left)/2);
        logger.incrementCompare(binary_log_id, 1);

        logger.incrementCompare(binary_log_id, 1);
        if(vec->at(middle) == *element){
            return;
        }

        logger.incrementCompare(binary_log_id, 1);
        if(vec->at(middle) < *element){
            left = ++middle;
            logger.incrementAttribuition(binary_log_id, 1);
            
        }else{
            right = --middle;
            logger.incrementAttribuition(binary_log_id, 1);

        }
    }
    

}


template <typename T>
bool Search<T>::linear(vector<T> vec, T element) {

    bool resp;
    int aux;

    vec.push_back(element);

    logger.init(linear_log_id);
    resp = linearSearch(&vec, &element);
    logger.init(linear_log_id);

    aux = (resp < 0) ? (resp * -1) : resp;

    logger.incrementAttribuition(linear_log_id, 1);
    logger.incrementInstance(linear_log_id, 1);
    logger.incrementCompare(linear_log_id, aux + 1); // +1 for the comparation in the ternary operator in the return

    logger.printLog(linear_log_id);

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

    logger.init(random_log_id);
    resp = randomSearch(&vec, &element);
    logger.end(random_log_id);

    logger.incrementInstance(random_log_id, 1);
    logger.incrementAttribuition(random_log_id, 1);
    logger.incrementCompare(random_log_id, 1);
    logger.printLog(random_log_id);

    return resp;
}

template <typename T>
bool Search<T>::randomSearch(vector<T> *vec, T *element) {

    int i = rand() % vec->size();
    return (vec->at(i) == *element);
}

