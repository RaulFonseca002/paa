
template <typename T>
Search<T>::Search(string logFileName) {
    logFile = ofstream(logFileName);
}

template <typename T>
Search<T>::~Search() {
    logFile.close();
}


template <typename T>
bool Search<T>::binarySearch(vector<T> vec, T element) {

    return false;
}

template <typename T>
bool Search<T>::linearSearch(vector<T> vec, T element) {

    chrono::steady_clock::time_point begin, end;
    begin = chrono::steady_clock::now();

    int index = 0;
    vec.push_back(element);

    while(element != vec[index]){
        index++;
    }

    end = chrono::steady_clock::now();

    time = chrono::duration_cast<chrono::microseconds>(end - begin).count();
    
    return (index != (vec.size() -1));
}

template <typename T>
void Search<T>::logLinear(vector<T> vec, T element) {

    int index = 0;

    logFile << "============================================================" << endl;
    logFile << "allocated and declared a variable of size: " << sizeof(index) << endl;

    vec.push_back(element);
    logFile << "pushed in a vector a variable of size: " << sizeof(element) << endl;

    while(element != vec[index]){
        index++;

    }

    logFile << "number of comparations: " << index << endl;
    logFile << "number of additions to a int: " << index << endl;
    logFile << "time: " << time << endl;


}


template <typename T>
bool Search<T>::randomSearch(vector<T> vec, T element) {

    return false;
}
