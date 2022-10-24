#ifndef FARMABLEPLOT_HPP
#define FARMABLEPLOT_HPP

#include "../inc/common.hpp"
#include "GrowableItem.hpp"

class FarmablePlot : public BasicShape {
private:
    GrowableItem growable; // stageTime will be for all stages.]

    int currentStage;
    float totalStageTime;
    bool isHarvestable;

    bool isHarvestable(); // checks if the current stage is equal to the final stage of plant growth.

public:
    // Init class.
    //FarmablePlot();
    FarmablePlot(sf::Vector2f, sf::Vector2f, sf::Color, bool, int);

    void setGrowableType(GrowableTypes);
    void addToTotalStageTime(float); // requires a handler class or function to add the time between frames to the totalStage time.
    void checkStageGrowRequirements(); // check if totalStageTime has matched or exceeded stageTime and growable is not yet harvestable.

    GrowableTypes harvestGrowable(); // check if it is harvestable first.
};

#endif
