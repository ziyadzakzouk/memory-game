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
#include <thread>
//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
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
    cout<<number<<" ";

    }
    else
    cout<<"* ";

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
    for (int i = 1; i <= 8; ++i) {
        Card card;
        card.setNumber(i);
        cardPairs[2 * (i-1)] = card;
        cardPairs[2 * (i-1) + 1] = card;
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
    cout << "Score: " << score<<" ";
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
void Game::revealAllCards() {
    // Reveal all cards
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            deck->getCards()[i][j].reveal();
        }
    }
    deck->displayGrid();

    // Wait for any modified seconds
    this_thread::sleep_for(chrono::seconds(3));

    // Hide all cards
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            deck->getCards()[i][j].hide();
        }
    }
    for (int i = 0; i <5 ; ++i) {
        cout<<endl;
    }
    deck->displayGrid();
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
    cout<<"Note x and y will be 1 to get the first element in row and column\n";
    cout<<"Note x and y will be 4 to get the last element in row and column\n";
    cout << "DING DING DING Let the Game Begins " << endl;
    deck->shuffle();
    revealAllCards();
    player1->setScore(0);
    player2->setScore(0);
    cout << "Player 1: " << player1->getName() << "-----------------VS------------------" << "Player 2: " << player2->getName() << endl;
    player1->displayScore(); cout<< "___________________________________________________" ; player2->displayScore();
    cout<<endl;
    PlayerTurn(player1,true); 

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
    int count = 0;
    int specialcount = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (deck->getCards()[i][j].isFlipped()== true) {
                count++;
            }
            if(deck->getCards()[i][j].getNumber()==7 || deck->getCards()[i][j].getNumber()== 8)
            specialcount++;
        }
    }
    return count >= 15 && specialcount <= 0;
}
void Game::PlayerTurn(Player *player,bool flag) { 
    if (allCardsFlipped()) {
        EndGame();
    }
    int x1, y1, x2, y2;
    // First card selection
    cout << "score : "<< player->getScore()<<" "<< player->getName() << "'s turn. Enter coordinates of the first card (row (X) and column (Y) ): "; //add player scoreXXXX
    cin >> x1 >> y1;
    while (x1 < 1 || x1 > 4 || y1 < 1 || y1 > 4 || deck->getCards()[x1-1][y1-1].isFlipped()) {
        if (x1 < 1 || x1 > 4 || y1 < 1 || y1 > 4) {
            cout << "Coordinates out of bounds. Please enter valid coordinates." << endl;
        } else if (deck->getCards()[x1-1][y1-1].isFlipped()) {
            cout << "Card already flipped. Choose another card." << endl;
            
        }
        cout << "score : "<< player->getScore()<<" "<< player->getName() << "'s turn. Enter coordinates of the first card (row (X) and column (Y) ): ";
        cin >> x1 >> y1;
    }
    deck->getCards()[x1-1][y1-1].reveal();  // reveal the card
    deck->displayGrid();

    // Second card selection
    cout << "score : "<< player->getScore()<<" "<<player->getName() << "'s turn. Enter coordinates of the second card (row (X) and column (Y) ): ";
    cin >> x2 >> y2;
    while (x2 < 1 || x2 > 4 || y2 < 1 || y2 > 4 || deck->getCards()[x2-1][y2-1].isFlipped()) {
        if (x2 < 1 || x2 > 4 || y2 < 1 || y2 > 4) {
            cout << "Coordinates out of bounds. Please enter valid coordinates." << endl;
        } else if (deck->getCards()[x2-1][y2-1].isFlipped()) {
            cout << "Card already flipped. Choose another card." << endl;
            
        }
        cout << "score : "<< player->getScore()<<" "<<player->getName() << "'s turn. Enter coordinates of the second card (row (X) and column (Y) ): ";
        cin >> x2 >> y2;
    }
    
    deck->getCards()[x2-1][y2-1].reveal();  // reveal the card
    deck->displayGrid();
    

    handleCards(player, &deck->getCards()[x1-1][y1-1], &deck->getCards()[x2-1][y2-1]);
    
    
    
       if (player == player1 && flag) {
        
            PlayerTurn(player2,false);
        } else if (player == player2 && !flag) {
            
            PlayerTurn(player1,true);
        }
       
}

