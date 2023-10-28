/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <iomanip>
#include "Game.h"
#include "hand.h"
using namespace std;
Game::Game(int players)
{
    hands = new Hand[players+1];
    deck = new Deck(52);
    numPlayers = players;
    deck->shuffle(7);
    //deck->print();
}
Game::~Game()
{
    delete[]hands;
    delete deck;
}
void Game::play()
{
    char answer;
    char HorS;
    int holder = 0;
    int sum=0;
    int dealerSum=0;
    cout << "Welcome to Black Jack" << endl;
    
    cout << "Do you want to play Black Jack? Y or N" << endl;
    cin >> answer;
    while (answer == 'Y'|| answer == 'y')
    {
        for (int i = 0; i < numPlayers+1; i++)
        {
            hands[i].clear();
        }
          cout<<"Dealer: ";        //dealer 0 and player 1+
        hands[0].addtoHand(deck->deal(1),1);
        deck->print(hands[0]);
        
        
        for (int i = 1; i < numPlayers+1; i++)
        {
            cout << "players hand for " << i << endl;
            hands[i].addtoHand(deck->deal(2), 2);
            deck->print(hands[i]);  
        }
        sum=0;
        //hands[1].clear();

        //hands[1].addtoHand(deck->deal(2),2);
        
        //deck->print(hands[0]);
        //cout<<endl<<"Player: ";
        //deck->print(hands[1]);
        //cout<<endl;
        //hands[0].addtoHand(deck->deal(1),1);
        for (int count = 1; count <= numPlayers; count++)
        {
            //sum = 0;
            sum = getSum(&hands[count], hands[count].getNumhand(), deck);
            /*
            for(int i=0;i<hands[count].getNumhand();i++){
            sum+= deck->getcard(true,hands[count].getHand()[i]);//get the value of the card
        }
             */
            cout<<"Sum for player " << count<< " is: " << sum << endl;
        }

        /*int *temp = hands[0].getHand();
        for (int count = 0; count < 10; count++)
        {
            cout << temp[count] << " " << endl;  
        }
        */
        
        // accum the hand of the deck(add previous cards together)
        for (int i = 1; i <= numPlayers; i++)
        {
            sum = getSum(&hands[i], hands[i].getNumhand(), deck);
            //sum = 0;
            /*
            for(int j=0;j<hands[i].getNumhand();j++){
            sum+= deck->getcard(true,hands[i].getHand()[j]);
            }
             */
            do
            {
                cout << "Would you like to hit or stand for player " << i << " ?" << endl;
                cin >> HorS;

                if (HorS == 'y'|| HorS == 'y')
                {
                    hands[i].addtoHand(deck->deal(1),1);
                    deck->print(hands[i]);
                    sum+=deck->getcard(true,hands[i].getHand()[hands[i].getNumhand()-1]);
                    cout<<"Sum: "<<sum<<endl;
                    
                    if (sum > 21)
                    {
                        cout << "You lost" << endl;
                    }
                    
                }
            } while ((HorS == 'y'|| HorS == 'y')&&sum<21);
            
        }

        
        
        //get cards for the dealer until the sum is greater than 17
        //cout << "dealers hand: " << endl;// help
        //deck->print(hands[0]);
        
        for(int i=0;i<hands[0].getNumhand();i++)
        {
            dealerSum+=deck->getcard(true,hands[0].getHand()[i]); // adding all the cards to the sum
        }
       // cout<<"Sum: "<<dealerSum<<endl;
        while (dealerSum<17&& sum <= 21)
        {

                hands[0].addtoHand(deck->deal(1),1);

                dealerSum+=deck->getcard(true,hands[0].getHand()[hands[0].getNumhand()-1]); // adding the last card to the (previous)sum
                
        }
        
        
        cout << "dealers hand: " << endl;
        deck->print(hands[0]);
        cout<<"Sum: "<<dealerSum<<endl;
        
        for( int i = 1; i <= numPlayers; i++ ) {
            cout << "player " << i << endl;
            sum = 0;
            for(int j=0;j<hands[i].getNumhand();j++){
            sum+= deck->getcard(true,hands[i].getHand()[j]);
            }
            
            cout << "Sum was: " << sum << endl;
	if( dealerSum > 21 ) {
		if( sum <= 21 ) {
                    cout << "you won" << endl;
		}
		else {
                    cout << "You lost" << endl;
		}
	}
	else {
		if( sum > 21 ) {
                    cout << "You lost" << endl;
		}
		else if( sum > dealerSum ) {
                    cout << "You won" << endl;
		}
		else if( sum == dealerSum) {
			cout << "It's a tie" << endl;
		}
		else {
                    cout << "Player lost" << endl;
		}		
            }
        }

        
        
        
        
        //if((sum>dealerSum&&sum<=21) || dealerSum > 21){
            //cout<<"You won"<<endl;
        //}
        //else if(sum == dealerSum)
        //{
        //    cout << "dealer has won" << endl;
        //}
        //else{
        //    cout<<"You lost"<<endl;
        //}
        
        
        // show dealers cards

        
        //see who is closer to 21
        
        cout << "Do you want to play another game of Black Jack? Y or N" << endl;
        cin >> answer;    
    }
    
    
}