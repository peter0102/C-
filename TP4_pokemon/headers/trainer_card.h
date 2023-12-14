#include "card.h"
#include <iostream>
#include <string>

using namespace std;

class TrainerCard : public Card {
    protected :
        string trainerName;
        string trainerEffect;
    public:
        TrainerCard(string trainerName, string trainerEffect);
        void displayInfo() const;
};