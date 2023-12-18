#include "headers/pokemon_card.h"
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

PokemonCard::PokemonCard(string pokemonName, string pokemonType, string family, int evolutionLevel, int maxHP,
                         int attack1_cost, string attack1_name, int attack1_damage, int attack2_cost,
                         string attack2_name, int attack2_damage):Card("Pokemon") {
    this->pokemonName = pokemonName;
    this->pokemonType = pokemonType;
    this->familyName = family;
    this->evolutionLevel = evolutionLevel;
    this->maxHP = maxHP;
    this->hp = maxHP;
    this->reserve = 0;
    this->attacks.push_back(make_tuple(attack1_cost, this->reserve, attack1_name, attack1_damage));
    this->attacks.push_back(make_tuple(attack2_cost, this->reserve, attack2_name, attack2_damage));
}

void PokemonCard::displayInfo() const {
    cout << "Name : " << this->pokemonName << ", Type : " << this->pokemonType << ", Family : " << this->familyName << ", Evolution Level : " << this->evolutionLevel << ", HP : " << this->hp;
    cout << ", Attacks : " << endl;
for (int i = 0; i < attacks.size(); i++) {
    cout << "Attack #" << i << endl;
    cout << "Attack Cost : " << get<0>(attacks[i]) << endl;
    cout << "Attack current energy storage : " << this->reserve << endl;
    cout << "Attack name : " << get<2>(attacks[i]) << endl;
    cout << "Attack damage : " << get<3>(attacks[i]) << endl;
    cout << endl;
    }
}

void PokemonCard::incrementEnergy() {
    this->reserve++;
}

string PokemonCard::getAttackName(int attackIndex) {
    return get<2>(attacks[attackIndex]);
}

int PokemonCard::getAttackDamage(int attackIndex) {
    return get<3>(attacks[attackIndex]);
}

int PokemonCard::getAttackCost(int attackIndex) {
    return get<0>(attacks[attackIndex]);
}


