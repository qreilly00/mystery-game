#include "../MapUtils.hpp"

MapUtils::MapUtils() {
    tu.loadAllTextures();

    roomWallWidth = 8;

    CurrentObjectVar = 1;
    textureChanged = 1;

    objectVarNames.push_back("Object size");
    objectVarNames.push_back("Blank");
    objectVarNames.push_back("Blank");
    objectVarNames.push_back("Object forground status");
    objectVarNames.push_back("Object texture");
    objectVarNames.push_back("Object collidable status");
    objectVarNames.push_back("Object level");
    objectVarNames.push_back("Object stage");

    objectSize = sf::Vector2f(32, 32);
    objectPosition = sf::Vector2f(0, 0);
    objectColor = sf::Color::White;
    objectIsForGround = 0;
    CurrentTexture = 0;
    objectCollidable = 0;
    objectLevel = 1;
    objectStage = 1;

    isObjectFarm = 0;

    l = LevelShape(objectSize, sf::Vector2f(0, 0), sf::Color::White, objectCollidable, objectIsForGround, objectLevel, objectStage, &tu.getTextures()[CurrentTexture], CurrentTexture);
}
