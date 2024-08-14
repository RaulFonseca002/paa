#include "Search.hpp"

int main() {

    Search<int> s("test.txt");
    vector<int> vec = {1,2,3,4,5,6,7};

    s.linearSearch(vec, 9);
    s.logLinear(vec, 9);


    return 0;
}
