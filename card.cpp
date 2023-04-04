#include "card.hpp"
#include <iostream>
#include <string>



Card::Card(std::string type, int num)
{
    this->type = type;
    this->numCard = num;
}

int Card::compare(Card other)
{
    if((this->getNumCard() - other.getNumCard()) == 0){
        return 0;
    }else if ((this->getNumCard() - other.getNumCard()) > 0){
        return 1;
    }else {
        return -1;
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

std::string Card::toString()\
{
    std::cout << "(" << this->getNumCard() << "," << this->getType() << ")" << std::endl;
}
