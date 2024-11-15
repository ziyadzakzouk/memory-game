#ifndef Deck_H
#define Deck_H
#include "cards/Card.h"

class Deck 
{
 public:   
 Card** cards;
public:
    Deck();
    void shuffle();
    void displayGrid();
};



#endif 
