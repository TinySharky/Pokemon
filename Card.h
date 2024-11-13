#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card {

protected:
    string cardName;

public:
    virtual ~Card() = default;

    Card(const string&);

    string getCardName() const;

    virtual void displayInfo(ostream&) const = 0;
};

#endif //CARD_H
