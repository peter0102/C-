#include "search.h"
#include <vector>
#include <iostream>

using namespace std;

class BinarySearch : public SearchingAlgorithm {
    public:
        int search(vector<int> arr, int target);
};