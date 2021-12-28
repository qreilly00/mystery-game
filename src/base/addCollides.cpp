#include "../Base.hpp"

void Base::addCollides(std::vector<LevelShape>& source) {
    for(auto x : source) {
        collides.push_back(x);
    }
}
