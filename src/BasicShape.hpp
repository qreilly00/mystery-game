#ifndef BASICSHAPE_HPP
#define BASICSHAPE_HPP

#include "../inc/common.hpp"

class BasicShape {
protected:
    sf::RectangleShape shape;

    bool isCollidable;
    bool isForGround;
    int textureIndex;
public:
    // Init class.
    BasicShape();
    BasicShape(sf::Vector2f, sf::Vector2f, sf::Color, bool, int, bool);

    // Get and set util for all shape properties.
    sf::RectangleShape& getShape();
    bool getIsCollidable();
    bool getIsForGround();
    int getTextureIndex();
};

#endif
