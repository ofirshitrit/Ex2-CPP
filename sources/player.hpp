
#pragma once 
#include "card.hpp"
#include <string>
#include <iostream>
#include <queue>
//using namespace std;

class Player {

    std::string name;
    std::vector<Card> stack;
    std::vector<Card> cardsTakenStack;
public:
    Player() {}
    Player(std::string name);

    std::string getName();
    int stacksize();
    int cardesTaken();
    void takeCards(Card card);
    void pullCards();

    
};