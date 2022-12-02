#ifndef MAPUTILS_HPP
#define MAPUTILS_HPP

#include "../inc/common.hpp"

#include "Entity.hpp"
#include "BasicShape.hpp"
#include "LevelShape.hpp"
#include "BasicUtils.hpp"
#include "TextureUtils.hpp"
//#include "FarmablePlot.hpp"

class MapUtils {
private:
    BasicUtils ut;
    TextureUtils tu;

    LevelShape l;

    sf::Vector2f playerStartPosition;

    int currentLevel;
    int roomWallWidth;

    int CurrentObjectVar;
    int textureChanged;

    std::vector<std::string> objectVarNames;

    // Visual editor variables.
    sf::Vector2f objectSize; // Select = 1.
    sf::Vector2f objectPosition; // Select = 2.
    sf::Color objectColor; // Select = 3.
    int objectIsForGround; // Select = 4.
    int CurrentTexture; // Select = 5
    bool objectCollidable; // Select = 6.
    int objectLevel; // Select = 7.
    int objectStage; // Select = 8.
    bool isObjectFarm;

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
    void addCollides(std::vector<LevelShape>& collides, std::vector<LevelShape> source) {for(auto x : source) collides.push_back(x);}
    void addCollidesCycle(std::vector<LevelShape>& collides, std::vector<LevelShape> source) {for(auto x : source) if(x.getIsCollidable()) collides.push_back(x);}

    // Visual editor functions.
    LevelShape leftMousePressed(sf::Vector2f mousePos) {return LevelShape(objectSize, sf::Vector2f(int(mousePos.x) - (int(mousePos.x) % 32), int(mousePos.y) - (int(mousePos.y) % 32)), objectColor, objectCollidable, objectIsForGround, objectLevel, objectStage, &tu.getTextures()[CurrentTexture], CurrentTexture);}
    //FarmablePlot leftMousePressedF(sf::Vector2f mousePos) {return FarmablePlot(objectSize, sf::Vector2f(int(mousePos.x) - (int(mousePos.x) % 32), int(mousePos.y) - (int(mousePos.y) % 32)), objectColor, objectCollidable, objectIsForGround, objectLevel, objectStage, &tu.getTextures()[CurrentTexture], CurrentTexture);}
    sf::Vector2f rightMousePressed(sf::Vector2f mousePos) {return sf::Vector2f(int(mousePos.x) - (int(mousePos.x) % 32), int(mousePos.y) - (int(mousePos.y) % 32));}
    sf::RectangleShape& buildPointer(sf::Vector2f);
    void saveObjects(std::vector<LevelShape>);
    std::vector<LevelShape> loadObjects(int);

    // Required by visual editor functions.
    void adjustObjectVar(bool);
    std::string buildObjectVarName();
    std::string buildObjectVarValue();

    // Property set utils.
    void setCurrentObjectVar(int varNumber) {CurrentObjectVar = varNumber;}

    // Property get utils.
    //bool getIsObjectFarm() {return isObjectFarm;}
    std::vector<sf::Texture>& returnTextures() {return tu.getTextures();}
    std::vector<std::string>& returnTextureNames() {return tu.getTextureNames();}
};

#endif
