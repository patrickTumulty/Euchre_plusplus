
#ifndef CARDDECK_HPP
#define CARDDECK_HPP

#include <iostream>
#include <vector>

struct Card
{
    Card(std::string value, std::string suit);
    std::string value;
    std::string suit;
};


class CardDeck
{
public:
    CardDeck();
    ~CardDeck();

    void createNewDeck();
    void shuffleDeck();
    void addToDiscardPile(Card * card);
    int getNumRemainingCards();
    Card * getNextCard();

private:
    std::vector<Card*> * mMainDeck;
    std::vector<Card*> * mDiscardPile;

};

#endif