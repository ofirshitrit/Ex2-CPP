#include "card.hpp"
#include <iostream>
#include <string>

Card::Card(){}

Card::Card(std::string type, int num)
{
    this->type = type;
    this->numCard = num;
}

int Card::compare(Card &other)
{
    if((this->getNumCard() - other.getNumCard()) == 0){
        return EVEN_CARDS;
    }else if ((this->getNumCard() - other.getNumCard()) > 0){
        return BIGGER_CARD;
    }else {
        return SMALLER_CARD;
    }
}

int Card::getNumCard()
{
    return this->numCard;
};

std::string Card::getType()
{
    return this->type;
};

