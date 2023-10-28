/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "deck.h"
#include <cstdlib>
#include <iostream>
#include <stack> //STL Library
using namespace std;
Deck::Deck(int numCards)
{  
    nCards = numCards;
    deck = new Card*[nCards];
    index = new int [nCards];
    for (int count = 0; count < nCards; count++)
    {
        deck[count] = new Card(count);// creating 1 single card, with value of count. Being saved into the "Deck".
        index[count]= count;
    }
}
Deck::~Deck()
{
    for (int count = 0; count < nCards; count++)
    {
        delete deck[count];// delete 1 pointer = card
    }
    delete []deck;// deleting whole array of pointers = card(s) (entire thing)
    delete []index;// removing whole array of pointers = integers
}
void Deck::shuffle(int nShuffle)// first
{
    
    int card1;
    int card2;
    int temp;
    for (int count = 0; count < nShuffle; count++)
    {
        for (int i = 0; i < nCards; i++)
        {
            card1 =  rand()%52;
            card2 = rand()%52;

            temp = index[card1];
            index[card1]= index[card2];
            index[card2] = temp;
        }
    }
    for (int i = 0; i <nCards; i++)
    {
        Card c(index[i]);
        Cards.push(c);
    }
}
int* Deck::deal(int nCards)
{
    // when you call deal to store the stuff we hae to delete the dynamic array. (main or desconstr)
    static int counter=0;
    int lastCard=(nCards + counter + 1)% this->nCards;
    int randNumb;
    int *array = new int[nCards];
    
    for( int i = 0; i < nCards; i++ ) {
    Card c = Cards.top();
    Cards.pop();
    array[i] = c.getNumber();
    }
    
    /*
    for (int count = 0; counter%this->nCards != lastCard; counter++, count++)
    {
        if (counter > this->nCards)
            {
                counter%=this->nCards;
                shuffle(7);
            }
        array[count]=index[counter];
        
    }

     */
    return array;
    
}
int Deck::getcard(bool notShuffleDeck, int position)
{
    if (notShuffleDeck)
    {
        return deck[position]->getcardValue();
    }
    else 
    {
        return deck[index[position]]->getcardValue();
    }
    
}
void Deck::print() // second
{
    for(int count = 0; count < nCards; count++)
    {
        cout << deck[count]->getface()<<" "<<deck[count]->getsuit()<<" "<<deck[count]->getcardValue()<< endl;
    }
}
void Deck::print(Hand& playersHand) //
{
    int *array1 = playersHand.getHand();
    for (int count = 0; count < playersHand.getNumhand(); count++)
    {
        cout << deck[array1[count]]->getface() <<" " <<deck[array1[count]]->getsuit() << " ";
    }
    cout<<endl;
}