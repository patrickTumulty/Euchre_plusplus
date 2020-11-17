#include <iostream>
#include <memory>
#include "carddeck.hpp"
#include "euchredeck.hpp"
#include "euchre.hpp"
#include "cardprinter.hpp"

int main()
{
    Euchre * euchre = new Euchre();
    euchre->createNewPlayer("Ripley");
    euchre->createNewPlayer("Deckard");
    euchre->createNewPlayer("Winston");
    euchre->createNewPlayer("Michael");
    euchre->deal();
    euchre->printPlayerHands(); 

    // Card * card = new Card("Jack", "Diamonds");
    // std::cout << card->value << std::endl;
    // std::cout << CardPrinter::printCard(card) << std::endl;

    return 0;
}