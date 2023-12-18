#include "card.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PokemonCard : public Card {
    protected :
    string pokemonType;
        string familyName;
        int evolutionLevel;

public:
        PokemonCard(string pokemonName, string type, string family, int evolutionLevel, int maxHP,
                    int attack1_cost, string attack1_name, int attack1_damage, int attack2_cost, string attack2_name, int attack2_damage);
        void displayInfo() const;

    void incrementEnergy();

    vector<tuple<int, int, string, int>> attacks;
    string pokemonName ;

    string getAttackName(int attackIndex);
    int getAttackDamage(int attackIndex);

    int hp;
    int maxHP;
    int reserve;
};