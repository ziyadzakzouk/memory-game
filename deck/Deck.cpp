#include "Deck.h"
#include <ctime>
#include <random>
#include <iostream>
#include <algorithm>

using namespace std;

Deck::Deck(){
cards = new Card*[4];
for (int i = 0; i < 4; i++)
{
    cards[i] = new Card[4];
}

}

Deck::Deck(Card** deck) {

for (int i = 0; i < 4; i++)
{
    for (int j = 0; j < 4; j++)
    {
        cards[i][j] = deck[i][j];
    } 
}

}

Deck::~Deck(){
for (int i = 0; i < 4; i++){
        delete[] cards[i];
}
}

void Deck::shuffle(){

    Card cardPairs[16];
    for (int i = 0; i < 8; ++i) {
        Card card;
        card.setNumber(i);
        cardPairs[2 * i] = card;
        cardPairs[2 * i + 1] = card;
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cardPairs, cardPairs + 16, g);
    int index = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cards[i][j] = cardPairs[index++];
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