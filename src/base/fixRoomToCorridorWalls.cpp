#include "../Base.hpp"

void Base::fixRoomToCorridorWalls() {
    int borderSize = roomWallWidth;
    for(auto x : roomWalls) {

        for(int i = 0; i < corridorWalls.size(); i++) {

            if( // Room down?
                x.getShape().getPosition() == corridorWalls[i].getShape().getPosition()
                //&& x.getStage() == corridorWalls[i].getStage()
            ) {
                x.getShape().setSize(sf::Vector2f(32/*corridorWalls[i].getShape().getSize().x*/, borderSize + 32));
                //std::cout << "Test";
            } /*if( // Room down?
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
            }*/
            //std::cout << isRoomUp << std::endl;
        }

        /*if(isRoomUp == 0) {
            roomWalls.push_back(LevelShape(sf::Vector2f(x.getShape().getSize().x, borderSize), sf::Vector2f(x.getShape().getPosition().x, x.getShape().getPosition().y - borderSize), sf::Color::Black, 1, x.getLevel(), x.getStage()));
        } if(isRoomDown == 0) {
            roomWalls.push_back(LevelShape(sf::Vector2f(x.getShape().getSize().x, borderSize), sf::Vector2f(x.getShape().getPosition().x, x.getShape().getPosition().y + x.getShape().getSize().y), sf::Color::Black, 1, x.getLevel(), x.getStage()));
        } if(isRoomLeft == 0) {
            roomWalls.push_back(LevelShape(sf::Vector2f(borderSize, x.getShape().getSize().y), sf::Vector2f(x.getShape().getPosition().x - borderSize, x.getShape().getPosition().y), sf::Color::Black, 1, x.getLevel(), x.getStage()));
        } if(isRoomRight == 0) {
            roomWalls.push_back(LevelShape(sf::Vector2f(borderSize, x.getShape().getSize().y), sf::Vector2f(x.getShape().getPosition().x + x.getShape().getSize().x, x.getShape().getPosition().y), sf::Color::Black, 1, x.getLevel(), x.getStage()));
        }*/
    }
}
