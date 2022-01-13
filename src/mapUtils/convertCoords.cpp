#include "../MapUtils.hpp"

void MapUtils::convertCoords(std::string coord, sf::Vector2f& v) {
    float *ptr = &v.x;

    for(int i = 0; i < coord.size(); i++) {
        if(coord[i] == ',') {
            ptr = &v.y;
        } else if(coord[i] >= '0' && coord[i] <= '9') {
            *ptr = (*ptr * 10) + coord[i] - 48;
        }
    }

    ptr = nullptr;
}
