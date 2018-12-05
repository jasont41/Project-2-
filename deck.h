/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   deck.h
 * Author: Jason
 *
 * Created on December 3, 2018, 12:03 PM
 */

#ifndef DECK_H
#define DECK_H
#include <vector>
using namespace std;
class deck {
public:
    deck();
    int dealP1();
    int dealP2(); 
    void shuffle();
    void sortDeck();
    int getp1HandElement(int); 
    int getp2HandElement(int); 
    virtual ~deck();
private:
    int gameDeck[52]; 
    vector<int> p1Hand;
    vector<int> p2Hand; 
    
};

#endif /* DECK_H */

