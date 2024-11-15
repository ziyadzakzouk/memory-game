#ifndef Player_H
#define Player_H
#include <string>
using namespace std;

class Player 
{
private:
string name;
int score;
public:
    Player();
    ~Player();
    void displayScore();
};



#endif 
