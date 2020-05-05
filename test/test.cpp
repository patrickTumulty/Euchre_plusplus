#include <iostream>
#include <gtest/gtest.h>
#include "../src/carddeck.hpp"


TEST(NOTEQUAL, notEqual)
{
    CardDeck * deck = new CardDeck();
    deck->shuffleDeck();

    Card * card1 = deck->getNextCard();
    Card * card2 = deck->getNextCard();

    ASSERT_FALSE((card1->value == card2->value)&&(card2->suit == card2->suit));
}

int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}