/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jason
 *
 * Created on December 3, 2018, 9:21 AM
 */

#include <cstdlib>
#include <iostream>
#include "deck.h"
#include "warGame.h"
using namespace std;

void intro() {
    cout << "Take a minute and let me know how many games you could like to see\n";
}
template <class T> 
void add(T &a){
    a++;
}
/*
 * 
 */
int main(int argc, char** argv) {
    intro();
    int num1;
    cout << "How many?\n";
    cin >> num1;
    add(num1);
    cout << "Let's do one more, just to be sure :) \n ";
    warGame games[num1];
    for (int i = 0; i < num1; i++) {
        warGame game;
    }
    //warGame game;
    //deckTest.printDeck();
}

