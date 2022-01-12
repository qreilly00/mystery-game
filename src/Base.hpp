#ifndef BASE_HPP
#define BASE_HPP

#include "../inc/common.hpp"

#include "Entity.hpp"
#include "BasicShape.hpp"
#include "LevelShape.hpp"
#include "BasicUtils.hpp"


class Base {
private:
    // Saves the amount of time generated by the timeUtil.
    BasicUtils ut;
    float totalTime;

    sf::RenderWindow window;
    sf::View view;

    Entity player;
    std::vector<sf::FloatRect> playerBorders;
    sf::Vector2f playerMoveAmount;

    int currentLevel;
    int currentStage;

    sf::Vector2f playerStartPosition;

    std::vector<LevelShape> collides;

    std::vector<LevelShape> rooms;
    std::vector<LevelShape> roomWalls;
    std::vector<LevelShape> corridors;
    std::vector<LevelShape> corridorWalls;
    /*std::vector<LevelShape> corridorsHigher;
    std::vector<LevelShape> corridorsMid;
    std::vector<LevelShape> corridorsLower;*/

public:

    // Init class.
    Base();

    // Init functions.
    void createWindow();
    void createPlayer();
    void designLevel(int/*, int*/); // 1 = Rooms

    // Required by designLevel().
    void convertCoords(std::string, sf::Vector2f&);
    void fillLevelArray(sf::Vector2f, sf::Vector2f, std::vector<std::string>, std::vector<LevelShape>&);
    void createCorridorWalls();
    void createRoomWalls();
    void addCollides(std::vector<LevelShape>&);

    // Main Functions.
    bool gameLoop();
    bool checkControls();

    // Required by checkControls().
    float calculateFrameStep();
    void checkMoves();

    // Required by checkMoves().
    void updatePlayerBorders();

    void drawWindow();
};

#endif
