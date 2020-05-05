
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "carddeck.hpp"

Card::Card(std::string value, std::string suit)
{
    this->value = value;
    this->suit = suit;
}

CardDeck::CardDeck()
{
    this->createNewDeck();
}

CardDeck::~CardDeck()
{
    delete mMainDeck;
}

void CardDeck::createNewDeck()
{
    this->mMainDeck = new std::vector<Card*>();
    this->mDiscardPile = new std::vector<Card*>(); // empty

    this->mMainDeck->push_back(new Card("2", "H"));
    this->mMainDeck->push_back(new Card("3", "H"));
    this->mMainDeck->push_back(new Card("4", "H"));
    this->mMainDeck->push_back(new Card("5", "H"));
    this->mMainDeck->push_back(new Card("6", "H"));
    this->mMainDeck->push_back(new Card("7", "H"));
    this->mMainDeck->push_back(new Card("8", "H"));
    this->mMainDeck->push_back(new Card("9", "H"));
    this->mMainDeck->push_back(new Card("10","H"));
    this->mMainDeck->push_back(new Card("Jack", "H"));
    this->mMainDeck->push_back(new Card("Queen","H"));
    this->mMainDeck->push_back(new Card("King", "H"));
    this->mMainDeck->push_back(new Card("Ace",  "H"));

    this->mMainDeck->push_back(new Card("2", "D"));
    this->mMainDeck->push_back(new Card("3", "D"));
    this->mMainDeck->push_back(new Card("4", "D"));
    this->mMainDeck->push_back(new Card("5", "D"));
    this->mMainDeck->push_back(new Card("6", "D"));
    this->mMainDeck->push_back(new Card("7", "D"));
    this->mMainDeck->push_back(new Card("8", "D"));
    this->mMainDeck->push_back(new Card("9", "D"));
    this->mMainDeck->push_back(new Card("10","D"));
    this->mMainDeck->push_back(new Card("Jack", "D"));
    this->mMainDeck->push_back(new Card("Queen","D"));
    this->mMainDeck->push_back(new Card("King", "D"));
    this->mMainDeck->push_back(new Card("Ace",  "D"));

    this->mMainDeck->push_back(new Card("2", "S"));
    this->mMainDeck->push_back(new Card("3", "S"));
    this->mMainDeck->push_back(new Card("4", "S"));
    this->mMainDeck->push_back(new Card("5", "S"));
    this->mMainDeck->push_back(new Card("6", "S"));
    this->mMainDeck->push_back(new Card("7", "S"));
    this->mMainDeck->push_back(new Card("8", "S"));
    this->mMainDeck->push_back(new Card("9", "S"));
    this->mMainDeck->push_back(new Card("10","S"));
    this->mMainDeck->push_back(new Card("Jack", "S"));
    this->mMainDeck->push_back(new Card("Queen","S"));
    this->mMainDeck->push_back(new Card("King", "S"));
    this->mMainDeck->push_back(new Card("Ace",  "S"));

    this->mMainDeck->push_back(new Card("2", "C"));
    this->mMainDeck->push_back(new Card("3", "C"));
    this->mMainDeck->push_back(new Card("4", "C"));
    this->mMainDeck->push_back(new Card("5", "C"));
    this->mMainDeck->push_back(new Card("6", "C"));
    this->mMainDeck->push_back(new Card("7", "C"));
    this->mMainDeck->push_back(new Card("8", "C"));
    this->mMainDeck->push_back(new Card("9", "C"));
    this->mMainDeck->push_back(new Card("10","C"));
    this->mMainDeck->push_back(new Card("Jack", "C"));
    this->mMainDeck->push_back(new Card("Queen","C"));
    this->mMainDeck->push_back(new Card("King", "C"));
    this->mMainDeck->push_back(new Card("Ace",  "C"));

}

void CardDeck::shuffleDeck()
{
    std::shuffle(this->mMainDeck->begin(), this->mMainDeck->end(), std::random_device());
}

Card * CardDeck::getNextCard()
{
    Card * c = this->mMainDeck->back();
    this->mMainDeck->pop_back();
    return c;
    ;
}

void CardDeck::addToDiscardPile(Card * card)
{
    this->mDiscardPile->push_back(card);
}

int CardDeck::getNumRemainingCards()
{
    return this->mMainDeck->size();
}