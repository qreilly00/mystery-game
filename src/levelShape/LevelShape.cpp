#include "../LevelShape.hpp"

LevelShape::LevelShape() {
    // A basic property setup.
    shape.setSize(sf::Vector2f(32, 32));
    shape.setPosition(sf::Vector2f(0, 0));

    shape.setFillColor(sf::Color::White);

    isCollidable = 0;
    textureIndex = 0;
    isForGround = 0;

    level = 0;
    stage = 0;
}

LevelShape::LevelShape(sf::Vector2f size, sf::Vector2f position, sf::Color clr, bool isCol, int lvl, int stg) {
    // A basic property setup, tailored for a specific purpose.
    shape.setSize(size);
    shape.setPosition(position);

    shape.setFillColor(clr);

    isCollidable = isCol;
    textureIndex = -1;
    isForGround = 0;

    level = lvl;
    stage = stg;
}

LevelShape::LevelShape(sf::Vector2f size, sf::Vector2f position, sf::Color clr, bool isCol, sf::Texture *tex, int idx, int lvl, int stg, bool isFG) {
    // A basic property setup, tailored for a specific purpose.
    shape.setSize(size);
    shape.setPosition(position);

    shape.setFillColor(clr);
    shape.setTexture(tex);

    isCollidable = isCol;
    textureIndex = idx;
    isForGround = isFG;

    level = lvl;
    stage = stg;
}
