#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
    name;
    score;
   
}

Player::Player(string name, int score) {
    this->name = name;
    this->score = score;
}

Player::~Player(){

}
void Player::setScore(int score){
    this->score = score;
}

int Player::getScore(){
    return score;
}
 
void Player::setName(string name){
    this->name = name;
}

string Player::getName(){
    return name;
}

void Player::displayScore(){
    cout << "Player Name: " << name << ", Score: " << score << endl;
}