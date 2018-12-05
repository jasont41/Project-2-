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
//#include <vector>

using namespace std;
deck::deck() {
    int gameDeck [52] = {2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6,
        6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 11, 11, 11, 11,
        12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14};
}

void deck::shuffle() {
    int shufflePlace, shuffleSwap;
    for (int i = 0; i < 100; i++) {
        char holder; //just a check holder 
        shufflePlace = rand() % 52 + 1; //Find the card to be swapped 
        shuffleSwap = rand() % 52 + 1; //The new home of the swapped card 
        holder = gameDeck[shufflePlace];
        gameDeck[shufflePlace] = gameDeck[shuffleSwap];
        gameDeck[shuffleSwap] = holder; //Return the second card in the swap
    }
}
//          Uses modulus to split the deck into two hands evenly 
//          I went with vectors because it is easier than handling dynamic arrays 

int deck::dealP1() {
    for (int i = 0; i < 52; i++) {
        if (i % 2 == 0) {
            p1Hand.push_back(gameDeck[i]);
        }
    }
}

int deck::dealP2() {
    for (int i = 0; i < 52; i++) {
        if (i % 2 == 1) {
            p2Hand.push_back(gameDeck[i]);
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



deck::~deck() {
}

