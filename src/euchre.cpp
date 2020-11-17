
#include <iostream>
#include "euchre.hpp"

Euchre::Euchre()
{
    mDeck = new EuchreDeck();
    mPlayers = new std::map<std::string, Player*>();
    mDeck->createNewDeck();
    mDeck->shuffleDeck();

}

Euchre::~Euchre()
{
    delete mDeck;
}

void Euchre::printPlayerHands()
{
    for (std::map<std::string, Player*>::iterator it = mPlayers->begin(); it != mPlayers->end(); ++it)
        it->second->printHand();
}

void Euchre::printRankedHands()
{
    for (std::map<std::string, Player*>::iterator it = mPlayers->begin(); it != mPlayers->end(); ++it)
    {
        std::cout << "[" << it->first << "]" << std::endl;
        std::cout << "Hand Score : " << it->second->rateHand() << std::endl;
    }
}

void Euchre::deal()
{
    int numDealtCards = 2;
    for (int i = 0; i < 2; i++)
    {
        if (i == 1) { numDealtCards = 3; }
        for (std::map<std::string, Player*>::iterator it = mPlayers->begin(); it != mPlayers->end(); ++it)
        {
            for (int j = 0; j < numDealtCards; j++)
            {
                it->second->addCardToHand(mDeck->getNextCard());
            }
        }
    }
    mTrumpSuit = mDeck->revealTopCard()->suit;
    std::cout << "Trump Suit is " << mTrumpSuit << std::endl;
    for (std::map<std::string, Player*>::iterator it = mPlayers->begin(); it != mPlayers->end(); ++it)
    {
        it->second->setTrumpSuit(mTrumpSuit);
    }
}

std::string Euchre::getTrumpSuit()
{
    return mTrumpSuit;
}

void Euchre::createNewPlayer(std::string playerName)
{
    Player * newPlayer = new Player(playerName);
    mPlayers->insert(std::pair<std::string, Player*>(playerName, newPlayer));
}

void Euchre::gameLoop()
{
    
}