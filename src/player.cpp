

#include <iostream>
#include <map>
#include <math.h>
#include "player.hpp"

Player::Player(std::string playerName)
{
    this->mPlayerName = playerName;
    this->mPlayerHand = new std::vector<Card*>();
    this->mScore = 0;
}

Player::~Player()
{
    delete this->mPlayerHand;
}

void Player::setTrumpSuit(std::string trumpSuit)
{
    this->mTrumpSuit = trumpSuit;
}

void Player::printHand()
{
    std::cout << "\n[" << this->mPlayerName << "]"<< std::endl;
    std::string val;
    std::string suit;
    int point;
    for (int i = 0; i < this->mPlayerHand->size(); i++)
    {
        val = this->mPlayerHand->at(i)->value;
        suit = this->mPlayerHand->at(i)->suit;
        std::cout << val << " of " << suit << std::endl;
    }
    std::cout << "Hand Score : " << this->rateHand() << std::endl;
}

int Player::evaluateCard(Card* card, std::string trumpSuit)
{
    std::string trumpSuitColor = this->checkColor(trumpSuit);

    std::map<std::string, int> rankMap = std::map<std::string, int>();
    rankMap.insert(std::pair<std::string, int>("9",     1));
    rankMap.insert(std::pair<std::string, int>("10",    2));
    rankMap.insert(std::pair<std::string, int>("Jack",  3));
    rankMap.insert(std::pair<std::string, int>("Queen", 4));
    rankMap.insert(std::pair<std::string, int>("King",  5));
    rankMap.insert(std::pair<std::string, int>("Ace",   6));

    if (card->value == "Jack") 
    {        
        if (card->suit == trumpSuit) { return 13; }
        else if (card->color == trumpSuitColor) { return 12; }
        else { return rankMap[card->value]; }
    }
    else if (card->suit == trumpSuit)
    {
        if (card->value == "9")         { return rankMap[card->value] + 6; }
        else if (card->value == "10")   { return rankMap[card->value] + 6; }
        else if (card->value == "Queen"){ return 9; }
        else if (card->value == "King") { return 10; }
        else if (card->value == "Ace")  { return 11; }
    }
    else
    {
        return rankMap[card->value];
    }
    return 999;
}

std::string Player::checkColor(std::string suit)
{
    if (suit == "Hearts" || suit == "Diamonds") { return "Red"; }
    else { return "Black"; }
}

void Player::addCardToHand(Card* card)
{
    this->mPlayerHand->push_back(card);
}

void Player::clearHand()
{
    this->mPlayerHand->clear();
}

std::string Player::getName()
{
    return this->mPlayerName;
}

void Player::incrementScore(int increment)
{
    this->mScore += increment;
}

int Player::getScore()
{
    return this->mScore;
}

float Player::rateHand()
{
    // 55 is highest score possible. 
    int pointValue = 0;
    float multiplier = 1.0 / 55.0;
    for (int i = 0; i < this->mPlayerHand->size(); i++)
    {
        pointValue += this->evaluateCard(this->mPlayerHand->at(i), this->mTrumpSuit);
    }
    return  roundf(100 * ((float)pointValue * multiplier)) * 0.01;
}

