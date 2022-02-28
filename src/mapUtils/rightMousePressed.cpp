#include "../MapUtils.hpp"

sf::Vector2f MapUtils::rightMousePressed(sf::Vector2f mousePos) {
    return sf::Vector2f(int(mousePos.x) - (int(mousePos.x) % 32), int(mousePos.y) - (int(mousePos.y) % 32));
}
