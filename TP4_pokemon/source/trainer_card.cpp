#include "trainer_card.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

TrainerCard::TrainerCard(string trainerName, string trainerEffect):Card("Trainer"), trainerName(trainerName),
trainerEffect(trainerEffect) {}

void TrainerCard::displayInfo() const {
    cout << "Trainer name : " << this->trainerName << ", Trainer effect : " << this->trainerEffect << endl;
}