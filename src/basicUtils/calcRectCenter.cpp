#include "../BasicUtils.hpp"

sf::Vector2f BasicUtils::calcRectCenter(sf::RectangleShape rect) {
    return sf::Vector2f(rect.getPosition().x + (rect.getSize().x / 2), rect.getPosition().y + (rect.getSize().y / 2));
}
