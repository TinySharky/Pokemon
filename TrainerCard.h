#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include "Card.h"

class TrainerCard : public Card{
private:
    string trainerEffect;

public:
    TrainerCard(const string&, const string&);

    void displayInfo(ostream &) const override;
};



#endif //TRAINERCARD_H
