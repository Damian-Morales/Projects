/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hand.h
 * Author: Damian
 *
 * Created on May 27, 2021, 7:12 PM
 */

#ifndef HAND_H
#define HAND_H
#include "AbstractHand.h"
using namespace std;

class Hand:public AbsCard2
{
private:
    int *Cards;
    int maxNumberHand;
    int currentAmtCards;
public:
    Hand();// default
    Hand(int*, int);// create a hand by passsing an array with index of cards and the number(size) of cards;
    ~Hand();// deconstructor (cards)
    int *getHand();//
    int getNumhand();// single return
    void addtoHand(int);// adding a card to the hand
    void addtoHand(int*, int);
    int getMaxNumberCards();// single return maxnumberhand
    void clear();
    
};


#endif /* HAND_H */

