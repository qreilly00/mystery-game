#include "../FarmablePlot.hpp"

GrowableTypes FarmablePlot::harvestGrowable() {
    if(isHarvestable()) {
        return growable.getGrowableType();
    }
}
