
#pragma once
#include "card.hpp"
#include <string>
#include <iostream>
#include <vector>
using namespace std;


class Player
{
    string name;
public:
    vector<Card> stack;
    vector<Card> cardsTakenStack;
    
    Player(string name);
    string getName();
    int stacksize();
    int cardesTaken();
    Card popCards();
    void pullCards(vector<Card> cardsOnTable);
};