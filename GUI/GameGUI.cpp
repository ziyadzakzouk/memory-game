#include "GameGUI.h"

GameGUI::GameGUI(Game* game, float startX, float startY)
        : game(game), deckGUI(game->getDeck(), startX, startY) {
    if (!font.loadFromFile("path/to/font.ttf")) {
        // Handle error
    }

    player1Text.setFont(font);
    player1Text.setCharacterSize(24);
    player1Text.setFillColor(sf::Color::White);
    player1Text.setPosition(startX, startY - 50);

    player2Text.setFont(font);
    player2Text.setCharacterSize(24);
    player2Text.setFillColor(sf::Color::White);
    player2Text.setPosition(startX + 300, startY - 50);
}

void GameGUI::draw(sf::RenderWindow& window) {
    deckGUI.draw(window);

    player1Text.setString(game->getPlayer1()->getName() + ": " + std::to_string(game->getPlayer1()->getScore()));
    player2Text.setString(game->getPlayer2()->getName() + ": " + std::to_string(game->getPlayer2()->getScore()));

    window.draw(player1Text);
    window.draw(player2Text);
}

void GameGUI::update() {
    deckGUI.update();
}