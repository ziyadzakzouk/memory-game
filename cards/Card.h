#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;

class Card
{
private:
    int number;
    int points;
    bool flipped; //true if number is visible
public:
    Card();
    Card(int num  , int points);
    ~Card();
    void display();
    int getNumber();
    int getPoints();
    bool isFlipped();
    void Flip();    //if its true make it false and vice versa
    void setNumber(int num);
    virtual void setPoints(int points);
    //added
    void setflipped(bool f);

    

};

#endif