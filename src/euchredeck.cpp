#include "euchredeck.hpp"
#include <map>
#include <iostream>

void EuchreDeck::createNewDeck() 
{
    this->mMainDeck = new std::vector<Card*>();
    this->mDiscardPile = new std::stack<Card*>(); // empty

    this->mMainDeck->push_back(new Card("9",    "Hearts")); // <3
    this->mMainDeck->push_back(new Card("10",   "Hearts"));
    this->mMainDeck->push_back(new Card("Jack", "Hearts"));
    this->mMainDeck->push_back(new Card("Queen","Hearts"));
    this->mMainDeck->push_back(new Card("King", "Hearts"));
    this->mMainDeck->push_back(new Card("Ace",  "Hearts"));

    this->mMainDeck->push_back(new Card("9",    "Diamonds")); // ◊
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


std::string EuchreDeck::checkColor(std::string suit)
{
    if (suit == "Hearts" || suit == "Diamonds") { return "Red"; }
    else { return "Black"; }
}