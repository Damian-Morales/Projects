/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Card.h
 * Author: Damian
 *
 * Created on May 25, 2021, 7:43 PM
 */
#include "AbstractCard.h"


#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;
class Card:public AbsCard
{
    private:
        int number;
        
 
        public:
            Card(int);// constructor
            ~Card();// deconstructor
            char getsuit();
            char getface();
            int getcardValue();// return value of card
            int getNumber();
            
};


#endif /* CARD_H */

