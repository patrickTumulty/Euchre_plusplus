#include <iostream>
#include <math.h>
#include <gtest/gtest.h>
#include "../src/carddeck.hpp"
#include "../src/euchredeck.hpp"
#include "../src/player.hpp"
#include "../src/euchre.hpp"


TEST(HANDRANK, rank)
{
    Player * player1 = new Player("Walter");
    player1->setTrumpSuit("Spades");
    player1->addCardToHand(new Card("Jack", "Spades")); // highest possible hand
    player1->addCardToHand(new Card("Jack", "Clubs"));
    player1->addCardToHand(new Card("Ace", "Spades"));
    player1->addCardToHand(new Card("King", "Spades"));
    player1->addCardToHand(new Card("Queen", "Spades"));
    ASSERT_EQ(1, player1->rateHand());
}

TEST(HANDRANK2, rank)
{
    Player * player1 = new Player("Walter");
    player1->setTrumpSuit("Spades");
    player1->addCardToHand(new Card("10", "Hearts")); // lowest possible hand
    player1->addCardToHand(new Card("10", "Diamonds"));
    player1->addCardToHand(new Card("9", "Diamonds"));
    player1->addCardToHand(new Card("9", "Hearts"));
    player1->addCardToHand(new Card("9", "Clubs"));
    ASSERT_EQ(13, (int)((player1->rateHand()) * 100));
}

TEST(NOTEQUAL, notEqual) // check to ensure each card is unique
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