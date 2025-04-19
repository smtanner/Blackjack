#include "Hand.h"

Hand::Hand() {}

void Hand::clear_hand() {
    m_hand.clear();
}

void Hand::operator+=(Card temp) {
    m_hand.push_back(temp);
}

Card Hand::displayCard(int i) {
    return m_hand[i];
}

int Hand::getPoints() {
    int points = 0;
    int aceCount = 0;

    for (auto& card : m_hand) {
        points += card.getValue();
        if (card.getRank() == "Ace") {
            aceCount++;
        }
    }


    while (points > 21 && aceCount > 0) {
        points -= 10;
        aceCount--;
    }

    return points;
}

int Hand::cardCount() {
    return m_hand.size();
}
