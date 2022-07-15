#include "../MapUtils.hpp"

std::string MapUtils::getObjectVarName() {
    if(CurrentObjectVar < 9) {
        return "(" + std::to_string(CurrentObjectVar) + ") " + objectVarNames[CurrentObjectVar - 1];
    }

    return  "(" + std::to_string(CurrentObjectVar) + ") " + "Error";
}
