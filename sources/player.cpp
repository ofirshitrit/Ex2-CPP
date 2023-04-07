#include <string>
#include <iostream>
#include "player.hpp"
using namespace std;

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
    Card removedCard = this->stack[0];
    this->stack.erase(this->stack.begin()); // remove the 1st element
    return removedCard;
}

void Player::pullCards(vector<Card> cardsOnTable)
{
    for (unsigned int i = 0; i < cardsOnTable.size(); i++)
    {
        this->cardsTakenStack.push_back(cardsOnTable[i]);
    }
}