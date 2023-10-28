/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   deck.h
 * Author: Damian
 *
 * Created on May 27, 2021, 7:13 PM
 */
#include "hand.h"
#include "Card.h"
#include <stack>
#ifndef DECK_H
#define DECK_H
class Deck
{
private:
    int nCards;// total 0f entire deck
    Card** deck;// brand new deck
    int *index;// shuffle deck
    stack<Card> Cards; // stack stl library
public:
    Deck(int);
    ~Deck();
    void shuffle(int nShuffle);// shuffle of cards. The integer is the number of times you shuffle a deck. (srand) grab 2 numbers. Swap too. for loop 52 and nShuffle.
    int *deal(int nCards);// to give nCards cards to the player
    int getcard(bool, int);// bool = to see if you want to return the shuffle deck or brand new (52). Integer = position of the card.
    void print();// Print all the entire shuffle deck
    void print(Hand&);// print the players hand
};


#endif /* DECK_H */

