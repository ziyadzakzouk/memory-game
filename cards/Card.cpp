#include "Card.h"


Card::Card(){
    number = 0;
    flipped = false;
    points = 0;

}

Card::Card(int num, int points){
    number = num;
    flipped = false;
    this->points = points;
}
Card::~Card(){


}

void Card::display(){
    if(!flipped){
    cout<<number;
//    flipped!=flipped;
    }
    else
    cout<<"*";

}

int Card::getNumber(){
    return number;
}

void Card::setNumber(int num){
    if(num<1 || num>6){
        cout<<"number must be between 1 and 6";
    }else{
    number = num;
    }
}

void Card::Flip(){
    flipped = !flipped;
}

bool Card::isFlipped(){
    return flipped;
}

int Card::getPoints(){
    return points;
}

void Card::setPoints(int points){
    this->points = points;
}
void Card::setflipped(bool f){
    flipped=f;
}