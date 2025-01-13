#include "DeckGUI.h"

DeckGUI::DeckGUI(Deck* deck, float startX, float startY) : deck(deck), startX(startX), startY(startY) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cardGUIs.emplace_back(&deck->getCards()[i][j], startX + j * 110, startY + i * 160);
        }
    }
}

void DeckGUI::draw(sf::RenderWindow& window) {
    for (auto& cardGUI : cardGUIs) {
        cardGUI.draw(window);
    }
}

void DeckGUI::update() {
    // Update logic if needed
}