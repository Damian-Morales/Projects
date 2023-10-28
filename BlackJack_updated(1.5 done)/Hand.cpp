/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "hand.h"
Hand::Hand()
{
    maxNumberHand = 10;
    Cards = new int [maxNumberHand];
    currentAmtCards = 0;
}
Hand::Hand(int* playerHand, int maxHand)// 
{
    maxNumberHand = 10;
    Cards = new int [maxNumberHand];
    currentAmtCards = maxHand;
    for (int count = 0; count < maxNumberHand; count++)
    {
        Cards[count] = playerHand[count];
    }
    
}
Hand::~Hand()//
{
    delete []Cards;
}
int *Hand::getHand()
{
    return Cards;
}
int Hand::getNumhand()
{
    return currentAmtCards;
}
void Hand::addtoHand(int adding)// addition of a card 1
{
    Cards[currentAmtCards++] = adding;
}
void Hand::addtoHand(int* cards, int numCards) // addition of 2 or more cards
{
    for (int count = 0; count < numCards; count++)
    {
        Cards[currentAmtCards++] = cards[count]; 
    }
}
int Hand::getMaxNumberCards()//
{
    return maxNumberHand;
}
void Hand::clear()
{
    currentAmtCards = 0;
    delete []Cards;
    Cards = new int [maxNumberHand];
}