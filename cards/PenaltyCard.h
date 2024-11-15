#ifndef PenaltyCard_H   
#define PenaltyCard_H
#include "Card.h"

class PenaltyCard : public Card
{
private:
int deductionPoints;

public:
    PenaltyCard();
    PenaltyCard(int num , int points);
    ~PenaltyCard();
    int getdeductionPoints();
    void setDeductionPoints(int points);
    int getDeductionPoints();
};



#endif 
