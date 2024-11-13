#include "Card.h"
#include <iostream>

Card::Card(const string& _cardName) : cardName(_cardName) {}

string Card::getCardName() const {
    return cardName;
}

