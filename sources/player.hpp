
#pragma once
#include "card.hpp"
#include <string>
#include <iostream>
#include <vector>

class Player
{

    std::string name;

public:
    std::vector<Card> stack;
    std::vector<Card> cardsTakenStack;
    Player();
    Player(std::string name);

    std::string getName();
    int stacksize();
    int cardesTaken();
    Card popCards();

    // TODO
    void pullCards(Card &card);
};