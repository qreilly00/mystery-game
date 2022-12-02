#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../inc/common.hpp"

#include "BasicUtils.hpp"
#include "BasicShape.hpp"
#include "LevelShape.hpp"

class Entity : public BasicShape {
private:
    int speed;
    int speedMultiplier;

    std::vector<sf::FloatRect> playerBorders;
public:
    // Init class.
    Entity();
    Entity(sf::Vector2f, sf::Vector2f, sf::Color, int, sf::Texture *, int);

    // Movement.
    void checkMoves(std::vector<LevelShape>&, sf::Vector2f, int);
    void updatePlayerBorders();

    // Property get utils.
    float getSpeed() {return speed;}
    float getSpeedMultiplier() {return speedMultiplier;}

    // Property set utils.
    void setSpeed(float spd) {speed = spd;}
    void setSpeedMultiplier(float spdMlt) {speedMultiplier = spdMlt;}
    void setTexture(sf::Texture *tex, int textureIDX) {shape.setTexture(tex); textureIndex = textureIDX;}
};

#endif
