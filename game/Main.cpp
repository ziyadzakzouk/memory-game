#include "Game.h"
#include "..\deck\Deck.h"
#include "..\player\Player.h"
#include "..\cards\Card.h"
#include "..\cards\BonusCard.h"
#include "..\cards\PenaltyCard.h"
#include "..\cards\StandardCard.h"

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
    if(flipped){
    cout<<number;

    }
    else
    cout<<"*";

}

int Card::getNumber(){
    return number;
}

void Card::setNumber(int num){
    number=num;
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

StandardCard::StandardCard() {   
}

StandardCard::StandardCard(int num , int points) : Card(num, points){

}

StandardCard::~StandardCard() {
    
}

#include <ctime>
#include <random>
#include <iostream>
#include <algorithm>

using namespace std;

Deck::Deck(){
cards = new Card*[4];
for (int i = 0; i < 4; i++)
{
    cards[i] = new Card[4];
}

}

Deck::Deck(Card** deck) {

for (int i = 0; i < 4; i++)
{
    for (int j = 0; j < 4; j++)
    {
        cards[i][j] = deck[i][j];
    } 
}

}

Deck::~Deck(){
for (int i = 0; i < 4; i++){
        delete[] cards[i];
}
delete[] cards;
}

void Deck::shuffle(){

    Card cardPairs[16];
    for (int i = 0; i < 8; ++i) {
        Card card;
        card.setNumber(i);
        cardPairs[2 * i] = card;
        cardPairs[2 * i + 1] = card;
    }
    random_device rd;
    mt19937 g(rd());
    std::shuffle(cardPairs, cardPairs + 16, g);
    int index = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cards[i][j] = cardPairs[index++];
        }
    }

}

void Deck::displayGrid(){
    for (int i = 0; i < 4; i++)
{
    for (int j = 0; j < 4; j++)
    {
      
        cards[i][j].display();
       
    }
    cout << endl;
}
}

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

Game::Game(){
    player1 = new Player;
    player2 = new Player;
    deck = new Deck;
}

Game::Game(Deck* deck, Player* player1, Player* player2){
    this->deck = deck;
    this->player1 = player1;
    this->player2 = player2;
}

Game::~Game(){
    delete player1;
    delete player2;
    delete deck;
}

void Game::initializeGame(){
    cout << "Welcome to Memory Game " << endl;
    cout << "Let the Game Begins DING DING DING" << endl;
    deck->shuffle();
    deck->displayGrid();
    player1->setName("Joe");
    player2->setName("Monafes");
    player1->setScore(0);
    player2->setScore(0);
    cout << "Player 1: " << player1->getName() << "-----------------VS------------------" << "Player 2: " << player2->getName() << endl;
    cout <<  player1->getScore() << "___________________________________________________" << player2->getScore() << endl;


}

void Game::setDeck(Deck* deck){
    this->deck = deck;
}

void Game::setPlayer1(Player* player){
    this->player1 = player1;
}

void Game::setPlayer2(Player* player){
    this->player2 = player2;
}

Deck* Game::getDeck(){
    return deck;
}

Player* Game::getPlayer1(){
    return player1;
}

Player* Game::getPlayer2(){
    return player2;
}

int main() {
    Game game;
    game.initializeGame();

    return 0;
}