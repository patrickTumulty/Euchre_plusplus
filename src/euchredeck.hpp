
#ifndef EUCHREDECK_HPP
#define EUCHREDECK_HPP

#include "carddeck.hpp"

class EuchreDeck : public CardDeck
{
public: 
    void createNewDeck() override;
    std::string checkColor(std::string suit);
private:
    
};


#endif