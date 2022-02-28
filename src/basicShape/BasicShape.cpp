#include "../BasicShape.hpp"

BasicShape::BasicShape() {
    // A basic property setup.
    shape.setSize(sf::Vector2f(32, 32));
    shape.setPosition(sf::Vector2f(0, 0));

    shape.setFillColor(sf::Color::White);

    isCollidable = 0;
}

BasicShape::BasicShape(sf::Vector2f size, sf::Vector2f position, sf::Color clr, bool isCol) {
    // A basic property setup, tailored for a specific purpose.
    shape.setSize(size);
    shape.setPosition(position);

    shape.setFillColor(clr);

    isCollidable = isCol;
}
