#ifndef StandardCard_H
#define StandardCard_H
#include "Card.h"

class StandardCard : public Card
{

public:
    StandardCard();

    StandardCard(int num , int points);
    ~StandardCard();
};



#endif 
