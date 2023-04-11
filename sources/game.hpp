#include <algorithm>
#include "card.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

namespace ariel
{
}

class Game
{

private:
  Player& player1;
  Player& player2;
  unsigned int numTurn;
  unsigned int numDraws;
  unsigned int p1_wins;
  unsigned int p2_wins;
  vector<Card> cardsOnTable;
  vector<Card> cards;
  stack<string> turnStatus;

public:
  Game(Player &pl1, Player &pl2);
  void playTurn();
  void playAll();
  void printWiner();
  void printLastTurn();
  void printLog();
  void printStats();
  vector<Card> &getCardsOnTable();
  vector<Card> &getCards();
  stack<string> &getTurnStatus();
  void divideCards(vector<Card> &cards);
  void initStackCards();
  void shuffle();
  string getWinner(int num1, string name1, string type1, int num2, string name2, string type2);
  string evenMode(int num, string name1, string type1, string name2, string type2);
  void printStack(vector<Card> &cards);
};
