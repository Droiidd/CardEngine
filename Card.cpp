#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "card.h"
using namespace std;

Card::Card(string suit, int value)
{
    this->suit = suit;
    this->value = value;
    const char* str_inp1 = "String Match";
}

Card::~Card()
{

}
int Card::valCmp(Card* c2)
{
    if (this->value == c2->value) {
        return 0;
    }
    else if (this->value > c2->value) {
        return 1;
    }
    else if (this->value < c2->value) {
        return -1;
    }
}
void Card::suitCmp(Card c2)
{
    if (this->suit != c2.suit)
    {
        //std::cout << this->printCard() << " is not equal to " << c2.printCard() << endl;
        cout << this->getCardDisplay() << " suit is NOT equal to " << c2.getCardDisplay() <<
             "\n" << endl;
    }
    else
        cout << this->getCardDisplay() << " suit is equal to " << c2.getCardDisplay()
             << "\n" << endl;
}
void Card::valEqTo(Card c2)
{
    if (this->value == c2.value) {
        cout << this->getCardDisplay()  << " value is equal to the "<<
             c2.getCardDisplay() << "\n"<<endl;
    }
    else
        cout << this->getCardDisplay() << " value is NOT equal to the " <<
             c2.getCardDisplay() << "\n" << endl;
}
void Card::valIsGreater(Card c2)
{
    if (this->value > c2.value) {
        cout << this->getCardDisplay() << " value is greater than the " <<
             c2.getCardDisplay() << "\n" << endl;
    }
    else
        cout << this->getCardDisplay() << " value is NOT greater than the " <<
             c2.getCardDisplay() << "\n" << endl;
}
void Card::valIsLess(Card c2)
{
    if (this->value < c2.value) {
        cout << this->getCardDisplay() << " value is less than the " <<
             c2.getCardDisplay() << "\n" << endl;
    }
    else
        cout << this->getCardDisplay() << " value is NOT less than the " <<
             c2.getCardDisplay() << "\n" << endl;
}



void Card::printCard()
{
    cout << this->getCardDisplay() << endl;
}

string Card::getCardDisplay()
{
    if (value != 11 && value != 12 && value != 13 && value != 14) {

        string valStr = to_string(value);
        string newString("["+valStr + " of " + this->suit+"]");
        return newString;
    }


    switch (value) {
        case 11:
        {
            string valStr2 = "Jack";
            string newString2("[" + valStr2 + " of " + this->suit + "]");
            return newString2;
            break;
        }
        case 12:
        {
            string valStr2 = "Queen";
            string newString2("[" + valStr2 + " of " + this->suit + "]");
            return newString2;
            break;
        }
        case 13:
        {
            string valStr2 = "King";
            string newString2("[" + valStr2 + " of " + this->suit + "]");
            return newString2;
            break;
        }
        case 14:
        {
            string valStr2 = "Ace";
            string newString2("[" + valStr2 + " of " + this->suit + "]");
            return newString2;
            break;
        }
    }


    return suit;
}
int Card::getCardValue()
{
    return this->value;

}