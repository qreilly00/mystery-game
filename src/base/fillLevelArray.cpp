#include "../Base.hpp"

void Base::fillLevelArray(sf::Vector2f startPosition, sf::Vector2f startSize, std::vector<std::string> map, std::vector<LevelShape>& levelArray) {
    // To be incremented as each line of map is checked for rooms.
    sf::Vector2f currentRoomCoords(startPosition);

    // Check each line for objects
    for(int i = 2; i < map.size(); i++) {
        for(int j = 0; j < map[i].size(); j++) {
            if(map[i][j] == '*') {
                levelArray.push_back(LevelShape(startSize, currentRoomCoords, sf::Color::White, 0, currentLevel, 1));
                playerStartPosition = currentRoomCoords;
            } else if(map[i][j] >= 'b' && map[i][j] <= 'i') {
                levelArray.push_back(LevelShape(startSize, currentRoomCoords, sf::Color::White, 0, currentLevel, map[i][j] - 'a'));
                levelArray.push_back(LevelShape(startSize, currentRoomCoords, sf::Color::White, 0, currentLevel, (map[i][j] - 'a') + 1));
            } else if(map[i][j] > '0' && map[i][j] <= '9') {
                levelArray.push_back(LevelShape(startSize, currentRoomCoords, sf::Color::White, 0, currentLevel, map[i][j] - '0'));
            }

            currentRoomCoords.x += startSize.x;
        }

        currentRoomCoords.x = startPosition.x;
        currentRoomCoords.y += startSize.y;
    }
}
