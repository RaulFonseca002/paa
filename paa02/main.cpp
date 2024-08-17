#include "Search.hpp"
#include <math.h>

typedef struct {

    vector<int> vec;
    int element;
}TestVector;

TestVector getRandomVector(int size, bool missingElement){

    srand(time(0));
    TestVector resp;

    for(int c = 0; c < size; c++){
        resp.vec.push_back((rand() % size));
    }

    resp.element = missingElement ? size : resp.vec.at((rand() % size));

    return resp;
}

void printTestVector(TestVector* test){

    printf("vector: ");
    for(int c : test->vec){
        printf("%i ", c);
    }

    printf("\nelement: %i\n", test->element);
}

int main() {

    Search<int> search;
    TestVector test;
    string resp;

    for(int c = 0; c <= 7; c++){

        test = getRandomVector(pow(10, c), false);

        printf("\nvec size: %li", test.vec.size());
        
        resp = search.linear(test.vec, test.element) ? "found" : "not found";
        printf("\nlinear: %s", resp.c_str());

        resp = search.binary(test.vec, test.element) ? "found" : "not found";
        printf("\nbinary: %s", resp.c_str());

        resp = search.random(test.vec, test.element) ? "found" : "not found";
        printf("\nrandom: %s", resp.c_str());

        printf("\n");
        
    }

    return 0;
}
