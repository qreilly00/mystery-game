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
    BasicShape(sf::Vector2f, sf::Vector2f, sf::Color, bool, bool, int);

    // Property get utils.
    sf::RectangleShape& getShape() {return shape;}

    bool getIsCollidable() {return isCollidable;}
    bool getIsForGround() {return isForGround;}

    int getTextureIndex()  {return textureIndex;}
};

#endif
