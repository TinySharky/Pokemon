#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "Card.h"
#include "pokemonCard.h"

using namespace std;

class Player {
private:
    string playerName;
    vector<Card*> benchCards;
    vector<pokemonCard*> actionCards;

public:
    Player(const string&);

    void addCardToBench(Card* card);
    void activatePokemonCard(int);
    void attachEnergycard(int, int);

    void displayBench() const;
    void displayAction() const;

    void attack(int, int, Player&, int);
    void useTrainer(int);

};



#endif //PLAYER_H
