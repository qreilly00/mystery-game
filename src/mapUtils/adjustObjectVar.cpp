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
        case 4:
            objectIsForGround == 0 ? objectIsForGround = 1 : objectIsForGround = 0;
            break;
        case 5:
            if(willIncrease == 1) {
                CurrentTexture < tu.getTextures().size() ? CurrentTexture++ : CurrentTexture = 0;
            } else {
                CurrentTexture > 0 ? CurrentTexture-- : CurrentTexture = tu.getTextures().size() - 1;
            }
            textureChanged = 1;
            break;
        case 6:
            objectCollidable == 0 ? objectCollidable = 1 : objectCollidable = 0;
            break;
        case 7:
            willIncrease == 1 ? objectLevel++ : objectLevel == 0 ? : objectLevel--;
            break;
        case 8:
            willIncrease == 1 ? objectStage++ : objectStage == 0 ? : objectStage--;
            break;
        case 9:
            isObjectFarm == 0 ? isObjectFarm = 1 : isObjectFarm = 0;
            break;
    }
}
