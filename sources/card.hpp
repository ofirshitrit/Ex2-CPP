
#pragma once 
#include <iostream>
#include <string>

#define EVEN_CARDS 0
#define C1_IS_BIGGER_CARD 2
#define C1_IS_SMALLER_CARD -2

class Card {
    int numCard;
    std::string type;
public:
    Card(); 
    Card(std::string type, int num);
    int compare(Card &other);
    int getNumCard();
    std::string getType();
    std::string toString();
    
};