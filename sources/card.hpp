
#pragma once 
#include <iostream>
#include <string>

#define EVEN_CARDS 0
#define BIGGER_CARD 1
#define SMALLER_CARD -1

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