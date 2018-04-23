#include "Deck.h"
#include <ostream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

bool hasPair(const vector<Card> &a)
{
    bool b = false;
    int one = 0;
    int two = 0;
    int three = 0;
    int four = 0;
    int five = 0;
    int six = 0;
    int seven = 0;
    int eight = 0;
    int nine = 0;
    int ten = 0;
    int eleven = 0;
    int twelve = 0;
    int thirteen = 0;
    for(unsigned int i = 0; i < a.size(); i++)
    {
        int cardRank = a.at(i).getRank();
        if(cardRank == 1)
        {
            one++;
        }
        if(cardRank == 2)
        {
            two++;
        }
        if(cardRank == 3)
        {
            three++;
        }
        if(cardRank == 4)
        {
            four++;
        }
        if(cardRank == 5)
        {
            five++;
        }
        if(cardRank == 6)
        {
            six++;
        }
        if(cardRank == 7)
        {
            seven++;
        }
        if(cardRank == 8)
        {
            eight++;
        }
        if(cardRank == 9)
        {
            nine++;
        }
        if(cardRank == 10)
        {
            ten++;
        }
        if(cardRank == 11)
        {
            eleven++;
        }
        if(cardRank == 12)
        {
            twelve++;
        }
        if(cardRank == 13)
        {
            thirteen++;
        }
    }
    if(one > 1 || two > 1 || three > 1 || four > 1 || five > 1 || six > 1 || seven > 1 || eight > 1 || nine > 1 || ten > 1 || eleven > 1 || twelve > 1 || thirteen> 1)
    {
        b = true;
    }
    return b;
}

ostream & operator<<(ostream &out, const vector<Card> &c)
{
    for(unsigned int i = 0; i < c.size(); i++)
    {
        operator << (out, c.at(i));
    }        
    return out;
}

int main()
{

srand(2222);
/* Passes in a vector Cards and returns true if any 2 Cards have the same rank.
   Otherwise returns false.
*/
bool hasPair(const vector<Card> &a);


/* Passes in a vector of Cards and outputs to the stream each Card
   separated by a comma and a space, 
   with no comma, space, or newline at the end.
*/
ostream & operator<<(ostream &o, const vector<Card> &c);

string file;
string fileName;
ofstream c9mang0;
bool mangoat = false;
int cph = 0;
int deals = 0;
double chance = 0.0;
double chanceP = 0.0;
cout << "Do you want to output all hands to a file?(Yes/No?) ";
cin >> file;
cout << endl << endl;
if(file == "Yes")
{
    cout << "Enter name of output file: ";
    cin >> fileName;
    cout << endl << endl;
    c9mang0.open(fileName.c_str());
    mangoat = true;
}
cout << "Enter number of cards per hand: ";
cin >> cph;
cout << endl << endl;
cout << "Enter number of deals (simulations): ";
cin >> deals;
cout << endl << endl;
Deck tempDeck;
for(int i = 0; i < deals; i++)
{
    vector<Card> tempDeck2;
    for(int j = 0; j < cph; j++)
    {
        Card temp;
        temp = tempDeck.dealCard();
        tempDeck2.push_back(temp);
    }
    bool hP = hasPair(tempDeck2);
    if(hP)
    {
        if(mangoat)
        {
            c9mang0 << "Found Pair!! ";
        }
        chance = chance + 1;
    }
    else
    {
        if(mangoat)
        {
            c9mang0 << "             ";
        }
    }
    if(mangoat)
        {
            operator <<(c9mang0, tempDeck2);
            c9mang0 << endl;
        }
    tempDeck.shuffleDeck();
}
chanceP = chance/deals * 100;
cout << "Chances of receiving a pair in a hand of 5 cards is: " << chanceP << "%" << endl;


return 0;
    
} 