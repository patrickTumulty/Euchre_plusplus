

#include <iostream>
#include "cardprinter.hpp"

std::string CardPrinter::printCard(Card * card)
{
    std::cout << std::to_string(card->value[0]) << std::endl;
    // std::string val = (char)card->value[0];
    // std::string suit = std::to_string((char)card->suit[0]);
    std::string one = "+---\n";
    // std::string two = "|" + val + " |\n";
    // std::string three = "| " + suit + "|\n";
    std::string four = " ---+\n";
    // return one + two + three + four;
}