#include "EnergyCard.h"

#include <ostream>

EnergyCard::EnergyCard(const string& _energyType ) :
Card("Energy"), energyType(_energyType) {}

void EnergyCard::displayInfo(ostream& os) const {
    os << "Energy Card : " << energyType << endl;
}
