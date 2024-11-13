#include "TrainerCard.h"

#include <ostream>

TrainerCard::TrainerCard(const string& trainerName, const string& _trainerEffect) :
Card(trainerName), trainerEffect(_trainerEffect) {}

void TrainerCard::displayInfo(ostream& os) const {
    os << "Trainer Name: " << cardName << ", Effect: " << trainerEffect << endl;
}

