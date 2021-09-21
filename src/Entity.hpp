#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../inc/common.hpp"
#include "BasicShape.hpp"


#include "BasicUtils.hpp"

class Entity : public BasicShape {
private:
    float speed;
    float speedMultiplier;
public:
    // Init class.
    Entity();
    Entity(sf::Vector2f size, sf::Vector2f position, float spd, float spdMlt, sf::Color clr);

    // Property get utils.
    float getSpeed();
    float getSpeedMultiplier();

    // Property set utils.
    void setSpeed(float);
    void setSpeedMultiplier(float);
};

#endif
