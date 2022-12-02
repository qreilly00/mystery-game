#include "../TextEntity.hpp"

void TextEntity::drawText(sf::RenderWindow& window) {
    text.setFont(font);
    window.draw(text);
}
