//
// Created by ya168 on 1/13/2025.
//

#ifndef CPP_GAME_GAMEGUI_H
#define CPP_GAME_GAMEGUI_H
#pragma once
#include <SFML/Graphics.hpp>
#include "DeckGUI.h"
#include "../game/Game.h"

class GameGUI {
public:
    GameGUI(Game* game, float startX, float startY);
    void draw(sf::RenderWindow& window);
    void update();

private:
    Game* game;
    DeckGUI deckGUI;
    sf::Text player1Text;
    sf::Text player2Text;
    sf::Font font;
};
#endif //CPP_GAME_GAMEGUI_H
