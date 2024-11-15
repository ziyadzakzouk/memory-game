#ifndef Player_H
#define Player_H
#include <string>
using namespace std;

class Player 
{
string name;
int score;
public:
    Player();
    ~Player();
    void displayScore();
};



#endif 
