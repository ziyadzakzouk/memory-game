#include "Game.h"

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