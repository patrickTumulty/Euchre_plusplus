

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include "euchredeck.hpp"

class Player
{
public:
    Player(std::string playerName);
    ~Player();

   
    std::string getName();

    void printHand();
    void addCardToHand(Card* card);
    void clearHand();
    int evaluateCard(Card* card, std::string trumpSuit);
    std::string checkColor(std::string suit);
    void incrementScore(int increment);
    int getScore();
    float rateHand();
    void setTrumpSuit(std::string trumpSuit);

private:
    std::string mPlayerName;
    std::vector<Card*> * mPlayerHand;
    int mScore;
    std::string mTrumpSuit;


};

#endif