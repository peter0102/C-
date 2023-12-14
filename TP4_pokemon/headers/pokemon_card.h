#include "card.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PokemonCard : public Card {
    protected :
        string pokemonName ;
        string pokemonType;
        string familyName;
        int evolutionLevel;
        int maxHP;
        int hp;
        vector<tuple<int, int, string, int>> attacks;
    public:
        PokemonCard(string cardName, string pokemonType, string familyName, int evolutionLevel, int hp, 
        int attack1Cost, string attack1Name, int attack1Damage, int attack2Cost, string attack2Name, int attack2Damage):Card(cardName){};
        vector<tuple<int, int, string, int>> attacks;
        void displayInfo() const;
};