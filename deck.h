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
#include <string>
using namespace std;
class deck {
public:
    deck();
    int dealCards();
    void shuffle(vector<int> &);
    void sortDeck();
    vector<int> getp1Hand();
    vector<int> getp2Hand(); 
    int getp1HandElement(int); 
    int getp2HandElement(int); 
    void deleteDeck(); 
    void putCardsInTieBank();
    char getFace(int);
    char getSuit(int);
    int  printCards();
    virtual ~deck(); 
protected: 
    vector<int> p1Hand; 
    vector<int> p2Hand; 
private:
    vector<int> gameDeck;  
    
    
    
};
class Player: public deck{
public:
    Player();
    void setName(string a); 
    string getName(); 
    void setHand(vector<int>); 
    vector<int> shufHand();
    vector<int> getHand(); 
    Player(const Player& orig);
    virtual ~Player();
private:
    string name;
    vector<int> hand;
};

#endif /* DECK_H */

