/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   warGame.h
 * Author: Jason
 *
 * Created on December 5, 2018, 2:18 PM
 */

#ifndef WARGAME_H
#define WARGAME_H

#include "CounterClass.h"

using namespace std;
class warGame {
public:
    warGame();
    void displayCard(int);
    void checkCard(int, int);
    void putCardsInTieBank(vector<int>&, vector<int>&);
    void dispenseTieCards(vector<int>&); 
    void compareCards(); 
    void dispenseCards();
    warGame(const warGame& orig);
    virtual ~warGame();
    static int gamesPlayed;
    class counterOutOfSync{};
private:
    int playerOneCount; 
    int playerTwoCount; 
    int tieCounter; 
    int p1Play; 
    int p2Play; 
    bool playerOneWin; 
    bool ultimateWin;
    bool handOver;
    bool winGame; 
    bool isTie; 
    bool tieResolved;
    vector<int> tiebank;
    vector<int> p1;
    vector<int> p2;
    int MAX_HANDS; 
    
     
};


#endif /* WARGAME_H */

