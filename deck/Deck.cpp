#include "Deck.h"
#include <ctime>
#include <random>
#include <iostream>
using namespace std;

Deck::Deck(){
cards = new Card*[4];
for (int i = 0; i < 4; i++)
{
    cards[i] = new Card[4];
}

}
//------------NOT SURE ABOUT THIS -----------------------------------------------------------------
Deck::Deck(Card** deck) {

for (int i = 0; i < 4; i++)
{
    for (int j = 0; j < 4; j++)
    {
        cards[i][j] = deck[i][j];
    } 
}

}
//-------------------------------------------------------------------------------------
Deck::~Deck(){
for (int i = 0; i < 4; i++){
        delete[] cards[i];
}
}

void Deck::shuffle(){
srand ((unsigned int) time(0));
for (int i = 0; i < 4; i++)
{
    for (int j = 0; j < 4; j++)
    {
        int randRow = rand() % 4;
        int randCol = rand() % 4;

        Card temp = cards[randRow][randCol];
        cards[randRow][randCol] = cards[i][j];
        cards[i][j] = temp;
       
    }
    
    
}

}

void Deck::displayGrid(){
    for (int i = 0; i < 4; i++)
{
    for (int j = 0; j < 4; j++)
    {
      
        cards[i][j].display();
       
    }
    cout << endl;
    
    
}
}