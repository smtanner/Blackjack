#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() {}

Hand Game::getplayerHand(Deck &deck, Hand &hand) {
    hand += deck.dealCard();
    hand += deck.dealCard();
    return hand;
}

Hand Game::getDealerHand(Deck &deck, Hand &hand) {
    hand += deck.dealCard();
    hand += deck.dealCard();
    return hand;
}

void Game::displayCards(Hand hand, string name) {
    cout << name << "'s Cards:" << endl;
    for (int i = 0; i < hand.cardCount(); i++) {
        cout << hand.displayCard(i).getCard() << endl;
    }
    cout << endl;
}

void Game::displayround() {
    cout << "Dealer's Show Card: " << endl;
    cout << DealerHand.displayCard(0).getCard() << endl;
    displayCards(playerHand, "Player");
}

void Game::playGame() {
    cout << "###########################" << endl;
    cout << "#  The Game of Blackjack  #" << endl;
    cout << "###########################" << endl << endl;

    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        m_deck = Deck();  // Reset deck
        playerHand.clear_hand();
        DealerHand.clear_hand();

        playerHand = getplayerHand(m_deck, playerHand);
        DealerHand = getDealerHand(m_deck, DealerHand);

    displayround();

        char choice;
        do {
            cout << "Hit or stand? (h/s): ";
            cin >> choice;
            if (choice == 'h' || choice == 'H') {
                playerHand += m_deck.dealCard();
                displayCards(playerHand, "Player");
            }
        } while ((choice == 'h' || choice == 'H') && playerHand.getPoints() < 21);

        if (playerHand.getPoints() <= 21) {
            while (DealerHand.getPoints() < 17) {
                DealerHand += m_deck.dealCard();
            }
        }

        displayCards(DealerHand, "Dealer");

        int playerPoints = playerHand.getPoints();
        int dealerPoints = DealerHand.getPoints();

        cout << "Your Points: " << playerPoints << endl;
        cout << "Dealer's Points: " << dealerPoints << endl;

        if (playerPoints > 21) {
            cout << "Sorry. You busted. You lose." << endl;
        } else if (dealerPoints == 21 && playerPoints < dealerPoints) {
            cout << "Dealer had Blackjack. You lose." << endl;
        } else if (playerPoints == 21 && playerPoints > dealerPoints) {
            cout << "Blackjack! You win!" << endl;
        } else if (playerPoints == dealerPoints && dealerPoints == 21) {
            cout << "Dang. Dealer has blackjack too. You push." << endl;
        } else if (dealerPoints > 21) {
            cout << "Yay! The dealer busted. You win!" << endl;
        } else if (playerPoints > dealerPoints) {
            cout << "Hooray! You win!" << endl;
        } else if (playerPoints < dealerPoints) {
            cout << "Sorry. You lose." << endl;
        } else {
            cout << "It's a tie! You push." << endl;
        }

        cout << endl << "Play another round? (y/n): ";
        cin >> playAgain;
        cout << endl;
    }

    cout << "Thanks for playing!" << endl;
}
