/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Card.h"
#include <iostream>
using namespace std;
Card::Card(int value)
{
    number = value;
}
Card::~Card() // 
{
    
}
char Card::getsuit()
{
    static char suit[]={'S','D','C','H'};
    return suit[number/13];
}
char Card::getface()
{
    static char face[]={'A','2','3','4','5','6',
                         '7','8','9','T','J','Q','K'};

    return face[number%13];
}
int Card::getcardValue()
{
    if (number%13 > 8)
    {
        return 10;
    }
        return (number%13) + 1;
        
}
int Card::getNumber()
{
    return number;
}