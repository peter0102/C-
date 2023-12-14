#include "card.h"
#include <iostream>
#include <string>

using namespace std;

class EnergyCard : public Card {
    protected :
        string cardName = "EnergyCard";
        string energyType;
    public:
        EnergyCard(string energyType);
        void displayInfo() const;
};