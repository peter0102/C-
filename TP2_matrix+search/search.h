#ifndef SEARCH_H
#define SEARCH_H
#include <iostream>
#include <vector>

using namespace std;

class SearchingAlgorithm {
    public:
        int numberComparisons;

        static int totalSearch;
        static int totalComparisons;
        static double averageComparisons;

        SearchingAlgorithm();

        void displaySearchResults(ostream &os, int result, int target) const;

        virtual int search(vector<int> arr, int target) = 0;
};
#endif