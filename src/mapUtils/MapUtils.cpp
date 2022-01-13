#include "../MapUtils.hpp"
MapUtils::MapUtils() {
    currentLevel = 1;
    currentStage = 1;

    roomWallWidth = 8;

    designLevel(currentLevel);
}
