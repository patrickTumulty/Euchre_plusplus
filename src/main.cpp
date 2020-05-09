#include <iostream>
#include <memory>
#include "carddeck.hpp"
#include "euchredeck.hpp"
#include "euchre.hpp"

int main()
{
    Euchre * euchre = new Euchre();
    euchre->createNewPlayer("Ripley");
    euchre->createNewPlayer("Deckard");
    euchre->createNewPlayer("Winston");
    euchre->createNewPlayer("Michael");
    euchre->deal();
    euchre->printPlayerHands(); // prints player name, player hand, and hand rank
    
    return 0;
}