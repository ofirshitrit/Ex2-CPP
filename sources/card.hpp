
#pragma once 
#include <iostream>
#include <string>
//using namespace std;

class Card {
    int numCard;
    std::string type;
public:
    Card(); 
    Card(std::string type, int num);
    int compare(Card other);
    int getNumCard();
    std::string getType();
    std::string toString();
    
};