#include "player.hpp"
#include "card.hpp"
#include "game.hpp"
#include <algorithm>
#include <random>
#include <string>
#include <sstream>
#define CARDS_AMOUNT 52
string Numbers[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

Game::Game(Player &p1, Player &p2) : p1(p1), p2(p2)
{
    if (&p1 == &p2)
        throw std::exception(); // if it is the same player
    initStackCards();
    divideCards(cards);
}

void Game::playTurn()
{
    if (numTurn > 26)
        throw std::exception();

    Card c1 = this->p1.popCards();
    Card c2 = this->p2.popCards();

    this->cardsOnTable.push_back(c1);
    this->cardsOnTable.push_back(c2);

    int res = c1.compare(c2);
    if (res == EVEN_CARDS)
    {
        if (p1.stacksize() == 0 || p2.stacksize() == 0)
        {
            divideCards(cardsOnTable);
        }
        string stats = evenMode(c1.getNumCard(), p1.getName(), c1.getType(), p2.getName(), c2.getType());
        turnStatus.push(stats);
        
        //Draw upside down cards
        Card c1 = this->p1.popCards();
        Card c2 = this->p2.popCards();
        this->cardsOnTable.push_back(c1);
        this->cardsOnTable.push_back(c2);
        numDraws++;

        playTurn();
    }
    else if (res == C1_IS_BIGGER_CARD)
    {
        p1.pullCards(cardsOnTable);
        string stats = getWinner(c1.getNumCard(), p1.getName(), c1.getType(), c2.getNumCard(), p2.getName(), c2.getType());
        turnStatus.push(stats);
    }
    else
    {
        p2.pullCards(cardsOnTable);
        string stats = getWinner(c2.getNumCard(), p2.getName(), c2.getType(), c1.getNumCard(), p1.getName(), c1.getType());
        turnStatus.push(stats);
    }
    numTurn++;
}

void Game::playAll()
{
    while (p1.stacksize() > 0 && p2.stacksize() > 0)
    {
        playTurn();
    }
}

void Game::printWiner()
{
    if (this->p1.cardesTaken() > this->p2.cardesTaken())
    {
        cout << this->p1.getName() << " is the winner!" << endl;
    }
    else if (this->p1.cardesTaken() < this->p2.cardesTaken())
    {
        cout << this->p2.getName() << " is the winner!" << endl;
    }
    else
    {
        cout << "no one wins!" << endl;
    }
}

void Game::printLastTurn()
{
    if (!turnStatus.empty())
    {
        cout << turnStatus.top();
        turnStatus.pop();
    }
}

void Game::printLog()
{
    while (!turnStatus.empty())
    {
        printLastTurn();
    }
}

void Game::printStats()
{
    int winRateP1 = round((float(p1.cardesTaken()) / CARDS_AMOUNT) * 100);
    int winRateP2 = round((float(p2.cardesTaken()) / CARDS_AMOUNT) * 100);
    cout << "WIn rate for " << p1.getName() << " is " << winRateP1 << "%" << endl;
    cout << "WIn rate for " << p2.getName() << " is " << winRateP2 << "%" << endl;
    cout << "The numer of Draw is: " << numDraws << endl;
}

void Game::divideCards(std::vector<Card> &cards)
{
    for (vector<Card>::size_type i = 0; i < cards.size() / 2; i++)
    {
        this->p1.stack.push_back(cards[i]);
    }
    for (vector<Card>::size_type i = cards.size() / 2; i < cards.size(); i++)
    {
        this->p2.stack.push_back(cards[i]);
    }
}

void Game::initStackCards()
{
    for (int i = 1; i <= 13; ++i)
    {
        Card c1("diamond", i);
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
    auto rng = std::default_random_engine{};
    std::shuffle(begin(cards), end(cards), rng);
}

string Game::getWinner(int num1, string name1, string type1, int num2, string name2, string type2)
{
    std::ostringstream ss;
    ss << name1 << " played " << Numbers[num1 - 1] << " of " << type1 << " " << name2 << " played " << Numbers[num2 - 1] << " of " << type2 << ". " << name1 << " wins." << endl;
    return ss.str();
}

string Game::evenMode(int num, string name1, string type1, string name2, string type2)
{
    std::ostringstream ss;
    ss << name1 << " played " << Numbers[num - 1] << " of " << type1 << " " << name2 << " played " << Numbers[num - 1] << " of " << type2 << ". Draw." << endl;
    return ss.str();
}