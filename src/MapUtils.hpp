#ifndef MAPUTILS_HPP
#define MAPUTILS_HPP

#include "../inc/common.hpp"

#include "Entity.hpp"
#include "BasicShape.hpp"
#include "LevelShape.hpp"
#include "BasicUtils.hpp"


class MapUtils {
private:
    BasicUtils ut;
    
    sf::Vector2f playerStartPosition;

    int currentLevel;
    int currentStage;

    int roomWallWidth;

    std::vector<LevelShape> collides;

    std::vector<LevelShape> rooms;
    std::vector<LevelShape> roomWalls;
    std::vector<LevelShape> corridors;
    std::vector<LevelShape> corridorWalls;

public:

    // Init class.
    MapUtils();

    // Init functions.
    void designLevel(int/*, int*/); // 1 = Rooms

    // Required by designLevel().
    void convertCoords(std::string, sf::Vector2f&);
    void fillLevelArray(sf::Vector2f, sf::Vector2f, std::vector<std::string>, std::vector<LevelShape>&);

    void createCorridorWalls();
    void createRoomWalls();

    void fixRoomToCorridorWalls();
    void addCollides(std::vector<LevelShape>&);
};

#endif
