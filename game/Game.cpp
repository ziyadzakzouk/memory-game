#include "Game.h"

Game::Game(){
    player1 = new Player;
    player2 = new Player;
    deck = new Deck;
}

Game::Game(Deck* deck,Player* player1,Player* player2){
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
    deck->shuffle();
    deck->displayGrid();
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