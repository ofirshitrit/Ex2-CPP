
#pragma once
#include <iostream>
#include <string>

constexpr int EVEN_CARDS = 0;
constexpr int C1_IS_BIGGER_CARD = 1;
constexpr int C1_IS_SMALLER_CARD = -1;
using namespace std;
class Card
{

public:
    Card();
    Card(string type, int num);
    int compare(Card &other);
    int getNumCard();
    string getType();
    string toString();

private:
    int numCard;
    string type;    
};