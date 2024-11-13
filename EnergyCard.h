#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include "Card.h"
#include <string>


class EnergyCard : public Card{
private:
    string energyType;

public:
    EnergyCard(const string&);

    void displayInfo(ostream &) const override;
};



#endif //ENERGYCARD_H
