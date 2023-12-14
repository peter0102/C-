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