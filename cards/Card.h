#ifndef CARD_H
#define CARD_H


class Card
{
    int number;
    int points;
    bool flipped;
public:
    Card();
    ~Card();
    void display();
};

#endif