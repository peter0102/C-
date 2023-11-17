#include "linear_search.h"
#include <vector>
#include <iostream>

using namespace std;

int LinearSearch::search(vector<int> arr, int target) {
    numberComparisons = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        numberComparisons++;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}