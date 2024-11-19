#include "PenaltyCard.h"

PenaltyCard::PenaltyCard() {
    int deductionpoints = 0;
}

PenaltyCard::PenaltyCard(int num , int points, int deductionPoints) : Card(num, points - deductionPoints) {
    this-> deductionPoints=deductionPoints;
}

PenaltyCard::~PenaltyCard() {
    
}
void PenaltyCard::setDeductionPoints(int points){
    deductionPoints = points;
}
int PenaltyCard::getDeductionPoints(){
    return deductionPoints;
}

