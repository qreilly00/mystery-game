#include "../Base.hpp"

void Base::designLevel(int lvl/*, int designType*/) {
    std::vector<std::string> map;

    sf::Vector2f startPosition;
    sf::Vector2f startSize;

    map = ut.getFileLines("../map-" + std::to_string(lvl) + "-rooms");

    convertCoords(map[0], startPosition);
    convertCoords(map[1], startSize);

    sf::Vector2f currentRoomCoords(startPosition);

    for(int i = 2; i < map.size(); i++) {
        for(int j = 0; j < map[i].size(); j++) {
            if(map[i][j] == '1') {
                rooms.push_back(BasicShape(startSize, currentRoomCoords, 0, 1, sf::Color::White));
            }

            currentRoomCoords.x += startSize.x;
        }

        currentRoomCoords.x = startPosition.x;
        currentRoomCoords.y += startSize.y;
    }
}
