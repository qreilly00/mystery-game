#include "../Entity.hpp"

Entity::Entity() {
    // A basic property setup.
    shape.setSize(sf::Vector2f(32, 32));
    shape.setPosition(sf::Vector2f(0, 0));

    shape.setFillColor(sf::Color::White);

    isCollidable = 0;

    speed = 100;
    speedMultiplier = 1;
}

Entity::Entity(sf::Vector2f size, sf::Vector2f position, sf::Color clr, bool isCol, float spd, float spdMlt) {
    // A basic property setup, tailored for a specific purpose.
    shape.setSize(size);
    shape.setPosition(position);

    shape.setFillColor(clr);

    isCollidable = isCol;

    speed = spd;
    speedMultiplier = spdMlt;
}
