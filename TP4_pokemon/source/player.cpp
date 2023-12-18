#include "headers/player.h"
#include "headers/card.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player(string playerName) {
    this->playerName = playerName;
}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int index) {
    cout << playerName << " is activating a pokemon card : " << actionCards[index]->getName() << endl;
    actionCards.erase(actionCards.begin() + index);
}

void Player::attachEnergyCard(int index1, int index2) {
    cout << playerName << " is attaching an energy card : " << benchCards[index1]->getName() << " of type " << benchCards[index1]->getType() << " to the pokemon: " << actionCards[index2]->getName() << endl;  
    actionCards[index2]->addEnergyCard(benchCards[index1]);
    benchCards.erase(benchCards.begin() + index1);
}