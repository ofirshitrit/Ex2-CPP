#include <algorithm>
#include "card.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace ariel{}


class Game { 
public:

    Player p1;
    Player p2;
    std::vector<Card> cardsOnTable;
    
    
    Game(Player &p1, Player &p2);


    //todo
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
};

