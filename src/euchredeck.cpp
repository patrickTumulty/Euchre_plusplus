#include "euchredeck.hpp"
#include <map>
#include <iostream>

void EuchreDeck::createNewDeck() 
{
    mMainDeck = new std::vector<Card*>();
    mDiscardPile = new std::stack<Card*>(); // empty

    mMainDeck->push_back(new Card("9",    "Hearts")); // <3
    mMainDeck->push_back(new Card("10",   "Hearts"));
    mMainDeck->push_back(new Card("Jack", "Hearts"));
    mMainDeck->push_back(new Card("Queen","Hearts"));
    mMainDeck->push_back(new Card("King", "Hearts"));
    mMainDeck->push_back(new Card("Ace",  "Hearts"));

    mMainDeck->push_back(new Card("9",    "Diamonds")); // ◊
    mMainDeck->push_back(new Card("10",   "Diamonds"));
    mMainDeck->push_back(new Card("Jack", "Diamonds"));
    mMainDeck->push_back(new Card("Queen","Diamonds"));
    mMainDeck->push_back(new Card("King", "Diamonds"));
    mMainDeck->push_back(new Card("Ace",  "Diamonds"));

    mMainDeck->push_back(new Card("9",    "Spades")); 
    mMainDeck->push_back(new Card("10",   "Spades"));
    mMainDeck->push_back(new Card("Jack", "Spades"));
    mMainDeck->push_back(new Card("Queen","Spades"));
    mMainDeck->push_back(new Card("King", "Spades"));
    mMainDeck->push_back(new Card("Ace",  "Spades"));

    mMainDeck->push_back(new Card("9",    "Clubs"));
    mMainDeck->push_back(new Card("10",   "Clubs"));
    mMainDeck->push_back(new Card("Jack", "Clubs"));
    mMainDeck->push_back(new Card("Queen","Clubs"));
    mMainDeck->push_back(new Card("King", "Clubs"));
    mMainDeck->push_back(new Card("Ace",  "Clubs"));

}


std::string EuchreDeck::checkColor(std::string suit)
{
    if (suit == "Hearts" || suit == "Diamonds") { return "Red"; }
    else { return "Black"; }
}