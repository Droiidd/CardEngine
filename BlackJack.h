#pragma once
#include <vector>
#include <string.h>
#include <string>
#include <stack>

#include "card.h"
#include "deck.h"

#ifndef UNTITLED_BLACKJACK_H
#define UNTITLED_BLACKJACK_H

using namespace std;

class BlackJack
{
public:
    BlackJack();
    ~BlackJack();
public:
    void play();
protected:
    std::vector<Card*> playerHand;
    std::vector<Card*> botHand;
    bool isWinner;
    bool busted;
    bool folded;
    bool playersTurn;
    int getHandPoints(vector<Card*> hand);
    bool checkWinner( vector<Card*> hand);
    bool checkBust(vector<Card*> hand);
    bool canAIHit(vector<Card*> hand);
    void determineWinner(vector<Card*> playerHand, vector<Card*> botHand);
};


#endif //UNTITLED_BLACKJACK_H
