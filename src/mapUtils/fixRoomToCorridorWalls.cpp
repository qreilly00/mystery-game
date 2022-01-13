#include "../MapUtils.hpp"

void MapUtils::fixRoomToCorridorWalls() {
    int borderSize = roomWallWidth;

    //std::cout << borderSize;
    for(int i = 0; i < roomWalls.size(); i++) {

        for(int j = 0; j < corridors.size(); j++) {

            if( // corridor up?
                roomWalls[i].getShape().getPosition().x == corridors[j].getShape().getPosition().x
                && roomWalls[i].getShape().getPosition().y == (corridors[j].getShape().getPosition().y + corridors[j].getShape().getSize().y) - 8
                && roomWalls[i].getStage() == corridors[j].getStage()
            ) {
                roomWalls[i].getShape().setSize(sf::Vector2f(1, 1));
            }if( // corridor down?
                roomWalls[i].getShape().getPosition().x == corridors[j].getShape().getPosition().x
                && roomWalls[i].getShape().getPosition().y == corridors[j].getShape().getPosition().y
                && roomWalls[i].getStage() == corridors[j].getStage()
            ) {
                roomWalls[i].getShape().setSize(sf::Vector2f(1, 1));
            } if( // corridor left?
                roomWalls[i].getShape().getPosition().x == (corridors[j].getShape().getPosition().x + corridors[j].getShape().getSize().x) - 8
                && roomWalls[i].getShape().getPosition().y == corridors[j].getShape().getPosition().y
                && roomWalls[i].getStage() == corridors[j].getStage()
            ) {
                roomWalls[i].getShape().setSize(sf::Vector2f(1, 1));
            } if( // corridor right?
                roomWalls[i].getShape().getPosition().x == corridors[j].getShape().getPosition().x
                && roomWalls[i].getShape().getPosition().y == corridors[j].getShape().getPosition().y
                && roomWalls[i].getStage() == corridors[j].getStage()
            ) {
                roomWalls[i].getShape().setSize(sf::Vector2f(1, 1));
            }
            //std::cout << isRoomUp << std::endl;
        }
    }
}
