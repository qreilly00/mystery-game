#include "../MapUtils.hpp"

MapUtils::MapUtils() {
    l = LevelShape(objectSize, sf::Vector2f(0, 0), objectColor, objectCollidable, objectLevel, objectStage);

    roomWallWidth = 8;

    CurrentObjectVar = 1;

    objectSize = sf::Vector2f(32, 32);
    objectPosition = sf::Vector2f(0, 0);
    objectColor = sf::Color::Black;
    //objectTexture;
    objectCollidable = 1;
    objectLevel = 1;
    objectStage = 1;
}
