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
    cout << playerName << "is attaching an Energy Card of type " << benchCards[benchIndex]->cardName << " to the Pokemon " << actionCards[benchIndex]->pokemonName << endl;
    benchCards.erase(benchCards.begin() + benchIndex);
    actionCards[benchIndex]->incrementEnergy();
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
    int attackCost = actionCards[actionIndex]->getAttackCost(energyIndex);
    if (actionCards[actionIndex]->reserve < attackCost) {
        cout << "Not enough energy to perform this attack." << endl;
        return;
    }
    string attackName = actionCards[actionIndex]->getAttackName(energyIndex);
    cout << playerName << "attacking " << opponent.playerName << "'s Pokemon" << opponent.actionCards[opponentActionIndex]->pokemonName << "with the Pokemon " << actionCards[actionIndex]->pokemonName;
    cout << "with its attack " <<  attackName << endl;
    int attackDamage = actionCards[actionIndex]->getAttackDamage(energyIndex);
    cout << "Reducing " << opponent.playerName << "'s Pokemon" << opponent.actionCards[opponentActionIndex]->pokemonName << "'s HP by " << attackDamage << endl;
    opponent.actionCards[opponentActionIndex]->hp -= attackDamage;
    if (opponent.actionCards[opponentActionIndex]->hp <= 0) {
        cout << opponent.playerName << "'s Pokemon" << opponent.actionCards[opponentActionIndex]->pokemonName << "has fainted." << endl;
        opponent.actionCards.erase(opponent.actionCards.begin() + opponentActionIndex);
    }
    else {
        cout << opponent.playerName << "'s Pokemon" << opponent.actionCards[opponentActionIndex]->pokemonName << "is still alive" << endl;
    }
    actionCards[actionIndex]->reserve -= attackCost;
}

void Player::useTrainer(int actionIndex) {
    cout << playerName << "is using the Trainer Card to heal all action cards." << endl;
    for (int i = 0; i < actionCards.size(); i++) {
        actionCards[i]->hp = actionCards[i]->maxHP;
    }
}