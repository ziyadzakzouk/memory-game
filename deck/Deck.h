#ifndef Deck_H
#define Deck_H
#include "..\cards\Card.h"

class Deck 
{
 private:   
 Card** cards;
public:
    Deck();
    ~Deck();
    Deck(Card** deck);
    void shuffle();
    void displayGrid();
};



#endif 
