
#pragma once
#include "card.hpp"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Player
{
    string name;
    vector<Card> stack;
    vector<Card> cardsTakenStack;

public:
    Player(string name);
    string getName();
    vector<Card> &getStack();
    vector<Card> &getCardsTakeStack();
    int stacksize();
    int cardesTaken();
    Card popCards();
    void pullCards(vector<Card> cardsOnTable);
};