#ifndef LEVELSHAPE_HPP
#define LEVELSHAPE_HPP

#include "../inc/common.hpp"
#include "BasicShape.hpp"


#include "BasicUtils.hpp"

class LevelShape : public BasicShape {
private:
    int level;
    int stage;
public:
    // Init class.
    LevelShape();
    LevelShape(sf::Vector2f, sf::Vector2f, sf::Color, bool, int, int);

    // Property get utils.
    int getLevel();
    int getStage();

    // Property set utils.
    void setLevel(int);
    void setStage(int);
};

#endif
