#include <algorithm>
#include "card.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
#include <stack>
using namespace std;


namespace ariel{}



class Game { 
public:

    Player &player1;
    Player &player2;
    vector<Card> cardsOnTable;
    vector<Card> cards;
    stack<string> turnStatus;
    unsigned int numTurn;
    unsigned int numDraws;
    unsigned int p1_wins;
    unsigned int p2_wins;
    
    
    Game(Player &pl1, Player &pl2);
    void playTurn();
    void playAll();
    void printWiner();
    void printLastTurn();
    void printLog();

    //todo
    void printStats();

 private:
  void divideCards(std::vector<Card> &cards);
  void initStackCards();
  void shuffle();
  string getWinner(int num1, string name1, string type1, int num2, string name2, string type2);
  string evenMode( int num , string name1, string type1, string name2 , string type2);


};

