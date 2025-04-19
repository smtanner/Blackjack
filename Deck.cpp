//
// Created by Tanner Smith on 4/18/25.
//

#include "Deck.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include "Card.h"


Deck::Deck() {
        vector<string> suits {"Hearts", "Diamonds", "Spades", "Clubs"};
        vector<string> ranks {"2", "3", "4", "5", "6", "7", "8","9","10", "Jack","Queen","King","Ace"};

        for (const auto& suit : suits) {
            for (const auto& rank : ranks) {
                int value;
                if (rank == "Ace") {
                    value = 11;
                } else if (rank == "Jack" || rank == "Queen" || rank == "King") {
                    value = 10;
                } else {
                    value = std::stoi(rank);
                }

                m_cardDeck.push_back(Card(suit, rank, value));
            }
        }

        shuffleDeck();

}
void Deck::shuffleDeck() {
    random_device rd;
    mt19937 gen(rd());
    shuffle(m_cardDeck.begin(),m_cardDeck.end(),gen);

}
Card Deck::dealCard() {
    Card temp;
    temp = m_cardDeck.back();
    m_cardDeck.pop_back();
    return temp;
}
int Deck::getCount() {
    return m_cardDeck.size();
}
