#include "../MapUtils.hpp"

void MapUtils::adjustObjectVar(bool willIncrease) {
    switch(CurrentObjectVar) {
        case 1:
            if(willIncrease == 1) {
                objectSize.x *= 2;
                objectSize.y *= 2;
            } else {
                if(objectSize.x / 2 >= 4) {
                    objectSize.x /= 2;
                    objectSize.y /= 2;
                }
            }
            break;
        case 5:
            willIncrease == 1 ? objectCollidable == 1 : objectCollidable == 0;
            break;
        case 6:
            willIncrease == 1 ? objectLevel++ : objectLevel == 0 ? : objectLevel--;
            break;
        case 7:
            willIncrease == 1 ? objectStage++ : objectStage == 0 ? : objectStage--;
            break;
    }
}
