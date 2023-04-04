#include <string>
#include <iostream>
#include "player.hpp"
using namespace std;

Player::Player() {}

Player::Player(string name)
{
    this->name = name;
}

string Player::getName()
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

Card Player::popCards()
{
    this->stack.erase(this->stack.begin()); // pop the 1st element
}

void Player::pullCards(vector<Card> cardsOnTable)
{
    for (unsigned int i = 0; i < cardsOnTable.size(); i++)
    {
        this->cardsTakenStack.push_back(cardsOnTable[i]);
    }
}