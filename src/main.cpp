#include <iostream>
#include "carddeck.hpp"

int main()
{
    std::unique_ptr<CardDeck> Deck = std::make_unique<CardDeck>();
    Deck->shuffleDeck();
    Card * card = Deck->getNextCard();
    std::cout << card->value << " of " << card->suit << std::endl;
    card = Deck->getNextCard();
    std::cout << card->value << " of " << card->suit << std::endl;
    card = Deck->getNextCard();
    std::cout << card->value << " of " << card->suit << std::endl;
    card = Deck->getNextCard();
    std::cout << card->value << " of " << card->suit << std::endl;
    card = Deck->getNextCard();
    std::cout << card->value << " of " << card->suit << std::endl;
    return 0;
}