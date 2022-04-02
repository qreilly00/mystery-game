#include "../MapUtils.hpp"

LevelShape MapUtils::leftMousePressed(sf::Vector2f mousePos) {
    return LevelShape(objectSize, sf::Vector2f(int(mousePos.x) - (int(mousePos.x) % 32), int(mousePos.y) - (int(mousePos.y) % 32)), objectColor, &tu.getTextures()[CurrentTexture], objectCollidable, objectLevel, objectStage);
}
