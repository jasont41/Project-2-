/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   deck.cpp
 * Author: Jason
 * 
 * Create#include "deck.h"d on December 3, 2018, 12:03 PM
 */
#include "deck.h"
#include <iomanip>
//to seed random number 
#include <vector>
#include <iostream>

using namespace std;
deck::deck() {
    int temp[52] = {2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6,
        6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 11, 11, 11, 11,
        12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14};
    int n = sizeof(temp)/sizeof(temp[0]);
    vector<int>temp1(temp, temp+n);
    gameDeck = temp1;
    shuffle(gameDeck);
    dealCards();
}

void deck::shuffle(vector<int> &deck) { 
    //making size holder so child classes can then be reshuffled 
    int size = deck.size(); 
    int shufflePlace, shuffleSwap;
    for (int i = 0; i < 100; i++) {
        char holder; //just a check holder 
        shufflePlace = rand() % size + 1; //Find the card to be swapped 
        shuffleSwap = rand() % size + 1; //The new home of the swapped card 
        holder = deck[shufflePlace];
        deck[shufflePlace] = deck[shuffleSwap];
        deck[shuffleSwap] = holder; //Return the second card in the swap
    }
}
//          Uses modulus to split the deck into two hands evenly 
//          I went with vectors because it is easier than handling dynamic arrays 

int deck::dealCards() {
    vector<int>::iterator middle(gameDeck.begin() + gameDeck.size()/2);
    for(auto it = gameDeck.begin(); it != gameDeck.end();++it){
        if(distance(it, middle) > 0){
            p1Hand.push_back(*it);
        }
        else{
            p2Hand.push_back(*it);
        }
    }
    
}




int deck::getp1HandElement(int i) {
    return p1Hand[i-1];
}
//On the off chance user would like to see an element in the hand
int deck::getp2HandElement(int i) {
    return p2Hand[i -1];
}

vector<int> deck::getp1Hand() {
    return p1Hand;
}

vector<int> deck::getp2Hand() {
    return p2Hand; 
}

void deck::sortDeck() {
    /*
     Pulled from textbook, chapter 8 - section 3. 
     */
    bool swap; 
    int temp; 
    do{
        swap = false; 
        for(int count = 0; count < 51; count ++){
            if(gameDeck[count] > gameDeck [count + 1]){
                temp = gameDeck[count];
                gameDeck[count] = gameDeck[count + 1]; 
                gameDeck[count + 1] = temp;
                swap = true; 
            }
        }
    }while(swap);
}

void deck::deleteDeck() {
    int temp = gameDeck.size(); 
    for (int i = 0; i < temp - 1; i++){
        vector<int>::iterator it; 
        it = gameDeck.begin();
        gameDeck.erase(it);
    }
}

char deck::getFace(int a) {
     static char face[]={'A','2','3','4','5','6',
                         '7','8','9','T','J','Q','K'};
    return face[a];
}

char deck::getSuit(int a) {
    int randNum = rand()%(3-0 + 1) + 0;
    static char suit[]={'S','D','C','H'};
    return suit[randNum];
}

int deck::printCards() {
    for(int i = 0; i < gameDeck.size(); i++){ 
        cout<< gameDeck.at(i) << " ";
    }
}




deck::~deck() {

}


Player::Player() {
}

void Player::setName(string temp) {
    name = temp; 
}

string Player::getName() {
    return name; 
}

vector<int> Player::shufHand() {
    shuffle(hand);
    return hand;
}

void Player::setHand(vector<int> a) {
    hand = a;
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}
