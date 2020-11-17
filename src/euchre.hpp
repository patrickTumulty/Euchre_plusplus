
#ifndef EUCHRE_HPP
#define EUCHRE_HPP

#include <iostream>
#include <map>
#include "euchredeck.hpp"
#include "player.hpp"


class Euchre
{
public:
    Euchre();
    ~Euchre();


    void gameLoop();
    void createNewPlayer(std::string playerName);
    void printPlayerHands();
    void deal();
    void printRankedHands();
    std::string getTrumpSuit();

private:
    std::string mTrumpSuit;
    EuchreDeck * mDeck;   
    std::map<std::string, Player*> * mPlayers;

};

#endif