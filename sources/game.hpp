#include <algorithm>
#include "card.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
#define TRUE 1
#define False 0
namespace ariel{}


class Game { 
public:

    Player p1;
    Player p2;
    std::vector<Card> cardsOnTable;
    std::vector<Card> cards;
    static int numTurn;
    
    Game(Player &p1, Player &p2);
    void playTurn();

    //todo
    
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();

 private:
  void divideCards(std::vector<Card> cards);
  void initStackCards();
  void shuffle();

};

