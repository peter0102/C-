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
        PokemonCard(string pokemonName, string type, string family, int evolutionLevel, int maxHP,
                    int attack1_cost, string attack1_name, int attack1_damage, int attack2_cost, string attack2_name, int attack2_damage);
        void displayInfo() const;
};