void Game::handleCards(Player* player, Card* card1, Card* card2) {
    // Handle normal cards
    if ((card1->getNumber() != 7 && card1->getNumber() != 8) && (card2->getNumber() != 7 && card2->getNumber() != 8)) {
        if (card1->getNumber() == card2->getNumber()) {
            card1->setNumber(-1);
            card2->setNumber(-1);
            player->setScore(player->getScore() + 1);
            if (player == player1) {
                
                PlayerTurn(player1,true);
            } else {
                
                PlayerTurn(player2,false);
            }
        } else
        {
            card1->hide();
            card2->hide();
        }
    }

    // Handle bonus cards
    if (card1->getNumber() == 7 && card2->getNumber() == 7) {
        int tmp;
        cout << "DING DING DING!!! both cards are Bonus Cards. Choose an option:\n";
        cout << "1. Gain +2 points\n";
        cout << "2. Gain +1 point and take another turn\n";
        cin >> tmp;

        if (tmp == 1) {
            cout << "Cards match! Adding 2 point to " << player->getName() << endl;
            card1->setNumber(-1);
            card2->setNumber(-1);
            player->setScore(player->getScore() + 2);
            cout << "Updated score: " << player->getScore() << endl;
        } else {
            
            player->setScore(player->getScore() + 1);
            
            if (player == player1) {
                card1->setNumber(-1);
                card2->setNumber(-1);
                if (allCardsFlipped())
                EndGame();
                PlayerTurn(player1,true);
            } else {
                card1->setNumber(-1);
                card2->setNumber(-1);
                if (allCardsFlipped())
                EndGame();
                PlayerTurn(player2,false);
            }
        }
        
    }

    // Handle penalty cards
    if (card1->getNumber() == 8 && card2->getNumber() == 8) {
        int tmp;
        cout << "OH NO !! both cards are penalty cards. choose an option:\n";
        cout << "1- Lose 2 points\n";
        cout << "2- Lose 1 point and skip the next turn\n";
        cin >> tmp;
        if (tmp == 1) {
            
            player->setScore(player->getScore() - 2);
            if(allCardsFlipped()){
                EndGame();
            }
        } else {

            player->setScore(player->getScore() - 1);
            if(allCardsFlipped()){
                EndGame();
            }
            else {
            if (player == player1) {
                 if(allCardsFlipped())
                EndGame();
                PlayerTurn(player2,true);
            } else {
                if (allCardsFlipped())
                EndGame();
                PlayerTurn(player1,false);
            }
        }
        }
        card1->setNumber(-1);
        card2->setNumber(-1);
    }

    // Handle mixed cards
    if ((card1->getNumber() == 7 && card2->getNumber() != 8) || (card2->getNumber() == 7 && card1->getNumber() != 8)) {
        player->setScore(player->getScore() + 1);
        if (card1->getNumber() == 7) {
            card1->setNumber(-1);
            card2->hide();
        } else {
            card2->setNumber(-1);
            card1->hide();
        }
    } else if ((card1->getNumber() == 8 && card2->getNumber() != 7) || (card2->getNumber() == 8 && card1->getNumber() != 7)) {
        player->setScore(player->getScore() - 1);
        if (card1->getNumber() == 8) {
            card1->setNumber(-1);
            card2->hide();
        } else {
            card2->setNumber(-1);
            card1->hide();
        }
    } else if ((card1->getNumber() == 7 && card2->getNumber() == 8) || (card2->getNumber() == 7 && card1->getNumber() == 8)) {
        card1->setNumber(-1);
        card2->setNumber(-1);
    }

    if(player == player1)
    player2->displayScore();
    else if(player == player2)
    player1->displayScore();
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
        cout << "Score: " << player2->getScore() << " Loser Score: " << player1->getScore() << endl;
    }
    else {
        cout << "It's a tie!\n"<<endl;
    }
    cout << "thank you for playing" << std::endl;
    exit(0);
}

int main() {
    Game game;
    game.initializeGame();

    return 0;
}