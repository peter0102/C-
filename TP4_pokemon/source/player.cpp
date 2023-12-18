#include "headers/player.h"
#include "headers/card.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player(string playerName) {
    this->playerName = playerName;
}

void Player::addCardToBench(Card *card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int index) {
    cout << playerName << "is activating a Pokemon Card : " << benchCards[index]->cardName << endl;
    actionCards.push_back((PokemonCard*) benchCards[index]);
    benchCards.erase(benchCards.begin() + index);
}

void Player::attachEnergyCard(int benchIndex, int energyIndex) {
    cout << playerName << "is attaching an Energy Card of type " << benchCards[benchIndex]->cardName << " to the Pokemon " << actionCards[benchIndex]->cardName << endl;
    benchCards.erase(benchCards.begin() + benchIndex);
}

void Player::displayBench() {
    cout << "Bench cards for player " << playerName << " : " << endl;
for (int i = 0; i < benchCards.size(); i++) {
        cout << benchCards[i]->cardName << " card - ";
        benchCards[i]->displayInfo();
    }
}

void Player::displayAction() {
    cout << "Action cards for player " << playerName << " : " << endl;
    for (int i = 0; i < actionCards.size(); i++) {
        cout << actionCards[i]->cardName << " card - ";
        actionCards[i]->displayInfo();
    }
}

void Player::attack(int actionIndex, int energyIndex, Player &opponent, int opponentActionIndex) {

}

void Player::useTrainer(int actionIndex) {
    cout << playerName << "is using the Trainer Card : " << actionCards[actionIndex]->cardName << " to heal all action cards." << endl;
}