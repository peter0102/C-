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
    this->attacks.push_back(make_tuple(attack1_cost, attack1_cost, attack1_name, attack1_damage));
    this->attacks.push_back(make_tuple(attack2_cost, attack2_cost, attack2_name, attack2_damage));
}

void PokemonCard::displayInfo() const {
    cout << "Name : " << this->pokemonName << ", Type : " << this->pokemonType << ", Family : " << this->familyName << ", Evolution Level : " << this->evolutionLevel << ", HP : " << this->maxHP << endl;
}
