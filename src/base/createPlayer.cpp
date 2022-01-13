#include "../Base.hpp"

void Base::createPlayer() {
    player.getShape().setSize(sf::Vector2f(32, 32));
    player.getShape().setPosition(sf::Vector2f(0, 0));
    player.getShape().setFillColor(sf::Color::Black);
    //player.setSpeed(1000);
}
