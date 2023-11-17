#include "search.h"
#include <vector>
#include <iostream>

using namespace std;

class LinearSearch : public SearchingAlgorithm {
    public:
        int search(vector<int> arr, int target);
};