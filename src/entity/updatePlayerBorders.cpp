#include "../Entity.hpp"

void Entity::updatePlayerBorders() {
    // Update left, right, top and Bottom border.
    playerBorders[0] = (sf::FloatRect(
        getShape().getPosition().x - 1,
        getShape().getPosition().y,
        1,
        getShape().getSize().y
    ));
    playerBorders[1] = (sf::FloatRect(
        getShape().getPosition().x + getShape().getSize().x,
        getShape().getPosition().y,
        1,
        getShape().getSize().y
    ));
    playerBorders[2] = (sf::FloatRect(
        getShape().getPosition().x,
        getShape().getPosition().y - 1,
        getShape().getSize().y,
        1
    ));
    playerBorders[3] = (sf::FloatRect(
        getShape().getPosition().x,
        getShape().getPosition().y + getShape().getSize().y,
        getShape().getSize().y,
        1
    ));
}
