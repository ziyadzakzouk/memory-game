#include "Game.h"
#include "..\deck\Deck.h"
#include "..\player\Player.h"
#include "..\cards\Card.h"
#include "..\cards\BonusCard.h"
#include "..\cards\PenaltyCard.h"
#include "..\cards\StandardCard.h"
#include <ctime>
#include <random>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

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
void Card::reveal(){
    flipped = true;
}
void Card::hide(){
    flipped = false;
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
    for (int i = 0; i < 7; ++i) {
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

Card** Deck::getCards(){
    return cards;
}
void Deck::setCards(Card** cards){
        this->cards = cards;
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
    cout << "Score: " << score;
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
    string x;
    string y;
    cout<<"enter player 1 name: ";cin>>x;
    player1->setName(x);
    cout<<"enter player 2 name: ";cin>>y;
    player2->setName(y);
    cout << "Welcome to Memory Game " << endl;
    cout<<"Instructions: \n";
    cout<<"1. The game consists of 16 cards, 8 pairs of cards.\n";
    cout<<"2. Each card has a number from 0 to 7.\n";
    cout<<"3. The player with the highest score wins the game.\n";
    cout<<"4. If the two cards have the same number, the player gets 1 point.\n";
    cout<<"5. If the two cards have different numbers, the player loses 1 point.\n";
    cout<<"6. If the two cards are bonus cards, the player gets 2 points or get 1 point with 2 rounds it depends on your choice.\n";
    cout<<"7. If the two cards are penalty cards, the player loses 2 points or lose 1 point and skip a round it depends on your choice.\n";
    cout<<"8. If one card is a bonus card and the other is a standard card, the player gets 1 point.\n";
    cout<<"9. If one card is a penalty card and the other is a standard card, the player loses 1 point.\n";
    cout<<"10. If one card is a bonus card and the other is a penalty card, the cards are removed from the grid.\n";
    cout<<"you will choose from x and y coordinates to flip the card and match the pairs .\n";
    cout<<"Note x and y will be zero to get the first element in row and column\n";
    cout<<"Note x and y will be 3 to get the last element in row and column\n";
    cout << "DING DING DING Let the Game Begins " << endl;
    deck->shuffle();
    deck->displayGrid();
    player1->setScore(0);
    player2->setScore(0);
    cout << "Player 1: " << player1->getName() << "-----------------VS------------------" << "Player 2: " << player2->getName() << endl;
    player1->displayScore(); cout<< "___________________________________________________" ; player2->displayScore();
    cout<<endl;

// Start the game loop
    while (!allCardsFlipped()) {
        PlayerTurn(player1);
        if (allCardsFlipped()) break;
        PlayerTurn(player2);
    }
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
bool Game::allCardsFlipped() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (deck->getCards()[i][j].isFlipped()== false) {
                return false;
            }
        }
    }
    return true;
}
void Game::PlayerTurn(Player *player) {
    int x1, y1, x2, y2;
    // First card selection
    do {
        cout << player->getName() << "'s turn. Enter coordinates of the first card (row (X) and column (Y) ): ";
        cin >> x1 >> y1;
        if (deck->getCards()[x1][y1].isFlipped()) {
            cout << "Card already flipped. Choose another card." << endl;
        }
    } while (deck->getCards()[x1][y1].isFlipped());
    deck->getCards()[x1][y1].reveal();  //reveal the card
    deck->displayGrid();
    // First card selection
    do {
        cout << player->getName() << "'s turn. Enter coordinates of the Second card (row (X) and column (Y) ): ";
        cin >> x2 >> y2;
        if (deck->getCards()[x2][y2].isFlipped()) {
            cout << "Card already flipped. Choose another card." << endl;
        }
    } while (deck->getCards()[x2][y2].isFlipped());
    deck->getCards()[x2][y2].reveal();  //reveal
    deck->displayGrid();
    handleCards(player, &deck->getCards()[x1][y1], &deck->getCards()[x2][y2]);
    if(allCardsFlipped()){
        EndGame();
    }
    else{
        if(player == player1){
            PlayerTurn(player2);
        }
        else{
            PlayerTurn(player1);
        }
    }

}

