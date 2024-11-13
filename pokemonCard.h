#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "Card.h"

#include <tuple>
#include <vector>



class pokemonCard : public Card{

private:
    string pokemonType;
    string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    vector<tuple<int, string, int>> attacks;

public:

    pokemonCard(const string& _pokemonName, const string& _pokemonType, const string& _familyName, int _evolutionLevel,
                int _maxHP, int _hp, int _energyStorage, const vector<tuple<int, string, int>> &_attacks);

    void displayInfo(ostream&) const override;
    int energyStorage;
    int getAttackPower(int) const;
    void applyDamage(int);
    void heal();

    virtual ~pokemonCard();
};



#endif
