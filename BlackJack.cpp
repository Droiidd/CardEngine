#pragma once
#include <vector>
#include <string.h>
#include <string>
#include <stack>
#include <iostream>
#include <stdlib.h>
#include <conio.h>

#include "card.h"
#include "deck.h"
#include "BlackJack.h"

BlackJack ::BlackJack()
{

}
BlackJack:: ~BlackJack()
{

}

void BlackJack::play()
{
    int chosen = 0;
    int selection = 0;
    folded = false;
    playersTurn = true;
    std::cout << "Please enter a shuffle amount: " << std::endl;
    std::cin >> chosen;

    Deck deck;
    for(int i = 0; i < chosen; i ++){
        deck.shuffle();
    }
    std::cout<<""<<std::endl;
    std::cout<<"Welcome to Droiid's Black Jack Shack! \nThe dealer has shuffled, let's begin."<<std::endl;

    std::cout<<""<<std::endl;

// ===--- INITIALIZE PLAYER / BOT HANDS WITH 2 CARDS ---===
    playerHand.push_back(deck.draw());
    playerHand.push_back(deck.draw());

    botHand.push_back(deck.draw());
    botHand.push_back(deck.draw());
    std::cout<<"Dealer is showing: \n [ ? ] "<<botHand.at(1)->getCardDisplay()<<std::endl;
    std::cout<<std::endl;

    //GAME INITIALIZED.
    while(playersTurn == true)
    {
        std::cout<<"Hand:"<<std::endl;
        for(int i = 0; i < playerHand.size(); i ++){
            std::cout<<playerHand.at(i)->getCardDisplay();
        }
        std::cout<<"\n"<<std::endl;
        std::cout<<"Select:\n1.) Hit    2.) Stand   3.)Place bet   4.)Fold"<<std::endl;
        std::cin>>selection;
        switch(selection){
            //HIT
            case 1:
                Card* test;
                test = deck.draw();
                playerHand.push_back(test);
                std::cout<<"\n\n\n\n\nYou drew "<<test->getCardDisplay()<<std::endl;
                if(checkBust(playerHand) == true){
                    //They busted
                    std::cout<<checkBust(playerHand)<<std::endl;
                    std::cout<<"\n\n\n\n\nPlayer busted!\nDealer wins.";
                    playersTurn =  false;
                }
                break;
                //Stand
            case 2:
                //DEALERS TURN
                playersTurn = false;
                break;
                //Place bet
            case 3:
                //Place a bet
                break;
            case 4:
                //Player folds
                std::cout<<"\n\n\n\n\nPlayer folded.\nDealer wins."<<std::endl;
                folded = true;
                playersTurn = false;
                break;
        }
    }

    bool botsTurn = true;
    if(busted != true && folded != true){
        while(botsTurn == true){
            //Dealer takes their turn
            std::cout<<"Dealer is showing: \n [ ? ] "<<botHand.at(1)->getCardDisplay()<<std::endl;
            if(canAIHit(botHand) == true)
            {
                botHand.push_back(deck.draw());
                for(int i = 1;i<botHand.size(); i++){
                    std::cout<<botHand.at(i)->getCardDisplay();
                }
            }else{
                botsTurn = false;
            }
            if(checkBust(botHand) == true){
                //Player wins!!
                std::cout<<"Player wins!"<<std::endl;
                botsTurn = false;
            }
        }
    }
    std::cout<<"\n\n\n"<<std::endl;
        //PLAYERS NOW COMPARE HANDS
    determineWinner(playerHand, botHand);
}

bool BlackJack::checkBust(vector<Card*> hand)
{
    int pointTotal = getHandPoints(hand);
    if(pointTotal >21) {
        busted = true;
        return true;
    }
    return false;
}
bool BlackJack::canAIHit(vector<Card*> hand)
{
    int pointTotal = getHandPoints(hand);
    if(pointTotal <16) {
        return true;
    }
    return false;
}
int BlackJack::getHandPoints(vector<Card*> hand)
{
int pointTotal = 0;
for(int x = 0;x<hand.size();x++){
if(hand.at(x)->getCardValue() == 11 || hand.at(x)->getCardValue() == 12 || hand.at(x)->getCardValue() == 13){
pointTotal += 10;
}else if(hand.at(x)->getCardValue() == 14){
pointTotal += 11;
//ITS AN ACE!!! 1 OR 11
}else{
pointTotal += hand.at(x)->getCardValue();
}

}
    return pointTotal;


}

void BlackJack::determineWinner(vector<Card *> playerHand, vector<Card *> botHand)
{
    std::cout<<"Flop!"<<std::endl;
    int playerPoints = getHandPoints(playerHand);
    int botPoints = getHandPoints(botHand);

    std::cout<<"Players Hand:"<<std::endl;
    for(int i = 0; i < playerHand.size(); i ++){
        std::cout<<playerHand.at(i)->getCardDisplay();
    }
    std::cout<<"\n"<<std::endl;
    std::cout<<"Dealers Hand:"<<std::endl;
    for(int i = 0; i < botHand.size(); i ++){
        std::cout<<botHand.at(i)->getCardDisplay();
    }
    std::cout<<"\n\n"<<std::endl;
    if(playerPoints > botPoints){
        //PLAYER WINS!
        std::cout<<"Player wins!"<<std::endl;
    }else if(playerPoints == botPoints){
        //DRAW
        std::cout<<"Draw!"<<std::endl;
    }else{
        //BOT WON
        std::cout<<"The dealer wins!"<<std::endl;
    }
}