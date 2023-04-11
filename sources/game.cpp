#include "player.hpp"
#include "card.hpp"
#include "game.hpp"
#include <algorithm>
#include <random>
#include <string>
#include <sstream>
#define CARDS_AMOUNT 52
string Numbers[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

Game::Game(Player &p1, Player &p2) : player1(p1), player2(p2)
{
    initStackCards();
    divideCards(cards);
    numTurn = 0;
    numDraws = 0;
    p1_wins = 0;
    p2_wins = 0;
}

void Game::playTurn()
{

    if (numTurn > 26)
        throw exception();
    if (player1.stacksize() == 0 || player2.stacksize() == 0)
        throw exception();
    if (&player1 == &player2)
        throw exception();

    Card c1 = this->player1.popCards();
    Card c2 = this->player2.popCards();

    this->cardsOnTable.push_back(c1);
    this->cardsOnTable.push_back(c2);

    int res = c1.compare(c2);
    string stats;
    if (res == EVEN_CARDS)
    {
        if (player1.stacksize() == 0 || player2.stacksize() == 0)
        {
            divideCards(cardsOnTable);
        }
        stats = evenMode(c1.getNumCard(), player1.getName(), c1.getType(), player2.getName(), c2.getType());
        turnStatus.push(stats);

        // Draw upside down cards
        Card c1 = this->player1.popCards();
        Card c2 = this->player2.popCards();
        this->cardsOnTable.push_back(c1);
        this->cardsOnTable.push_back(c2);
        numDraws++;

        playTurn();
    }
    else if (res == C1_IS_BIGGER_CARD)
    {
        player1.pullCards(cardsOnTable);
        stats = getWinner(c1.getNumCard(), player1.getName(), c1.getType(), c2.getNumCard(), player2.getName(), c2.getType());
        turnStatus.push(stats);
        p1_wins++;
    }
    else
    {
        player2.pullCards(cardsOnTable);
        stats = getWinner(c2.getNumCard(), player2.getName(), c2.getType(), c1.getNumCard(), player1.getName(), c1.getType());
        turnStatus.push(stats);
        p2_wins++;
    }
    numTurn++;
    cardsOnTable.clear();
}

void Game::playAll()
{
    while (player1.stacksize() > 0 && player2.stacksize() > 0)
    {
        playTurn();
    }
}

void Game::printWiner()
{
    if (this->player1.cardesTaken() > this->player2.cardesTaken())
    {
        cout << this->player1.getName() << " is the winner!" << endl;
    }
    else if (this->player1.cardesTaken() < this->player2.cardesTaken())
    {
        cout << this->player2.getName() << " is the winner!" << endl;
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
    }
}

void Game::printLog()
{
    stack<string> tempStack = turnStatus;

    while (!tempStack.empty()) {
        cout << tempStack.top();
        tempStack.pop();
    }
}

void Game::printStats()
{
    cout << player1.getName() << " status: " << endl;
    int winRateP1 = (((float)this->p1_wins / numTurn) * 100);
    cout << "win rate: " << winRateP1 << "% " << endl;
    cout << "cards taken: " << player1.cardesTaken() << endl;

    cout << player2.getName() << " status: " << endl;
    int winRateP2 = (((float)this->p2_wins / numTurn) * 100);
    cout << "win rate: " << winRateP2 << "% " << endl;
    cout << "cards taken: " << player2.cardesTaken() << endl;

    cout << "The numer of Draw is: " << numDraws << endl;
}

void Game::divideCards(vector<Card> &cards)
{
    for (unsigned i = 0; i < cards.size() - 1; i += 2)
    {
        this->player1.getStack().push_back(cards[i]);
        this->player2.getStack().push_back(cards[i + 1]);
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
void Game::printStack(vector<Card> &cards)
{
    cout << "SIZE: " << cards.size() << endl;

    for (unsigned int i = 0; i < cards.size(); i++)
    {
        cout << cards[i].toString() << " ";
    }
    cout << endl;
}

vector<Card> &Game::getCardsOnTable()
{
    return this->cardsOnTable;
}

vector<Card> &Game::getCards()
{
    return this->cards;
}

stack<string> &Game::getTurnStatus()
{
    return this->turnStatus;
}