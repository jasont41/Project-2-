/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   warGame.cpp
 * Author: Jason
 * 
 * Created on December 5, 2018, 2:18 PM
 */
#include <iostream>
#include <vector>
#include "deck.h"
#include "warGame.h"
#include "CounterClass.h"
using namespace std;
//Static variable to count number of games played 
int warGame::gamesPlayed = 0;

warGame::warGame() {
    //Creating instance of deck class here will 
    //create a deck, shuffle the deck and deal the 
    //cards to each player 
    deck gameDeck;

    handOver = false;
    winGame = true;
    isTie = false;
    tieResolved = false;
    MAX_HANDS = 1000;
    int p1Play = 0;
    int p2Play = 0;
    bool playerOneWin = true;
    bool ultimateWin = false;
    bool handOver = false;
    bool winGame = false;
    int tieCounter = 0;
    gamesPlayed++;
    //using vectors built in assignment operator to equate the vectors 
    p1 = gameDeck.getp1Hand();
    p2 = gameDeck.getp2Hand();
    int playerOneCount = p1.size();
    int playerTwoCount = p2.size();
    Player playerOne;
    Player playerTwo;
    playerOne.setName("One");
    playerTwo.setName("Two");
    playerOne.setHand(p1);
    playerTwo.setHand(p2);
    p1 = playerOne.shufHand();
    p2 = playerTwo.shufHand();
    compareCards();
}

void warGame::compareCards() {
    int hands_played = 0;
    CounterClass p1Counter;
    CounterClass p2Counter;
    p1Counter.setCount(0);
    p2Counter.setCount(0);

    do {
        if (tieResolved == true) {
            tiebank.clear();
            tiebank.shrink_to_fit();
        }

        isTie = false;
        int temp1 = p1.front(), temp2 = p2.front();
        p1Play = temp1;
        p2Play = temp2;
        //************Below is for Debugging ***********************************
        cout << "Size of Player One hand before top card dispense: " << p1.size() << "\n";
        cout << "Size of Player Two hand before top card dispense: " << p2.size() << "\n";
        vector<int>::iterator p1Fix;
        vector<int>::iterator p2Fix;
        p1Fix = p1.begin();
        p2Fix = p2.begin();
        p1.erase(p1Fix);
        p2.erase(p2Fix);
        // After cards have been dispensed into int holders, size should be 25 and 25 first go around 
        cout << "P1 size after card is played " << p1.size() << "\n";
        cout << "P2 size after card is played " << p2.size() << "\n";

        do {
            if (p1Play > p2Play) {
                //Player One Wins 
                playerOneWin = true;


                //checkCard(p1Play, 1);
                //checkCard(p2Play, 2);
                cout << "P1 play: " << p1Play << "  P2 play : " << p2Play << endl;
                dispenseCards();
                cout << "Player 1 wins this hand, "
                        "thus gets all cards in play \n";
                //in the case of a tie 
                if (tieResolved == false) {
                    playerOneWin = true;
                    tieResolved = true;
                    cout << "Tie bank Size: " << tiebank.size() << endl;
                    for (int i = 0; i < tiebank.size(); i++) {
                        p1.push_back(tiebank[i]);
                    }
                    cout << "Player 1 wins the tie\n";
                }

                //using the counter class 
                p1Counter.operator++(1);
                cout << "Value of p1Counter\n" << p1Counter.getCount();

                handOver = true;
                if (handOver == true) {
                    hands_played++;
                }//Checking the count of the counter class 
                if (p1Counter.getCount() + p2Counter.getCount() != hands_played) {
                    cout << "It appears as if the counting class isn't working correctly\n"
                            "I apologize\n";
                }
            }//[below] p2 wins hand 
            else if (p2Play > p1Play) {
                //checking player cards 
                // player two wins 
                //using the counter class 
                p2Counter.operator++(1);

                cout << "P1 play: " << p1Play << "  P2 play : " << p2Play << endl;
                playerOneWin = false;
                dispenseCards();
                cout << "Player 2 wins this hand, "
                        "thus gets all cards in play\n";
                //in the case of a tie 
                if (tieResolved == false) {
                    playerOneWin = false;
                    tieResolved = true;
                    cout << "Size of tieBank: " << tiebank.size() << endl;
                    for (int i = 0; i < tiebank.size(); i++) {
                        p2.push_back(tiebank[i]);
                    }
                    cout << "Player 2 wins the tie" << endl;
                }
                handOver = true;
                if (handOver == true) {
                    hands_played++;
                }//Checking the count of the counter class 
                try {
                    if (p1Counter.getCount() + p2Counter.getCount() != hands_played) {
                        cout << "It appears as if the counting class isn't working correctly\n"
                                "I apologize\n";
                        throw counterOutOfSync();
                    }
                } catch (counterOutOfSync) {
                    cout << "Counter needs work\n";
                }
            } else if (p1Play == p2Play) {
                isTie = true;
                putCardsInTieBank(p1, p2);
                // if (p1.size() > 3 || p2.size() > 3) {
                //checkCard(p1Play, 1);
                //checkCard(p2Play, 2);
                cout << "P1 play: " << p1Play << "  P2 play : " << p2Play << endl << endl << endl;
                cout << "It's a tie!\n" << endl << endl;
                cout << "The next three cards of each players hand will now be "
                        "deposited into the tie stack" << endl;
                cout << endl << endl;
                cout << "Size of tieBank: " << tiebank.size() << endl;
                tieResolved = false;
                if (p1.size() < 3 || p2.size() < 3) {
                    cout << "One of the players doesn't have enough cards to continue\n";
                    if (p1.size() < 3) {
                        cout << "player 2 wins \n";
                        handOver = true;
                        ultimateWin = true;
                    }
                    if (p2.size() < 3) {
                        cout << "Player 1 wins \n";
                        handOver = true;
                        ultimateWin = true;
                    }
                    handOver = true;
                    ultimateWin = true;
                }
            }
        } while (handOver == false);
        cout << "Hands that have been played: " << hands_played << endl;
        if (p1.size() == 0) {
            cout << endl << endl << "player two wins game \n";
            ultimateWin = true;
        }
        if (p2.size() == 0) {
            cout << endl << endl << "Player one wins game \n";
            ultimateWin = true;
        }
        if (hands_played == MAX_HANDS) {
            ultimateWin = true;
        }
    } while (ultimateWin == false);


    cout << "Number of hands played " << hands_played << endl;

}