void Game::handleCards(Player* player, Card* card1, Card* card2) {
    if (card1->getNumber() == 7 && card2->getNumber() == 7) { //both are bonus cards

        int tmp;
        cout << "DING DING DING!!! both cards are Bonus Cards. Choose an option:\n";
        cout << "1. Gain +2 points\n";
        cout << "2. Gain +1 point and take another turn\n";
        cin >> tmp;
        if (tmp == 1) { //manner choice
            player->setScore(player->getScore() + 2);
        } else {
            player->setScore(player->getScore() + 1);
            if(player == player1){
                PlayerTurn(player1);
            }
            else{
                PlayerTurn(player2);
            }
        }
        card1->setNumber(-1);
        card2->setNumber(-1);
    } else if (card1->getNumber() == 8 && card2->getNumber() == 8) { //both are penalty cards

        int tmp;
        cout << "OH NO !!  both cards are penalty cards. choose an option:\n";
        cout << "1- Lose 2 points\n";
        cout << "2- Lose 1 point and skip the next turn\n";
        cin >> tmp;
        if (tmp == 1) {
            player->setScore(player->getScore() - 2);
        } else {
            player->setScore(player->getScore() - 1);

            if(player == player1){
                PlayerTurn(player2);
            }
            else{
                PlayerTurn(player1);
            }
        }
        card1->setNumber(-1);
        card2->setNumber(-1);
    } else if ((card1->getNumber() == 7 && card2->getNumber() != 8) || (card2->getNumber() == 7 && card1->getNumber() != 8)) { //one is bonus card and the other is standard card

        player->setScore(player->getScore() + 1);
        if (card1->getNumber() == 7) {
            card1->setNumber(-1);
            card2->hide();
        } else {
            card2->setNumber(-1);
            card1->hide();
        }
    } else if ((card1->getNumber() == 8 && card2->getNumber() != 7) || (card2->getNumber() == 8 && card1->getNumber() != 7)) {
        // one card is a penalty card and the other is a standard card
        player->setScore(player->getScore() - 1);
        if (card1->getNumber() == 8) {
            card1->setNumber(-1);
            card2->hide();
        } else {
            card2->setNumber(-1);
            card1->hide();
        }
    } else if ((card1->getNumber() == 7 && card2->getNumber() == 8) || (card2->getNumber() == 7 && card1->getNumber() == 8)) {
        // one card is a bonus card and the other is a penalty card
        card1->setNumber(-1);
        card2->setNumber(-1);
    } else if (card1->getNumber() == card2->getNumber()) {
       //both cards are standard cards and have the same number
        player->setScore(player->getScore() + 1);
        card1->setNumber(-1);
        card2->setNumber(-1);
        if(player == player1){
            PlayerTurn(player1);
        }
        else{
            PlayerTurn(player2);
        }
    } else {

        card1->hide();
        card2->hide();
        if (player == player1) {
            PlayerTurn(player2);
        } else {
            PlayerTurn(player1);
        }
    }
    player->displayScore();
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
void Game::EndGame() {
    cout << "Game Over!\n";
    if (player1->getScore() > player2->getScore()) {
        cout << "Winner: " << player1->getName() << endl;
        cout << "Score: " << player1->getScore() << "Loser Score: " << player2->getScore() << endl;
    }
    else if (player1->getScore() < player2->getScore()) {
        cout << "Winner: " << player2->getName() << endl;
        cout << "Score: " << player2->getScore() << "Loser Score: " << player1->getScore() << endl;
    }
    else {
        cout << "It's a tie!\n";
    }
}

int main() {
    Game game;
    game.initializeGame();

    return 0;
}