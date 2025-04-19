//
// Created by Tanner Smith on 4/18/25.
//

#ifndef DECK_H
#define DECK_H
#include <vector>
#include "Card.h"
using namespace std;


class Deck {
private:
    vector<Card> m_cardDeck;
    void shuffleDeck();
    public:
    Deck();
    Card dealCard();
    int getCount();
};



#endif //DECK_H
