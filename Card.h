#pragma once
#include <string.h>
#include <string>
#ifndef UNTITLED_CARD_H
#define UNTITLED_CARD_H

using namespace std;


class Card
{
public:
    Card(string suit, int value);
    ~Card();

public:
    void suitCmp(Card c2);
    void valEqTo(Card c2);
    void valIsGreater(Card c2);
    void valIsLess(Card c2);
    int valCmp(Card* c2);
public:
    void printCard();
    string getCardDisplay();
    int getCardValue();
protected:
    string suit;
    int value;
};






#endif //UNTITLED_CARD_H
