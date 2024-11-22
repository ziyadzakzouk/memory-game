#include "BonusCard.h"

BonusCard::BonusCard() {
    bonusPoints = 0;
}

BonusCard::BonusCard(int num,int point, int bonusPoints) : Card(num,point+bonusPoints) {
this-> bonusPoints=bonusPoints;
}

BonusCard::~BonusCard() {
    
}

int BonusCard::getBonusPoints(){
    return bonusPoints;
}

void BonusCard::setBonusPoints(int point){
    bonusPoints = point;
}

