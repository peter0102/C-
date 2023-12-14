#include <iostream>
#include <string>

using namespace std;

class Player {
    protected:
        string playerName;
        vector<Card*> benchCards;
        vector<PokemonCard*> actionCards;
    public:
        Player(string playerName);
        void addCardToBench(Card* card);
        void attachEnergyCard(int, int);
        void displayBench();
        void displayAction();
        void activatePokemonCard(int);
        void attack(int, int, Player, int);
        void useTrainer(int);
};