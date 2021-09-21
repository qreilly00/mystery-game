#include "../Base.hpp"

void Base::updatePlayerBorders() {
    // Update left, right, top and Bottom border.
    playerBorders[0] = (sf::FloatRect(
        player.getShape().getPosition().x - 1,
        player.getShape().getPosition().y,
        1,
        player.getShape().getSize().y
    ));
    playerBorders[1] = (sf::FloatRect(
        player.getShape().getPosition().x + player.getShape().getSize().x,
        player.getShape().getPosition().y,
        1,
        player.getShape().getSize().y
    ));
    playerBorders[2] = (sf::FloatRect(
        player.getShape().getPosition().x,
        player.getShape().getPosition().y - 1,
        player.getShape().getSize().y,
        1
    ));
    playerBorders[3] = (sf::FloatRect(
        player.getShape().getPosition().x,
        player.getShape().getPosition().y + player.getShape().getSize().y,
        player.getShape().getSize().y,
        1
    ));
}
