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

    LevelShape l;

    sf::Vector2f playerStartPosition;

    int currentLevel;
    int roomWallWidth;

    int CurrentObjectVar;

    // Visual editor variables.
    sf::Vector2f objectSize; // Select = 1.
    sf::Vector2f objectPosition; // Select = 2.
    sf::Color objectColor; // Select = 3.
    //sf::texture objectTexture;
    bool objectCollidable; // Select = 5.
    int objectLevel; // Select = 6.
    int objectStage; // Select = 7.

public:

    // Init class.
    MapUtils();

    // text editor functions.
    sf::Vector2f designLevel(int lvl, std::vector<LevelShape>&, std::vector<LevelShape>&, std::vector<LevelShape>&, std::vector<LevelShape>&);

    // Required by designLevel().
    void convertCoords(std::string, sf::Vector2f&);
    void fillLevelArray(sf::Vector2f, sf::Vector2f, std::vector<std::string>, std::vector<LevelShape>&);

    void createCorridorWalls(std::vector<LevelShape>, std::vector<LevelShape>&);
    void createRoomWalls(std::vector<LevelShape>, std::vector<LevelShape>&);

    void fixRoomToCorridorWalls(std::vector<LevelShape>&, std::vector<LevelShape>);
    void addCollides(std::vector<LevelShape>&, std::vector<LevelShape>);

    // Visual editor functions.
    LevelShape leftMousePressed(sf::Vector2f);
    sf::Vector2f rightMousePressed(sf::Vector2f);
    sf::RectangleShape buildPointer(sf::Vector2f);
    void saveObjects(std::vector<LevelShape>);
    std::vector<LevelShape> loadObjects(int);

    // Required by visual editor functions.
    void setCurrentObjectVar(int);
    void adjustObjectVar(bool);
};

#endif
