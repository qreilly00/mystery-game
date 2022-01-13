#include "../MapUtils.hpp"

void MapUtils::addCollides(std::vector<LevelShape>& source) {
    for(auto x : source) {
        collides.push_back(x);
    }
}