void warGame::putCardsInTieBank(vector<int>&vect1, vector<int>& vect2) {
    tiebank.push_back(p1Play);
    tiebank.push_back(p2Play);
    for (int i = 0; i < 3; i++) {
        tiebank.push_back(p1.at(i));
        tiebank.push_back(p2.at(i));
    }
    cout << "Size of tieBank inside putCardsInTieBank func  " << tiebank.size() << endl;
    for (int i = 0; i < 3; i++) {
        vector<int>::iterator it;
        it = vect1.begin();
        vect1.erase(it);
        vector<int>::iterator it2;
        it2 = vect2.begin();
        vect2.erase(it2);
    }
}

void warGame::dispenseCards() {
    //not in the event of a tie 
    if (playerOneWin == true) {
        p1.push_back(p1Play);
        p1.push_back(p2Play);
    }
    if (playerOneWin == false) {
        p2.push_back(p1Play);
        p2.push_back(p2Play);
    }
}

void warGame::displayCard(int a) {
    if (a > 1 && a < 11) {
        cout << a;
    } else if (a == 11) {
        cout << "J";
    } else if (a == 12) {
        cout << "Q";
    } else if (a == 13) {
        cout << "K";
    } else {
        cout << "A"; // meaning the card drawn was 14 
    }

}

void warGame::checkCard(int card, int player) {
    deck *temp = new deck;
    cout << "Player " << player << "card: " << temp->getFace(card) << "  " << temp->getSuit(card);
    delete temp;
}

warGame::warGame(const warGame & orig) {
}

warGame::~warGame() {
}