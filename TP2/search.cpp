#include "search.h"
#include <iostream>
#include <vector>


int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0;

SearchingAlgorithm::SearchingAlgorithm(): numberComparisons(0) {};

void SearchingAlgorithm::displaySearchResults(ostream& os, int result, int target) const {
    totalSearch++;
    if (result == -1) {
        os << "Searching for the element "" << target << "" resulted in no matches." << endl;
    } else {
        totalComparisons += numberComparisons;
        averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
        os << "Searching for the element " << target << " resulted in a match at index " << result << "." << endl;
    }
}