#include "../MapUtils.hpp"

sf::RectangleShape MapUtils::buildPointer(sf::Vector2f mousePos) {
    l.getShape().setSize(objectSize);
    l.getShape().setPosition(sf::Vector2f(int(mousePos.x) - (int(mousePos.x) % 32), int(mousePos.y) - (int(mousePos.y) % 32)));
    if(textureChanged == 1) {l.setTexture(&tu.getTextures()[CurrentTexture]); textureChanged = 0;}

    return l.getShape();
}
