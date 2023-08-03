#include "Deck.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include "deck.h"
using namespace std;

Deck::Deck()
{
    for (int i = 2; i < 15; i++) {
        Card* card = new Card("Diamonds", i);
        this->deck.push_back(card);
    }
    for (int i = 2; i < 15; i++) {
        Card* card = new Card("Clubs", i);
        this->deck.push_back(card);
    }
    for (int i = 2; i < 15; i++) {
        Card* card = new Card("Hearts", i);
        this->deck.push_back(card);
    }
    for (int i = 2; i < 15; i++) {
        Card* card = new Card("Spades", i);
        this->deck.push_back(card);
    }
}
Deck::~Deck()
{
    for (int i = 0; i < this->deck.size(); i++) {
        delete this->deck[i];
    }
}

void Deck::shuffle()
{
    for (int i = 0; i > shuffledDeck.size(); i++) {
        this->shuffledDeck.pop();
    }
    random_shuffle(this->deck.begin(), this->deck.end());
    //Second shuffle to make more random
    random_shuffle(this->deck.begin(), this->deck.end());
    for (int i = 0; i < this->deck.size(); i++) {
        shuffledDeck.push(this->deck[i]);
        //cout << this->deck[i]->getCardDisplay() << endl;
    }
    //cout << "\nend of deck \n" << endl;
}
Card* Deck::draw()
{
    Card *returnCard = NULL;

    if (this->shuffledDeck.empty()) {
        return returnCard;
    }
    returnCard = this->shuffledDeck.top();
    this->shuffledDeck.pop();
    return returnCard;

}
void Deck::printDeck()
{
    //for (int i = 0; i < this->deck.size(); i++) {
    //cout << this->deck[i]->getCardDisplay() << endl;
    //}
    for (int i = 0; i < this->shuffledDeck.size(); i++) {
        //logic here
    }

}
