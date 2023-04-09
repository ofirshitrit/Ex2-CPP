
#pragma once
#include <iostream>
#include <string>

constexpr int EVEN_CARDS = 0;
constexpr int C1_IS_BIGGER_CARD = 1;
constexpr int C1_IS_SMALLER_CARD = -1;

class Card
{
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