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
    LevelShape(sf::Vector2f size, sf::Vector2f position, sf::Color clr, bool isCol, sf::Texture *tex, int idx, int lvl, int stg);

    // Property get utils.
    int getLevel();
    int getStage();

    // Property set utils.
    void setTexture(sf::Texture *tex);
    void setLevel(int);
    void setStage(int);
};

#endif
