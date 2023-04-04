
#pragma once 
#include "card.hpp"
#include <string>
#include <iostream>
#include <queue>
//using namespace std;

class Player {
public:
    std::string name;
    std::queue<Card> cards;

    Player() {}

    Player(std::string name) {
        this->name = name;
    }

    int stacksize() {
        //TODO
        return 0;
    }

    int cardesTaken() {
        //TODO
        return 0;
    }

    void pullCard() {

    }

    void takeCards() {

    }
};