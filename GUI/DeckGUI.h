//
// Created by ya168 on 1/13/2025.
//

#ifndef CPP_GAME_DECKGUI_H
#define CPP_GAME_DECKGUI_H
#pragma once
#include <SFML/Graphics.hpp>
#include "../deck/Deck.h"
#include "CardGUI.h"
#include <vector>

#pragma once
#include <SFML/Graphics.hpp>
#include "../deck/Deck.h"
#include "CardGUI.h"
#include <vector>

class DeckGUI {
public:
    DeckGUI(Deck* deck, float startX, float startY);
    void draw(sf::RenderWindow& window);
    void update();

private:
    Deck* deck;
    std::vector<CardGUI> cardGUIs;
    float startX;
    float startY;
};
#endif //CPP_GAME_DECKGUI_H
