#include "../MapUtils.hpp"

std::string MapUtils::getObjectVarValue() {
    if(CurrentObjectVar == 1) {
        std::stringstream ss;
        ss << objectSize.x << ", " << objectSize.y;
        return ss.str();
    } else if(CurrentObjectVar == 2 || CurrentObjectVar == 3) {
        return "Blank";
    } else if(CurrentObjectVar == 4) {
        return std::to_string(objectIsForGround);
    } else if(CurrentObjectVar == 5) {
        return std::to_string(CurrentTexture);
    } else if(CurrentObjectVar == 6) {
        return std::to_string(objectCollidable);
    } else if(CurrentObjectVar == 7) {
        return std::to_string(objectLevel);
    } else if(CurrentObjectVar == 8) {
        return std::to_string(objectStage);
    }
    return "Error";
}
