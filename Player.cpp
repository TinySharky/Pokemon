#include "Player.h"

#include <iostream>
#include <ostream>

Player::Player(const string& _playerName) :
playerName(_playerName) {}

void Player::addCardToBench(Card* _card) {
    benchCards.push_back(_card);
}


void Player::activatePokemonCard(int index) {
    if (index < 0 || index >= benchCards.size()) {
        cout << "Invalid index" << endl;
    }

    pokemonCard* pokemon_card = dynamic_cast<pokemonCard*>(benchCards[index]);

    if (pokemon_card) {
        cout << playerName << " is activating a Pokemon card: " << pokemon_card->getCardName() << endl;
        actionCards.push_back(pokemon_card);
        benchCards.erase(benchCards.begin() + index);
    } else {
        cout << "The selected card is not a Pokemon card." << endl;
    }
}

void Player::attachEnergycard(int energyChoice, int activePokemon) {
    if (energyChoice < 0 || energyChoice >= benchCards.size()) {
        cout << "Invalid energy choice" << endl;
    }

    if (benchCards[energyChoice]) {}

    if (actionCards.empty()) {
        cout << "No active pokemon" << endl;
    }

    if (activePokemon > actionCards.size() - 1) {
        cout << "Invalid active pokemon choice" << endl;
    }

    actionCards[activePokemon]->energyStorage += 1;
    benchCards.erase(benchCards.begin() + energyChoice);
    cout << "Energy attached. Current energy storage : " << actionCards[activePokemon]->energyStorage << endl;
}


void Player::displayBench() const{
    cout << "Player " << playerName << "'s Bench cards:" << endl;

    if (benchCards.empty()) {
        cout << "No cards on the bench." << endl;
    } else {
        for (size_t i = 0; i < benchCards.size(); ++i) {
            cout << "Card " << i + 1 << ": ";
            benchCards[i]->displayInfo(cout);
        }
    }
}

void Player::displayAction() const {
    cout << "Player: " << playerName << "'s Action cards:" << endl;

    if (actionCards.empty()) {
        cout << "No action cards." << endl;
    } else {
        for (size_t i = 0; i < actionCards.size(); ++i) {
            cout << "Card " << i + 1 << ": ";
            actionCards[i]->displayInfo(cout);
        }
    }
}

void Player::attack(int selectedActionCard, int selectedAttack, Player& target, int actionCardTarget) {
    if (selectedActionCard < 0 || selectedActionCard >= benchCards.size()) {
        cout << "Invalid selected action card" << endl;
    }

    pokemonCard* attackerCard = actionCards[selectedActionCard];
    pokemonCard* targetCard = target.actionCards[actionCardTarget];

    int damage = attackerCard->getAttackPower(selectedAttack);
    targetCard->applyDamage(damage);

    cout << attackerCard->getCardName() << " deal " << damage << " damage to " << targetCard->getCardName() << endl;
}

void Player::useTrainer(int index) {
    actionCards[index]->heal();
    benchCards.erase(benchCards.begin() + index);
}




