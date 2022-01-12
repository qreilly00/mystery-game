#include "../Base.hpp"

void Base::createRoomWalls() {
    for(auto x : rooms) {
        int isRoomUp = 0;
        int isRoomDown = 0;
        int isRoomLeft = 0;
        int isRoomRight = 0;

        for(int i = 0; i < rooms.size(); i++) {

            if( // Room up?
                x.getShape().getPosition().x == rooms[i].getShape().getPosition().x
                && x.getShape().getPosition().y == rooms[i].getShape().getPosition().y - rooms[i].getShape().getSize().y
                && x.getStage() == rooms[i].getStage()
            ) {
                isRoomUp++;
            } if( // Room down?
                x.getShape().getPosition().x == rooms[i].getShape().getPosition().x
                && x.getShape().getPosition().y == rooms[i].getShape().getPosition().y + rooms[i].getShape().getSize().y
                && x.getStage() == rooms[i].getStage()
            ) {
                isRoomDown++;
            } if( // Room left?
                x.getShape().getPosition().y == rooms[i].getShape().getPosition().y
                && x.getShape().getPosition().x == rooms[i].getShape().getPosition().x - rooms[i].getShape().getSize().x
                && x.getStage() == rooms[i].getStage()
            ) {
                isRoomLeft++;
            } if( // Room right?
                x.getShape().getPosition().y == rooms[i].getShape().getPosition().y
                && x.getShape().getPosition().x == rooms[i].getShape().getPosition().x + rooms[i].getShape().getSize().x
                && x.getStage() == rooms[i].getStage()
            ) {
                isRoomRight++;
            }
        }

        if(isRoomUp == 0) {
            roomWalls.push_back(LevelShape(sf::Vector2f(x.getShape().getSize().x, 8), sf::Vector2f(x.getShape().getPosition().x, x.getShape().getPosition().y - 8), sf::Color::Black, 1, x.getLevel(), x.getStage()));
        } if(isRoomDown == 0) {
            roomWalls.push_back(LevelShape(sf::Vector2f(x.getShape().getSize().x, 8), sf::Vector2f(x.getShape().getPosition().x, x.getShape().getPosition().y + x.getShape().getSize().y), sf::Color::Black, 1, x.getLevel(), x.getStage()));
        } if(isRoomLeft == 0) {
            roomWalls.push_back(LevelShape(sf::Vector2f(8, x.getShape().getSize().y), sf::Vector2f(x.getShape().getPosition().x - 8, x.getShape().getPosition().y), sf::Color::Black, 1, x.getLevel(), x.getStage()));
        } if(isRoomRight == 0) {
            roomWalls.push_back(LevelShape(sf::Vector2f(8, x.getShape().getSize().y), sf::Vector2f(x.getShape().getPosition().x + x.getShape().getSize().x, x.getShape().getPosition().y), sf::Color::Black, 1, x.getLevel(), x.getStage()));
        }
    }
}
