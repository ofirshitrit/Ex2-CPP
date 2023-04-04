#include <string>
#include <iostream>
#include "player.hpp"


Player::Player(std::string name) 
{
    this->name = name;
}

std::string Player::getName()
{
    return this->name;
}

int Player::stacksize()
{
    return this->stack.size();
}

int Player::cardesTaken()
{
    return this->cardsTakenStack.size();
}