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
    Player(string n, int score);
    ~Player();
    void displayScore();
    int getScore();
    void setScore(int score);
    void setName(string name);
    string getName();
};



#endif 
