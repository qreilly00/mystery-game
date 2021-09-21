#ifndef BASICSHAPE_HPP
#define BASICSHAPE_HPP

#include "../inc/common.hpp"

class BasicShape {
protected:
    sf::RectangleShape shape;
public:
    // Init class.
    BasicShape();
    BasicShape(sf::Vector2f, sf::Vector2f, float, float, sf::Color);

    // Get and set util for all shape properties.
    sf::RectangleShape& getShape();
};

#endif
