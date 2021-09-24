#include "../Base.hpp"

void Base::designLevel(int lvl/*, int designType*/) {

    // Rooms, Corridors (Higher, Mid and Lower).

    std::vector<std::string> fileNames = {"-rooms", "-corridors-higher", "-corridors-mid", "-corridors-lower"};

    for(int i = 0; i < fileNames.size(); i++) {
        std::vector<std::string> map;

        sf::Vector2f startPosition;
        sf::Vector2f startSize;

        // Grab all lines from map-x-rooms.
        map = ut.getFileLines("../map-" + std::to_string(lvl) + fileNames[i]);

        // Get start position and size for map-x-rooms.
        convertCoords(map[0], startPosition);
        convertCoords(map[1], startSize);

        // Put all rooms into the room array.
        switch(i) {
            case 0:
                fillLevelArray(startPosition, startSize, map, rooms);
                break;
            case 1:
                fillLevelArray(startPosition, startSize, map, corridorsHigher);
                break;
            case 2:
                fillLevelArray(startPosition, startSize, map, corridorsMid);
                break;
            case 3:
                fillLevelArray(startPosition, startSize, map, corridorsLower);
                break;
        }
    }
}
