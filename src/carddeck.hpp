
#ifndef CARDDECK_HPP
#define CARDDECK_HPP

#include <iostream>
#include <stack>
#include <vector>

#define DIAMONDS = "Diamonds"; 
#define JACK = "Jack";
struct Card
{
    Card(std::string value, std::string suit);

    void setColor();

    int pointValue;
    std::string value;
    std::string suit;
    std::string color;

};


class CardDeck
{
public:
    CardDeck();
    ~CardDeck();

    virtual void createNewDeck();
    void shuffleDeck();
    void addToDiscardPile(Card * card);
    void removeJokers();
    void addJokers();
    void resetDeck();
    void discardNextCard();
    Card * revealTopCard(); 
    int getNumRemainingCards();
    Card * getNextCard();

protected:
    std::vector<Card*> * mMainDeck;
    std::stack<Card*> * mDiscardPile;
    
};

#endif