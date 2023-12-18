#include "card.h"
#include <iostream>
#include <string>

using namespace std;

class EnergyCard : public Card {
    protected :
        string cardName = "Energy";
        string energyType;
    public:
        EnergyCard(string energyType);
        void displayInfo() const;
};