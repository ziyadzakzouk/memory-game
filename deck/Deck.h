#ifndef _Deck_
#define _Deck_
#include "cards/Card.h"

class Deck 
{
 public:   
 Card cards[4][4];
public:
    Deck();
    void shuffle();
    void displayGrid();
};



#endif 
