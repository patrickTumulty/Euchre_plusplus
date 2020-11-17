
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "carddeck.hpp"



Card::Card(std::string value, std::string suit)
{
    value = value;
    suit = suit;
    pointValue = 0;
    setColor();
}

void Card::setColor()
{
    if (suit == "Hearts" || suit == "Diamonds")
    {
        color = "Red";
    }
    else if (suit == "Clubs" || suit == "Spades")
    {
        color = "Black";
    }
}

CardDeck::CardDeck()
{
    mMainDeck = new std::vector<Card*>();
    mDiscardPile = new std::stack<Card*>();
}

CardDeck::~CardDeck()
{
    delete mMainDeck;
    delete mDiscardPile;
}

void CardDeck::createNewDeck()
{
    mMainDeck->push_back(new Card("2",    "Hearts"));
    mMainDeck->push_back(new Card("3",    "Hearts"));
    mMainDeck->push_back(new Card("4",    "Hearts"));
    mMainDeck->push_back(new Card("5",    "Hearts"));
    mMainDeck->push_back(new Card("6",    "Hearts"));
    mMainDeck->push_back(new Card("7",    "Hearts"));
    mMainDeck->push_back(new Card("8",    "Hearts"));
    mMainDeck->push_back(new Card("9",    "Hearts"));
    mMainDeck->push_back(new Card("10",   "Hearts"));
    mMainDeck->push_back(new Card("Jack", "Hearts"));
    mMainDeck->push_back(new Card("Queen","Hearts"));
    mMainDeck->push_back(new Card("King", "Hearts"));
    mMainDeck->push_back(new Card("Ace",  "Hearts"));

    mMainDeck->push_back(new Card("2", "Diamonds"));
    mMainDeck->push_back(new Card("3", "Diamonds"));
    mMainDeck->push_back(new Card("4", "Diamonds"));
    mMainDeck->push_back(new Card("5", "Diamonds"));
    mMainDeck->push_back(new Card("6", "Diamonds"));
    mMainDeck->push_back(new Card("7", "D"));
    mMainDeck->push_back(new Card("8", "D"));
    mMainDeck->push_back(new Card("9", "D"));
    mMainDeck->push_back(new Card("10","D"));
    mMainDeck->push_back(new Card("Jack", "Diamonds"));
    mMainDeck->push_back(new Card("Queen","D"));
    mMainDeck->push_back(new Card("King", "D"));
    mMainDeck->push_back(new Card("Ace",  "D"));

    mMainDeck->push_back(new Card("2", "S"));
    mMainDeck->push_back(new Card("3", "S"));
    mMainDeck->push_back(new Card("4", "S"));
    mMainDeck->push_back(new Card("5", "S"));
    mMainDeck->push_back(new Card("6", "S"));
    mMainDeck->push_back(new Card("7", "S"));
    mMainDeck->push_back(new Card("8", "S"));
    mMainDeck->push_back(new Card("9", "S"));
    mMainDeck->push_back(new Card("10","S"));
    mMainDeck->push_back(new Card("Jack", "S"));
    mMainDeck->push_back(new Card("Queen","S"));
    mMainDeck->push_back(new Card("King", "S"));
    mMainDeck->push_back(new Card("Ace",  "S"));

    mMainDeck->push_back(new Card("2", "C"));
    mMainDeck->push_back(new Card("3", "C"));
    mMainDeck->push_back(new Card("4", "C"));
    mMainDeck->push_back(new Card("5", "C"));
    mMainDeck->push_back(new Card("6", "C"));
    mMainDeck->push_back(new Card("7", "C"));
    mMainDeck->push_back(new Card("8", "C"));
    mMainDeck->push_back(new Card("9", "C"));
    mMainDeck->push_back(new Card("10","C"));
    mMainDeck->push_back(new Card("Jack", "C"));
    mMainDeck->push_back(new Card("Queen","C"));
    mMainDeck->push_back(new Card("King", "C"));
    mMainDeck->push_back(new Card("Ace",  "C"));
}

void CardDeck::resetDeck()
{
    mMainDeck->clear();
    createNewDeck();
}

void CardDeck::addJokers()
{
    mMainDeck->push_back(new Card("Joker", "J1"));
    mMainDeck->push_back(new Card("Joker", "J2"));
}

void CardDeck::removeJokers()
{
    int numJokers = 2;
    int index = 0;
    while(numJokers != 0)
    {
        if (mMainDeck->at(index)->value == "Joker")
        {
            mMainDeck->erase(mMainDeck->begin() + index);
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
    mDiscardPile->push(getNextCard());
}


void CardDeck::shuffleDeck()
{
    std::shuffle(mMainDeck->begin(), mMainDeck->end(), std::random_device());
}

Card * CardDeck::getNextCard()
{
    Card * c = mMainDeck->back();
    mMainDeck->pop_back();
    return c;
}

Card * CardDeck::revealTopCard()
{
    return mMainDeck->back();
}

void CardDeck::addToDiscardPile(Card * card)
{
    mDiscardPile->push(card);
}

int CardDeck::getNumRemainingCards()
{
    return mMainDeck->size();
}