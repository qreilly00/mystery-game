#include "../FarmablePlot.hpp"

/*BasicShape::FarmablePlot() {
    // A basic property setup.
    shape.setSize(sf::Vector2f(32, 32));
    shape.setPosition(sf::Vector2f(0, 0));

    shape.setFillColor(sf::Color::White);

    isCollidable = 0;
    textureIndex = 0;
    isForGround = 0;
}*/

BasicShape::FarmablePlot(sf::Vector2f size, sf::Vector2f position, sf::Color clr, bool isCol/*, int idx, std::vector<int> grblidx*/) {
    // A basic property setup, tailored for a specific purpose.
    shape.setSize(size);
    shape.setPosition(position);

    shape.setFillColor(clr);

    isCollidable = isCol;
    textureIndex = idx;

    isForGround = 0;

    currentStage = 1;
    totalStageTime = 0;
    isHarvestable = 0;

    growable = GrowableItem(size, position, clr, isCol, grblidx);
}
