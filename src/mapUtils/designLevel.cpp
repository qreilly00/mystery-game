#include "../MapUtils.hpp"

sf::Vector2f MapUtils::designLevel(int lvl, std::vector<LevelShape>& rooms, std::vector<LevelShape>& corridors, std::vector<LevelShape>& roomWalls, std::vector<LevelShape>& corridorWalls) {

    // Rooms, Corridors (Higher, Mid and Lower).

    currentLevel = lvl;

    std::vector<std::string> fileNames = {"-rooms", "-corridors"/*"-corridors-higher", "-corridors-mid", "-corridors-lower"*/};

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
                createRoomWalls(rooms, roomWalls);
                playerStartPosition.x += startSize.x / 2;
                playerStartPosition.y += startSize.y / 2;
                break;
            case 1:
                fillLevelArray(startPosition, startSize, map, corridors);
                createCorridorWalls(corridors, corridorWalls);
                break;
        }
    }
    fixRoomToCorridorWalls(roomWalls, corridors);

    return playerStartPosition;
}
