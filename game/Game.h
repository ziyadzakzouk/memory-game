#ifndef Game_h
#define Game_h
#include "..\deck\Deck.h"
#include "..\player\Player.h"


class Game 
{
    private:
    Deck* deck;
    Player* player1;
    Player* player2;

public:
    Game();
    Game(Deck* deck, Player* player1, Player* player2);
    ~Game();
    void initializeGame();
    void setDeck(Deck* deck);
    Deck* getDeck();
    void setPlayer1(Player* player1);
    void setPlayer2(Player* player2);
    Player* getPlayer1();
    Player* getPlayer2();
    void PlayerTurn(Player* player,bool flag); //detects the player's turn
    void handleCards(Player* player,Card* card1, Card* card2); //handles the cards
    bool allCardsFlipped();
    void EndGame(); //displays the winner
    void handleBounsCard(Player* player,Card* card1,Card* card2); //handles the bonus card
    void revealAllCards();


};



#endif 
