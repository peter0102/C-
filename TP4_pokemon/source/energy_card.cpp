#include "headers/energy_card.h"
#include <iostream>
#include <string>

using namespace std;

void EnergyCard::displayInfo() const{
    cout << "EnergyCard: " << this->cardName << endl;
    cout << "EnergyType: " << this->energyType << endl;
}

EnergyCard::EnergyCard(string energyType):Card("Energy"){
    this->energyType = energyType;
}