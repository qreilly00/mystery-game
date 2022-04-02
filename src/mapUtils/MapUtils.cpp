#include "../MapUtils.hpp"

MapUtils::MapUtils() {
    tu.loadAllTextures();

    l = LevelShape(objectSize, sf::Vector2f(0, 0), sf::Color::White, &tu.getTextures()[CurrentTexture], objectCollidable, objectLevel, objectStage);

    roomWallWidth = 8;

    CurrentObjectVar = 1;

    objectSize = sf::Vector2f(32, 32);
    objectPosition = sf::Vector2f(0, 0);
    objectColor = sf::Color::White;
    //objectTexture;
    objectCollidable = 0;
    objectLevel = 1;
    objectStage = 1;
}
