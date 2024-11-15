#include "deck/Deck.h"

Deck::Deck(){
cards = new Card*[4];
for (int i = 0; i < 4; i++)
{
    cards[i] = new Card[4];
}

}
Deck::~Deck(){


}

void Deck::shuffle(){

}

void Deck::displayGrid(){

}