#ifndef GROWABLEITEM_HPP
#define GROWABLEITEM_HPP

#include "../inc/common.hpp"
#include "TextureUtils.hpp"

public GrowableType {BLUE_FLOWER};

class GrowableItem : public BasicShape {
private:
    GrowableType type;

    std::vector<int> stageTextureIndexes;

    int numberOfStages;
    int timeOfStages;

public:
    // Init class.
    //GrowableItem();
    GrowableItem(sf::Vector2f, sf::Vector2f, sf::Color, bool, int);

    void setGrowableType(GrowableTypes);
    //void setStageTextureIndexes(GrowableTypes);
};

#endif