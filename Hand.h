//
// Created by Tanner Smith on 4/18/25.
//

#ifndef HAND_H
#define HAND_H

#include <vector>
#include "card.h"
using namespace std;

class Hand {
private:
    vector<Card> m_hand;
    public:
    Hand();
    void clear_hand();
    void operator+=(Card);
    Card displayCard(int);
    int getPoints();
    int cardCount();
};



#endif //HAND_H
