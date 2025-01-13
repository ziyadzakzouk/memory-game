#include "CardGUI.h"

CardGUI::CardGUI(Card* card, float x, float y) : card(card), flipped(false) {
    shape.setSize(sf::Vector2f(100, 150));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Green);

    if (!font.loadFromFile("path/to/font.ttf")) {
        // Handle error
    }

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(x + 35, y + 60);
}

void CardGUI::draw(sf::RenderWindow& window) {
    window.draw(shape);
    if (flipped) {
        text.setString(std::to_string(card->getNumber()));
        window.draw(text);
    }
}

void CardGUI::flip() {
    flipped = !flipped;
}

bool CardGUI::isFlipped() const {
    return flipped;
}