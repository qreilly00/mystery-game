#include "../MapUtils.hpp"

void MapUtils::createCorridorWalls(std::vector<LevelShape> corridors, std::vector<LevelShape>& corridorWalls) {

    for(auto x : corridors) {
        for(int i = 0; i < corridors.size(); i++) {
            // Checks for a corridor piece above or below the current piece.
            if( // Vertical Corridor Walls
                x.getShape().getPosition().x == corridors[i].getShape().getPosition().x
                && x.getShape().getPosition().y == corridors[i].getShape().getPosition().y + corridors[i].getShape().getSize().y
                || x.getShape().getPosition().x == corridors[i].getShape().getPosition().x
                && x.getShape().getPosition().y == corridors[i].getShape().getPosition().y - corridors[i].getShape().getSize().y
                && x.getStage() == corridors[i].getStage()
            ) {
                corridorWalls.push_back(LevelShape(sf::Vector2f(x.getShape().getSize().x / 3, x.getShape().getSize().y), x.getShape().getPosition(), sf::Color::Black, 1, x.getLevel(), x.getStage()));
                corridorWalls.push_back(LevelShape(sf::Vector2f(x.getShape().getSize().x / 3, x.getShape().getSize().y), sf::Vector2f(x.getShape().getPosition().x + ((x.getShape().getSize().x / 3) * 2), x.getShape().getPosition().y), sf::Color::Black, 1, x.getLevel(), x.getStage()));
            } else if( // Horizontal Corridor Walls
                x.getShape().getPosition().y == corridors[i].getShape().getPosition().y
                && x.getShape().getPosition().x == corridors[i].getShape().getPosition().x + corridors[i].getShape().getSize().x
                || x.getShape().getPosition().y == corridors[i].getShape().getPosition().y
                && x.getShape().getPosition().x == corridors[i].getShape().getPosition().x - corridors[i].getShape().getSize().x
                && x.getStage() == corridors[i].getStage()
            ) {
                corridorWalls.push_back(LevelShape(sf::Vector2f(x.getShape().getSize().x, x.getShape().getSize().y / 3), x.getShape().getPosition(), sf::Color::Black, 1, x.getLevel(), x.getStage()));
                corridorWalls.push_back(LevelShape(sf::Vector2f(x.getShape().getSize().x, x.getShape().getSize().y / 3), sf::Vector2f(x.getShape().getPosition().x, x.getShape().getPosition().y + ((x.getShape().getSize().y / 3) * 2)), sf::Color::Black, 1, x.getLevel(), x.getStage()));
            }
        }
    }
}
