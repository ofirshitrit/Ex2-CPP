#include "card.hpp"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string Numbers[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
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
    
    for(int i = 0; i <= 13; i++) {
        if(numCard == i + 1) {
            ss << "(" << Numbers[i] << "," << type << ")";
            return ss.str();
        }
    }
    
    ss << "(" << numCard << "," << type << ")";
    return ss.str();
}
