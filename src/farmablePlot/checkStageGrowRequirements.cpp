#include "../FarmablePlot.hpp"

void FarmablePlot::checkStageGrowRequirements() { // check if totalStageTime has matched or exceeded stageTime and growable is not yet harvestable.
    if(!isHarvestable()) {
        if(totalStageTime >= growable.getTimeOfStages()) {
            currentStage++;
            totalStageTime = 0;
        }
    } else {
        totalStageTime = 0;
    }
}
