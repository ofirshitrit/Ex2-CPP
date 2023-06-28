
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include "doctest.h"
#include <iostream>
#include <string>
using namespace std;


TEST_CASE("Check that for each player has 26 cards at the begining")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    bool res;
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("Check if after one turn one player has more cards than the other")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    bool moreCards = false;
    game.playTurn();
    
    if (p1.cardesTaken() > 0 || p2.cardesTaken() > 0) moreCards = true;
    CHECK(moreCards);

}




TEST_CASE("Check that after 5 turns the stacksize of player is at most 21")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    for (int i = 0; i < 5; i++)
    {
        game.playTurn();
    }
    CHECK(p1.stacksize() <= 21);
    CHECK(p2.stacksize() <= 21);
    CHECK(26 - p2.stacksize() >= 21);
    CHECK(26 - p2.stacksize() >= 21);

}


TEST_CASE("Check that after one turn the stacksize and the cardtaken is change")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playTurn();
    
    CHECK(p1.stacksize() < 26);
    CHECK(p2.stacksize() < 26);
    bool cardsTakens = false;
    if (p1.cardesTaken() > 0 || p2.cardesTaken() > 0 ) cardsTakens = true;
    CHECK(cardsTakens);

}

TEST_CASE("Check the status game after 10 rounds")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    for(int i = 0; i < 10; i++){
        game.playTurn();
        if (p1.stacksize() == 0 && p2.stacksize() == 0)
        {
             break; //stop the game 
        }
    }
    CHECK(p1.stacksize() < 17);
    CHECK(p2.stacksize() < 17);
}


TEST_CASE("Check if in the end of the game the sum of the cards is 52")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playAll();
    bool sumIs52 = false;
    if (p1.stacksize() + p1.cardesTaken() + p2.stacksize() + p2.cardesTaken() == 52)  sumIs52 = true;
    CHECK(sumIs52);
}


TEST_CASE("Check the game over")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playAll();
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);

}

TEST_CASE("Check if error is thrown after 26 turns")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playAll();
    CHECK_THROWS(game.playTurn());
    
}

TEST_CASE("Check if error is thrown if p1 plays with hinself")
{
    Player p1("Alice");
    Game game(p1,p1);
    CHECK_THROWS(game.playTurn());
    
}


TEST_CASE("Check if there is error if try to print winner befor the game start")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_THROWS(game.printWiner());
    
}