
#pragma once 
#include <iostream>
#include <string>
//using namespace std;

class Card {
    int number;
    std::string type;
public:
    Card() {
        // default constructor implementation
    }

    Card(std::string type, int num) {
        this->type = type;
        this->number = num;
    }

    
};