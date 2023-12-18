#include "headers/pokemon_card.h"
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

PokemonCard::PokemonCard(string cardName, string pokemonType, string familyName, int evolutionLevel, int hp,
int attack1Cost, string attack1Name, int attack1Damage, int attack2Cost, string attack2Name, int attack2Damage):Card(cardName){
    this->pokemonType = pokemonType;
    this->familyName = familyName;
    this->evolutionLevel = evolutionLevel;
    this->hp = hp;
    this->attacks.push_back(make_tuple(attack1Cost, attack1Damage, attack1Name, attack1Damage));
    this->attacks.push_back(make_tuple(attack2Cost, attack2Damage, attack2Name, attack2Damage));
}

void PokemonCard::displayInfo() const{
    cout << "PokemonCard: " << this->cardName << endl;
    cout << "PokemonType: " << this->pokemonType << endl;
    cout << "FamilyName: " << this->familyName << endl;
    cout << "EvolutionLevel: " << this->evolutionLevel << endl;
    cout << "HP: " << this->hp << endl;
    cout << "Attacks: " << endl;
    for (int i = 0; i < this->attacks.size(); i++){
        cout << "Attack " << i << ": " << endl;
        cout << "Cost: " << get<0>(this->attacks[i]) << endl;
        cout << "Damage: " << get<1>(this->attacks[i]) << endl;
        cout << "Name: " << get<2>(this->attacks[i]) << endl;
        cout << "Description: " << get<3>(this->attacks[i]) << endl;
    }
}

void PokemonCard::getName() const{
    cout << this->cardName << endl;
}