#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void countFrequencyBruteForce(const vector<int> &vector) { // const &vector pour ne pas copier le vecteur inutilement
    for (int i=0; i<vector.size(); i++) {
        bool isDuplicate = false;
        for (int j=0; j<i; j++) {
            if (vector[i] == vector[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (isDuplicate) {
            continue;
        }
        int count = 1;
        for (int j=i+1; j<vector.size(); j++) {
            if (vector[i] == vector[j]) {
                count++;
            }
        }
        cout << vector[i] << " : " << count << " times" << endl;
    }
}

map<int, int> countFrequencyOptimal(const vector<int> &vector) {
    map<int, int> frequencyMap;
    for (int i=0; i<vector.size(); i++) {
        frequencyMap[vector[i]]++;
    }
    return frequencyMap;
}


int main ( ) {
    vector<int> numbers = {1 , 2 , 3 , 2 , 4 , 1 , 5 , 5 , 6 } ;
    // Test countFrequencyBruteForce
    cout << " Frequency ( Brute Force ) : " << endl ;
    countFrequencyBruteForce(numbers);
    // Test countFrequencyOptimal
    cout << "\nFrequency ( Optimal ) : " << endl ;
    map<int , int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for ( const auto& entry : frequencyMapOptimal ) {
    cout << entry.first << " : " << entry.second << " times " << endl ;
    }
    return 0 ;
}