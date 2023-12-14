#include "binary_search.h"
#include <vector>
#include <iostream>

using namespace std;
/**
 * @param arr tableau d'entiers ordonné
 * @param target entier à rechercher
 * @return l'index de l'entier recherché dans le tableau, -1 si non trouvé
*/
int BinarySearch::search(vector<int> arr, int target) {
    // numberComparisons = 0;
    
    // int start = 0; //étape 1 : initialisation
    // int end = arr.size() - 1; //étape 1 : initialisation
    
    // while (start < end) { //loop, inférieur strict pour éviter une boucle infinie si start = end n'est pas la solution
    //     int mid = start + (end - start) / 2; //étape 2 : recalcule mid à chaque itération

    //     numberComparisons++;

    //     if (arr[mid] == target) { //étape 3 check le mid
    //         return mid;
    //     } else if (arr[mid] < target) { //étape 4 check si la solution est à droite
    //         start = mid + 1;
    //     } else {
    //         end = mid - 1; //étape 4 check si la solution est à gauche
    //     }
    // }

    // return -1;
    return search_recursive(arr, target, 0, arr.size() - 1);
}

int BinarySearch::search_recursive(vector<int> arr, int target, int start, int end) {
    numberComparisons++;

    if (start > end) {
        return -1;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return search_recursive(arr, target, mid + 1, end);
    } else {
        return search_recursive(arr, target, start, mid - 1);
    }
}
