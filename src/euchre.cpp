
#include <iostream>
#include "euchre.hpp"

Euchre::Euchre()
{
    this->mDeck = new EuchreDeck();
    this->mPlayers = new std::map<std::string, Player*>();
    this->mDeck->createNewDeck();
    this->mDeck->shuffleDeck();

}

Euchre::~Euchre()
{
    delete this->mDeck;
}

void Euchre::printPlayerHands()
{
    for (std::map<std::string, Player*>::iterator it = this->mPlayers->begin(); it != this->mPlayers->end(); ++it)
        it->second->printHand();
}

void Euchre::printRankedHands()
{
    for (std::map<std::string, Player*>::iterator it = this->mPlayers->begin(); it != this->mPlayers->end(); ++it)
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
        for (std::map<std::string, Player*>::iterator it = this->mPlayers->begin(); it != this->mPlayers->end(); ++it)
        {
            for (int j = 0; j < numDealtCards; j++)
            {
                it->second->addCardToHand(this->mDeck->getNextCard());
            }
        }
    }
    this->mTrumpSuit = this->mDeck->revealTopCard()->suit;
    std::cout << "Trump Suit is " << this->mTrumpSuit << std::endl;
    for (std::map<std::string, Player*>::iterator it = this->mPlayers->begin(); it != this->mPlayers->end(); ++it)
    {
        it->second->setTrumpSuit(mTrumpSuit);
    }
}

std::string Euchre::getTrumpSuit()
{
    return this->mTrumpSuit;
}

void Euchre::createNewPlayer(std::string playerName)
{
    Player * newPlayer = new Player(playerName);
    this->mPlayers->insert(std::pair<std::string, Player*>(playerName, newPlayer));
}