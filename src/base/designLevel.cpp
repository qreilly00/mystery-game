#include "../Base.hpp"

void Base::designLevel(int lvl/*, int designType*/) {
    //
    // Rooms.
    //
    std::vector<std::string> map;

    sf::Vector2f startPosition;
    sf::Vector2f startSize;

    // Grab all lines from map-x-rooms.
    map = ut.getFileLines("../map-" + std::to_string(lvl) + "-rooms");

    // Get start position and size for map-x-rooms.
    convertCoords(map[0], startPosition);
    convertCoords(map[1], startSize);

    // Put all rooms into the room array.
    fillLevelArray(startPosition, startSize, map, rooms);

    //
    // Corridors higher.
    //

    startPosition = sf::Vector2f(0, 0);
    startSize = sf::Vector2f(0, 0);

    // Grab all lines from map-x-corridors-higher.
    map = ut.getFileLines("../map-" + std::to_string(lvl) + "-corridors-higher");

    // Get start position and size for map-x-corridors-higher.
    convertCoords(map[0], startPosition);
    convertCoords(map[1], startSize);

    // Put all higher corridors into the higher corridors array.
    fillLevelArray(startPosition, startSize, map, corridorsHigher);

    //
    // Corridors mid.
    //

    startPosition = sf::Vector2f(0, 0);
    startSize = sf::Vector2f(0, 0);

    // Grab all lines from map-x-corridors-mid.
    map = ut.getFileLines("../map-" + std::to_string(lvl) + "-corridors-mid");

    // Get start position and size for map-x-corridors-mid.
    convertCoords(map[0], startPosition);
    convertCoords(map[1], startSize);

    // Put all higher corridors into the mid corridors array.
    fillLevelArray(startPosition, startSize, map, corridorsMid);

    //
    // Corridors lower.
    //

    startPosition = sf::Vector2f(0, 0);
    startSize = sf::Vector2f(0, 0);

    // Grab all lines from map-x-corridors-lower.
    map = ut.getFileLines("../map-" + std::to_string(lvl) + "-corridors-lower");

    // Get start position and size for map-x-corridors-lower.
    convertCoords(map[0], startPosition);
    convertCoords(map[1], startSize);

    // Put all higher corridors into the lower corridors array.
    fillLevelArray(startPosition, startSize, map, corridorsLower);
}
