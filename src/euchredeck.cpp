#include "euchredeck.hpp"
#include <map>
#include <iostream>

void EuchreDeck::createNewDeck() 
{
    this->mMainDeck = new std::vector<Card*>();
    this->mDiscardPile = new std::stack<Card*>(); // empty

    this->mMainDeck->push_back(new Card("9",    "Hearts"));
    this->mMainDeck->push_back(new Card("10",   "Hearts"));
    this->mMainDeck->push_back(new Card("Jack", "Hearts"));
    this->mMainDeck->push_back(new Card("Queen","Hearts"));
    this->mMainDeck->push_back(new Card("King", "Hearts"));
    this->mMainDeck->push_back(new Card("Ace",  "Hearts"));

    this->mMainDeck->push_back(new Card("9",    "Diamonds"));
    this->mMainDeck->push_back(new Card("10",   "Diamonds"));
    this->mMainDeck->push_back(new Card("Jack", "Diamonds"));
    this->mMainDeck->push_back(new Card("Queen","Diamonds"));
    this->mMainDeck->push_back(new Card("King", "Diamonds"));
    this->mMainDeck->push_back(new Card("Ace",  "Diamonds"));

    this->mMainDeck->push_back(new Card("9",    "Spades"));
    this->mMainDeck->push_back(new Card("10",   "Spades"));
    this->mMainDeck->push_back(new Card("Jack", "Spades"));
    this->mMainDeck->push_back(new Card("Queen","Spades"));
    this->mMainDeck->push_back(new Card("King", "Spades"));
    this->mMainDeck->push_back(new Card("Ace",  "Spades"));

    this->mMainDeck->push_back(new Card("9",    "Clubs"));
    this->mMainDeck->push_back(new Card("10",   "Clubs"));
    this->mMainDeck->push_back(new Card("Jack", "Clubs"));
    this->mMainDeck->push_back(new Card("Queen","Clubs"));
    this->mMainDeck->push_back(new Card("King", "Clubs"));
    this->mMainDeck->push_back(new Card("Ace",  "Clubs"));

}

void EuchreDeck::rankCards(std::string trumpSuite)
{
    std::string trumpSuiteColor = this->checkColor(trumpSuite);

    std::cout << trumpSuite << std::endl;

    std::map<std::string, int> rankMap = std::map<std::string, int>();
    rankMap.insert(std::pair<std::string, int>("9",     1));
    rankMap.insert(std::pair<std::string, int>("10",    2));
    rankMap.insert(std::pair<std::string, int>("Jack",  3));
    rankMap.insert(std::pair<std::string, int>("Queen", 4));
    rankMap.insert(std::pair<std::string, int>("King",  5));
    rankMap.insert(std::pair<std::string, int>("Ace",   6));

    for (int i = 0; i < this->mMainDeck->size(); i++)
    {   
        if (this->mMainDeck->at(i)->value == "Jack") 
        {
            
            if (this->mMainDeck->at(i)->suit == trumpSuite)             { this->mMainDeck->at(i)->pointValue = 13; }
            else if (this->mMainDeck->at(i)->color == trumpSuiteColor)  { this->mMainDeck->at(i)->pointValue = 12; }
        }
        else if (this->mMainDeck->at(i)->suit == trumpSuite)
        {
            this->mMainDeck->at(i)->pointValue = rankMap[this->mMainDeck->at(i)->value] + 6;
        }
        else
        {
            this->mMainDeck->at(i)->pointValue = rankMap[this->mMainDeck->at(i)->value];
        }
    }
}

std::string EuchreDeck::checkColor(std::string suit)
{
    if (suit == "Hearts" || suit == "Diamonds") { return "Red"; }
    else { return "Black"; }
}