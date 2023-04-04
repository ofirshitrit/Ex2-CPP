#include "player.hpp"
#include "card.hpp"
#include "game.hpp"

Game::Game(Player &p1, Player &p2)
{

    this->p1 = p1;
    this->p2 = p2;
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
        Game::playTurn();
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