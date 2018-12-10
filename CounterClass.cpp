/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CounterClass.cpp
 * Author: Jason
 * 
 * Created on December 9, 2018, 11:45 PM
 */

#include "CounterClass.h"

CounterClass::CounterClass() {
    playerWinCount = 0; 
    
}

int CounterClass::getCount() {
    return playerWinCount;
}

void CounterClass::setCount(int a) {
    playerWinCount = a;
}

// The idea here is to have a separate instance of this class 
// for each player, and the warGame class will take these two 
// objects and add them together and then compare that to the counter 
// if it matches, nothing will happen. If it doesn't the code will tell the user 
CounterClass CounterClass::operator+(CounterClass obj) {
    CounterClass newOBJ; 
    newOBJ.playerWinCount = playerWinCount + obj.playerWinCount;
    return (newOBJ);
}
//Same as above, just with subtraction
CounterClass CounterClass::operator-(CounterClass obj) {
    CounterClass newOBJ; 
    newOBJ.playerWinCount = playerWinCount - obj.playerWinCount; 
    return(newOBJ); 
}
//Just a simple increment of the member variable 
CounterClass CounterClass::operator++(int q) {
    playerWinCount = playerWinCount +1; 
}

CounterClass::CounterClass(const CounterClass& orig) {
}

CounterClass::~CounterClass() {
}

