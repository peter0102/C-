#include "jump_search.h"
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
/**
 * @param arr tableau d'entiers ordonné
 * @param target entier à rechercher
 * @return l'index de l'entier recherché dans le tableau, -1 si non trouvé
*/
int JumpSearch::search(vector<int> arr, int target) { //jump search est une amélioration de la recherche linéaire, en coupant le tableau en blocs de taille sqrt(n) et en sautant de bloc en bloc
    numberComparisons = 0;

    int n = arr.size();
    int step = sqrt(n); //étape 1 : initialisation, sqrt(n) étant la taille optimale d'un saut

    int prev = 0; //étape 1 : initialisation, prev étant l'index du dernier saut
    while (arr[min(step, n) - 1] < target) { //étape 2 : check si la solution est à droite
        numberComparisons++;

        prev = step; //étape 3 : update prev
        step += sqrt(n); //étape 3 : update step

        if (prev >= n) {
            return -1;
        }
    }

    while (arr[prev] < target) { 
        numberComparisons++;
        prev++; 
        if (prev == min(step, n)) {
            return -1;
        }
    }
    if (arr[prev] == target) { // linear search
        return prev;
    }

    return -1;
}