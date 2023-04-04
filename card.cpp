#include "card.hpp"
#include <iostream>
#include <string>
#include <sstream>

Card::Card(){}

Card::Card(std::string type, int num)
{
    this->type = type;
    this->numCard = num;
    specials[0] = "Ace";
    specials[1] = "Prince";
    specials[2] = "Queen";
    specials[3] = "King";
}

int Card::compare(Card &other)
{
    if((this->getNumCard() - other.getNumCard()) == 0){
        return EVEN_CARDS;
    }else if ((this->getNumCard() - other.getNumCard()) > 0){
        return C1_IS_BIGGER_CARD;
    }else {
        return C1_IS_SMALLER_CARD;
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


std::string Card::toString() {
    std::ostringstream ss;
    if(numCard == 1) ss << "(" << specials[0] << "," << type << ")";
    else if(numCard == 11) ss << "(" << specials[1] << "," << type << ")";
    else if(numCard == 12) ss << "(" << specials[2] << "," << type << ")";
    else if(numCard == 13) ss << "(" << specials[3] << "," << type << ")";
    else ss << "(" << numCard << "," << type << ")";
    return ss.str();
}
