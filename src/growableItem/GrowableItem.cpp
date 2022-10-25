#include "../GrowableItem.hpp"

/*BasicShape::BasicShape() {
    // A basic property setup.
    shape.setSize(sf::Vector2f(32, 32));
    shape.setPosition(sf::Vector2f(0, 0));

    shape.setFillColor(sf::Color::White);

    isCollidable = 0;
    textureIndex = 0;
    isForGround = 0;
}*/

BasicShape::GrowableItem(sf::Vector2f size, sf::Vector2f position, sf::Color clr, bool isCol, std::vector<int> idx) {
    // A basic property setup, tailored for a specific purpose.
    shape.setSize(size);
    shape.setPosition(position);

    shape.setFillColor(clr);

    isCollidable = isCol;
    isForGround = 0;

    type = BLUE_FLOWER;

    stageTextureIndexes = idx;
    textureIndex = idx[0];

    numberOfStages = 4;
    timeOfStages = 4;
}
