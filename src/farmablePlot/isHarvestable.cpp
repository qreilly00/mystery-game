#include "../FarmablePlot.hpp"

bool FarmablePlot::isHarvestable() {
    if(currentStage == growable.getNumberOfStages()) {
        return 1;
    }
    return 0;
}
