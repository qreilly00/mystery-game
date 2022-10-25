#ifndef GROWABLEITEM_HPP
#define GROWABLEITEM_HPP

#include "../inc/common.hpp"
#include "TextureUtils.hpp"

enum GrowableTypes {BLUE_FLOWER};

class GrowableItem : public BasicShape {
private:
    GrowableTypes type;

    std::vector<int> stageTextureIndexes;

    int numberOfStages;
    float timeOfStages;

public:
    // Init class.
    //GrowableItem();
    GrowableItem(sf::Vector2f, sf::Vector2f, sf::Color, bool/*, int*/);

    void setGrowableType(GrowableTypes);

    int getNumberOfStages();
    float getTimeOfStages();
    GrowableTypes getGrowableType();
};

#endif
