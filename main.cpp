#include "Card.h"
#include "pokemonCard.h"
#include "EnergyCard.h"
#include "TrainerCard.h"
#include "Player.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
    Player player1("Hadi");

    vector<tuple<int, string, int>> attacksPikachu = {
        make_tuple(2, "Thunderbolt", 20),
        make_tuple(1, "Quick Attack", 30)
    };

    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new TrainerCard("Ash", "heal all your action pokemon"));
    player1.addCardToBench(new pokemonCard("Pikachu", "Electric", "Pikachu", 2, 100, 100, 0, attacksPikachu));

    player1.activatePokemonCard(3);
    player1.attachEnergycard(0,0);
    player1.attachEnergycard(0,0);

    cout << endl;
    player1.displayBench();
    cout << endl;
    player1.displayAction();

    vector<tuple<int, string, int>> attacksBulbasaur = {
        make_tuple(2, "Leech Seed", 15),
        make_tuple(3, "Vine Whip", 25)
    };

    cout << endl;

    Player player2("Germain");

    player2.addCardToBench(new EnergyCard("Grass"));
    player2.addCardToBench(new TrainerCard("Brock", "heal all your action pokemon"));
    player2.addCardToBench(new pokemonCard("Bulbasaur", "Grass", "Bulbasaur", 1, 100, 100, 0, attacksBulbasaur));

    player2.activatePokemonCard(2);
    player2.attachEnergycard(0,0);

    cout << endl;
    player2.displayBench();
    cout << endl;
    player2.displayAction();

    player1.attack(0, 0, player2, 0);
    cout << endl;
    player2.displayAction();
    cout << endl;
    player2.displayBench();
    cout << endl;
    player2.useTrainer(0);
    cout << endl;
    player2.displayAction();

    return 0;
}