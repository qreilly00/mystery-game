#include "../Base.hpp"

void Base::createPlayer() {
    player.getShape().setSize(sf::Vector2f(64, 64));
    player.getShape().setPosition(sf::Vector2f(64, 32));
    player.getShape().setFillColor(sf::Color::Blue);
}
