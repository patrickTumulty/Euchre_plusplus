
#ifndef EUCHREDECK_HPP
#define EUCHREDECK_HPP

#include "carddeck.hpp"

class EuchreDeck : public CardDeck
{
public: 
    void createNewDeck() override;
    void rankCards(std::string trumpSuit);
    std::string checkColor(std::string suit);
private:
    
};


#endif