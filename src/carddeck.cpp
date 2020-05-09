
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "carddeck.hpp"

Card::Card(std::string value, std::string suit)
{
    this->value = value;
    this->suit = suit;
    this->pointValue = 0;
    this->setColor();
}

void Card::setColor()
{
    if (this->suit == "Hearts" || this->suit == "Diamonds")
    {
        this->color = "Red";
    }
    else if (this->suit == "Clubs" || this->suit == "Spades")
    {
        this->color = "Black";
    }
}

CardDeck::CardDeck()
{
    this->mMainDeck = new std::vector<Card*>();
    this->mDiscardPile = new std::stack<Card*>();
}

CardDeck::~CardDeck()
{
    delete mMainDeck;
    delete mDiscardPile;
}

void CardDeck::createNewDeck()
{
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

void CardDeck::resetDeck()
{
    this->mMainDeck->clear();
    this->createNewDeck();
}

void CardDeck::addJokers()
{
    this->mMainDeck->push_back(new Card("Joker", "J1"));
    this->mMainDeck->push_back(new Card("Joker", "J2"));
}

void CardDeck::removeJokers()
{
    int numJokers = 2;
    int index = 0;
    while(numJokers != 0)
    {
        if (this->mMainDeck->at(index)->value == "Joker")
        {
            this->mMainDeck->erase(this->mMainDeck->begin() + index);
            numJokers--;
        }
        else
        {
            index++;
        }
    }
}


void CardDeck::discardNextCard()
{
    this->mDiscardPile->push(this->getNextCard());
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
}

Card * CardDeck::revealTopCard()
{
    return this->mMainDeck->back();
}

void CardDeck::addToDiscardPile(Card * card)
{
    this->mDiscardPile->push(card);
}

int CardDeck::getNumRemainingCards()
{
    return this->mMainDeck->size();
}