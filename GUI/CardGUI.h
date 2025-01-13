
#ifndef CPP_GAME_CARDGUI_H
#define CPP_GAME_CARDGUI_H
#pragma once
#include <SFML/Graphics.hpp>
#include "../cards/Card.h"

class CardGUI {
public:
    CardGUI(Card* card, float x, float y);
    void draw(sf::RenderWindow& window);
    void flip();
    bool isFlipped() const;

private:
    Card* card;
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;
    bool flipped;
};
#endif //CPP_GAME_CARDGUI_H
