/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: Damian
 *
 * Created on June 1, 2021, 7:00 PM
 */

#ifndef GAME_H
#define GAME_H
#include "Card.h"
#include "deck.h"
#include "hand.h"

class Game
{
private:
    Deck *deck; //
    Hand *hands; //hold the cards
    int numPlayers; // number of players
public:
    Game(int);// create a game based on numberplayers 
    ~Game();//delete hands(array) and deck(1 variable= no [])
    int getSum(Hand *H, int size, Deck *D)
    {
        if(size == 0) return 0;
        int val = D->getcard(true, H->getHand()[size-1]);
        cout << "Card value is: " << val << endl;
        return val + getSum(H, size - 1, D);
    }
    void play();
};





#endif /* GAME_H */

