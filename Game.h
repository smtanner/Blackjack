//
// Created by Tanner Smith on 4/18/25.
//

#ifndef GAME_H
#define GAME_H
#include "Deck.h"
#include "Hand.h"
#include "iostream"
using namespace std;
class Game {
private:
    Deck m_deck;
    Hand playerHand;
    Hand DealerHand;
    public:
    Game();
    Hand getplayerHand(Deck &deck, Hand &hand);
    Hand getDealerHand(Deck &deck, Hand &hand);
    void displayCards(Hand hand, string name);
    void displayround();
    void playGame();

};



#endif //GAME_H
