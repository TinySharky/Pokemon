#include "pokemonCard.h"
#include <iostream>

pokemonCard::pokemonCard(const string& pokemonName, const string& _pokemonType, const string& _familyName, int _evolutionLevel,
                         int _maxHP, int _hp, int _energyStorage, const vector<tuple<int, string, int>>& _attacks)
    : Card(pokemonName), pokemonType(_pokemonType), familyName(_familyName), evolutionLevel(_evolutionLevel),
      maxHP(_maxHP), hp(_hp), energyStorage(_energyStorage), attacks(_attacks) {}

void pokemonCard::displayInfo(ostream& os) const {
    os << "Pokemon: " << cardName << ", Type: " << pokemonType << ", Family: " << familyName
       << ", Evolution Level: " << evolutionLevel << ", Max HP: " << maxHP << ", HP: " << hp << ", Energy Storage: " << energyStorage << endl;

    os << "Attacks:" << endl;
    for (const auto& attack : attacks) {
        os << "- Cost: " << get<0>(attack) << ", Name: " << get<1>(attack) << ", Power: " << get<2>(attack) << endl;
    }
}

int pokemonCard::getAttackPower(int selectedAttack) const {
    if (selectedAttack < 0 || selectedAttack >= attacks.size()) {
        cout << "Invalid attack choice!" << endl;
        return 0;
    }

    return std::get<2>(attacks[selectedAttack]);
}

void pokemonCard::applyDamage(int damage) {
    hp -= damage;
    if (hp <= 0) {
        hp = 0;
        cout << "Pokemon " << cardName << " is knocked out!" << endl;
    } else {
        cout << "Pokemon " << cardName << " has " << hp << " HP remaining." << endl;
    }
}

void pokemonCard::heal() {
    hp = maxHP;
    cout << "Pokemon " << cardName << " healing!" << endl;
}





pokemonCard::~pokemonCard() {

}

