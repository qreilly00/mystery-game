#include "../MapUtils.hpp"

void MapUtils::createRoomWalls(std::vector<LevelShape>rooms, std::vector<LevelShape>&roomWalls) {
    int borderSize = roomWallWidth;
    for(auto x : rooms) {
        int isRoomUp = 0;
        int isRoomDown = 0;
        int isRoomLeft = 0;
        int isRoomRight = 0;

        for(int i = 0; i < rooms.size(); i++) {

            if( // Room up?
                x.getShape().getPosition().x == rooms[i].getShape().getPosition().x
                && rooms[i].getShape().getPosition().y == x.getShape().getPosition().y - rooms[i].getShape().getSize().y
                && x.getStage() == rooms[i].getStage()
            ) {
                isRoomUp++;
            } if( // Room down?
                x.getShape().getPosition().x == rooms[i].getShape().getPosition().x
                && rooms[i].getShape().getPosition().y == x.getShape().getPosition().y + rooms[i].getShape().getSize().y
                && x.getStage() == rooms[i].getStage()
            ) {
                isRoomDown++;
            } if( // Room left?
                x.getShape().getPosition().y == rooms[i].getShape().getPosition().y
                && rooms[i].getShape().getPosition().x == x.getShape().getPosition().x - rooms[i].getShape().getSize().x
                && x.getStage() == rooms[i].getStage()
            ) {
                isRoomLeft++;
            } if( // Room right?
                x.getShape().getPosition().y == rooms[i].getShape().getPosition().y
                && rooms[i].getShape().getPosition().x == x.getShape().getPosition().x + rooms[i].getShape().getSize().x
                && x.getStage() == rooms[i].getStage()
            ) {
                isRoomRight++;
            }
        }

        if(isRoomUp == 0) {
            roomWalls.push_back(LevelShape(sf::Vector2f(x.getShape().getSize().x, borderSize), sf::Vector2f(x.getShape().getPosition().x, x.getShape().getPosition().y - borderSize), sf::Color::Black, 1, x.getLevel(), x.getStage()));
        } if(isRoomDown == 0) {
            roomWalls.push_back(LevelShape(sf::Vector2f(x.getShape().getSize().x, borderSize), sf::Vector2f(x.getShape().getPosition().x, x.getShape().getPosition().y + x.getShape().getSize().y), sf::Color::Black, 1, x.getLevel(), x.getStage()));
        } if(isRoomLeft == 0) {
            roomWalls.push_back(LevelShape(sf::Vector2f(borderSize, x.getShape().getSize().y), sf::Vector2f(x.getShape().getPosition().x - borderSize, x.getShape().getPosition().y), sf::Color::Black, 1, x.getLevel(), x.getStage()));
        } if(isRoomRight == 0) {
            roomWalls.push_back(LevelShape(sf::Vector2f(borderSize, x.getShape().getSize().y), sf::Vector2f(x.getShape().getPosition().x + x.getShape().getSize().x, x.getShape().getPosition().y), sf::Color::Black, 1, x.getLevel(), x.getStage()));
        }
    }
}
