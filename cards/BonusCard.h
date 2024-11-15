#ifndef BonusCard_H
#define BonusCard_H
#include "Card.h"

class BonusCard : public Card
{
    private:
    int bonusPoints;
public:
    BonusCard();
    BonusCard(int num,int point);
    ~BonusCard();
    void setBonusPoints(int points);
    int getBonusPoints();
    
};



#endif 
