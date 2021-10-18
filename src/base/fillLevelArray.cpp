#include "../Base.hpp"

void Base::fillLevelArray(sf::Vector2f startPosition, sf::Vector2f startSize, std::vector<std::string> map, std::vector<BasicShape>& levelArray) {
    // To be incremented as each line of map is checked for rooms.
    sf::Vector2f currentRoomCoords(startPosition);

    // Check each line for objects
    for(int i = 2; i < map.size(); i++) {
        for(int j = 0; j < map[i].size(); j++) {
            if(map[i][j] == '1') {
                levelArray.push_back(LevelShape(startSize, currentRoomCoords, sf::Color::White, 0, currentLevel, 1));
            } else if(map[i][j] == '2') {
                levelArray.push_back(LevelShape(startSize, currentRoomCoords, sf::Color::White, 0, currentLevel, 2));
            }

            currentRoomCoords.x += startSize.x;
        }

        currentRoomCoords.x = startPosition.x;
        currentRoomCoords.y += startSize.y;
    }
}
