#include "../LevelShape.hpp"

LevelShape::LevelShape() {
    // A basic property setup.
    shape.setSize(sf::Vector2f(32, 32));
    shape.setPosition(sf::Vector2f(0, 0));

    shape.setFillColor(sf::Color::White);

    isCollidable = 0;
    isForGround = 0;

    level = 0;
    stage = 0;

    textureIndex = 0;
}

LevelShape::LevelShape(sf::Vector2f size, sf::Vector2f position, sf::Color clr, bool isCol, int lvl, int stg) {
    // A basic property setup, tailored for a specific purpose.
    shape.setSize(size);
    shape.setPosition(position);

    shape.setFillColor(clr);

    isCollidable = isCol;
    isForGround = 0;

    level = lvl;
    stage = stg;

    textureIndex = -1;
}

LevelShape::LevelShape(sf::Vector2f size, sf::Vector2f position, sf::Color clr, bool isCol, bool isFG, int lvl, int stg, sf::Texture *tex, int idx) {
    // A basic property setup, tailored for a specific purpose.
    shape.setSize(size);
    shape.setPosition(position);

    shape.setFillColor(clr);
    shape.setTexture(tex);

    isCollidable = isCol;
    isForGround = isFG;

    level = lvl;
    stage = stg;

    textureIndex = idx;
}
