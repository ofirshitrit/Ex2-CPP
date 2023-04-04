#include "player.hpp"
#include "card.hpp"
#include "game.hpp"
#include <algorithm>
#include <random>

Game::Game(Player &p1, Player &p2)
{

    this->p1 = p1;
    this->p2 = p2;
    numTurn++;
    initStackCards();
    divideCards(cards);

}

void Game::playTurn()
{   

    Card c1 = this->p1.popCards();
    Card c2 = this->p2.popCards();

    this->cardsOnTable.push_back(c1);
    this->cardsOnTable.push_back(c2);

    int res = c1.compare(c2);
    if (res = EVEN_CARDS)
    {
        if(p1.stacksize() == 0 || p2.stacksize() == 0)
        {
            divideCards(cardsOnTable);
        }
        
        playTurn();
        
    }
    else if (res = BIGGER_CARD)
    {
        p1.pullCards(cardsOnTable);
    }
    else
    {
         p2.pullCards(cardsOnTable);
    }
}


void Game::divideCards(std::vector<Card> cards)
{
    for (int i = 0; i < cards.size()/2; i++)
    {
        this->p1.stack.push_back(cards[i]);
    }
    for (int i = cards.size()/2; i < cards.size(); i++)
    {
        this->p2.stack.push_back(cards[i]);
    }
   
}

void Game::initStackCards()
{
    for (int i = 1; i <= 13; ++i) {
            Card c1("diamond",i);
            Card c2("spade", i);
            Card c3("heart", i);
            Card c4("club", i);
            cards.push_back(c1);
            cards.push_back(c2);
            cards.push_back(c3);
            cards.push_back(c4);
        }
    shuffle();
}

void Game::shuffle()
{
    auto rng = std::default_random_engine {};
    std::shuffle(begin(cards),end(cards),rng);    
}