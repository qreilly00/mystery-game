#include "../Base.hpp"

void Base::createPlayer() {
    player.getShape().setSize(sf::Vector2f(258, 258));
    player.getShape().setPosition(sf::Vector2f(0, 0));
    player.getShape().setFillColor(sf::Color::Black);
    player.setSpeed(400);
    //player.setSpeed(1000);
}
