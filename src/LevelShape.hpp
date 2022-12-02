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
    LevelShape(sf::Vector2f, sf::Vector2f, sf::Color, bool, bool, int, int, sf::Texture*, int);

    // Property get utils.
    int getLevel() {return level;}
    int getStage() {return stage;}

    // Property set utils.
    void setTexture(sf::Texture *tex) {shape.setTexture(tex);}
    void setLevel(int lvl) {level = lvl;}
    void setStage(int stg) {stage = stg;}
};

#endif
