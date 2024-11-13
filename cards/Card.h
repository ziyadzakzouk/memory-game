#ifndef _CARD_
#define _CARD_


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