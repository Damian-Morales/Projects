/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Damian
 *
 * Created on May 25, 2021, 5:56 PM
 */

#include <iostream>
#include <cstdlib>
#include "Game.h"

using namespace std;


int main()
{
    unsigned seed = time(0);
    srand(seed);
    
    int numPlay;
    cout << "How many players will there be?" <<endl;
    cin >> numPlay;
    Game game(numPlay);
    game.play();
    
    
    
    
    
    return 0;
    
    
    
    
    
    
    
    
    
    
    
    
    
}

