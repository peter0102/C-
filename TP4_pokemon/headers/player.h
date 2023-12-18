#ifndef POKEMON_CARD
#define POKEMON_CARD
#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "pokemon_card.h"

using namespace std;

class Player {
    protected:
        string playerName;
        vector<Card*> benchCards;
        vector<PokemonCard*> actionCards;
    public:
        Player(string playerName);
        void addCardToBench(Card* card);
        void activatePokemonCard(int index);
        void attachEnergyCard(int benchIndex, int energyIndex);
        void displayBench();
        void displayAction();
        void attack(int actionIndex, int energyIndex, Player& opponent, int opponentActionIndex);
        void useTrainer(int actionIndex);
};
#endif