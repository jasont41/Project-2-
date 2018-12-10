/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CounterClass.h
 * Author: Jason
 *
 * Created on December 9, 2018, 11:45 PM
 */

#ifndef COUNTERCLASS_H
#define COUNTERCLASS_H

class CounterClass {
public:
    CounterClass();
    int getCount();
    void setCount(int);
    CounterClass operator+(CounterClass); 
    CounterClass operator-(CounterClass);
    CounterClass operator++(int); 
    
    CounterClass(const CounterClass& orig);
    virtual ~CounterClass();
private:
    int playerWinCount;
};

#endif /* COUNTERCLASS_H */

