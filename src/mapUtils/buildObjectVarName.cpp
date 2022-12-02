#include "../MapUtils.hpp"

std::string MapUtils::buildObjectVarName() {
    if(CurrentObjectVar < 9) {
        return "(" + std::to_string(CurrentObjectVar) + ") " + objectVarNames[CurrentObjectVar - 1];
    }

    return  "(" + std::to_string(CurrentObjectVar) + ") " + "Error";
}
