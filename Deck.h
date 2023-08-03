#ifndef UNTITLED_DECK_H
#define UNTITLED_DECK_H
#pragma once
#include <vector>
#include <string.h>
#include <string>
#include <stack>

#include "card.h"
using namespace std;

class Deck
{
public:
    Deck();
    ~Deck();
public:
    void shuffle();
    //string getCard();
    void printDeck();
    Card* draw();
protected:
    vector<Card*> deck;
    stack<Card*> shuffledDeck;
};
#endif //UNTITLED_DECK_H
