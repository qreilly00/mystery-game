#include "../FarmablePlot.hpp"

GrowableTypes FarmablePlot::harvestGrowable(float time) {
    if(isHarvestable != 1) {
        return growable.getGrowableType();
    }

    std::cout << "Current Stage: " << currentStage << std::endl;

    addToTotalStageTime(time);
}
