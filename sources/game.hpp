#include <algorithm>
#include "card.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
#define TRUE 1
#define False 0
using namespace std;
#include <stack>

namespace ariel{}



class Game { 
public:

    Player &p1;
    Player &p2;
    vector<Card> cardsOnTable;
    vector<Card> cards;
    stack<string> turnStatus;
    int numTurn;
    
    Game(Player &p1, Player &p2);
    void playTurn();
    void playAll();
    void printWiner();

    //todo
    
    void printLastTurn();
    void printLog();
    void printStats();

 private:
  void divideCards(std::vector<Card> &cards);
  void initStackCards();
  void shuffle();

};

