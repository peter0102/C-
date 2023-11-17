#ifndef JUMP_SEARCH_H
#define JUMP_SEARCH_H
#include "search.h"
#include <vector>
#include <iostream>

using namespace std;

class JumpSearch : public SearchingAlgorithm {
    public:
        int search(vector<int> arr, int target);
};
#endif