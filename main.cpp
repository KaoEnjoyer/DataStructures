#include <iostream>
#include "BinarySearchTree.h"
#include "HashMap.h"
#include "Vec.h"
#include <vector>
#include <map>


using namespace std;

struct test{
    int k;

    void zmiana(const int n){
        this -> k = n;
    }
};


int main() {
    map<string, int>m;
    hash_map<string, int> t;
    t[1] = "jeden";
    t[2] = "dwa";
    t[3] = "trzy";

    std::cout << t[1];


}