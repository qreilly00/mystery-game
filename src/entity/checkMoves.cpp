#include "../Entity.hpp"

void Entity::checkMoves(std::vector<LevelShape>& collides, sf::Vector2f playerMoveAmount, int currentStage) {
    updatePlayerBorders();

    for(auto x : collides) {
        // Figure out before-hand, the distance between each side of the shape and the current object.
        float playerLeftDistance = (x.getShape().getPosition().x + x.getShape().getSize().x) - getShape().getPosition().x;
        float playerRightDistance = getShape().getPosition().x + getShape().getSize().x - (x.getShape().getPosition().x);
        float playerTopDistance = (x.getShape().getPosition().y + x.getShape().getSize().y) - getShape().getPosition().y;
        float playerBottomDistance = getShape().getPosition().y + getShape().getSize().y - (x.getShape().getPosition().y);

        // While moving left, right, up and down.
        if(playerMoveAmount.x < 0 && playerBorders[0].intersects(x.getShape().getGlobalBounds()) && x.getStage() == currentStage) {
            playerMoveAmount.x = playerLeftDistance;
        }
        if(playerMoveAmount.x > 0 && playerBorders[1].intersects(x.getShape().getGlobalBounds()) && x.getStage() == currentStage) {
            playerMoveAmount.x = -playerRightDistance;
        }
        if(playerMoveAmount.y < 0 && playerBorders[2].intersects(x.getShape().getGlobalBounds()) && x.getStage() == currentStage) {
            playerMoveAmount.y = playerTopDistance;
        }
        if(playerMoveAmount.y > 0 && playerBorders[3].intersects(x.getShape().getGlobalBounds()) && x.getStage() == currentStage) {
            playerMoveAmount.y = -playerBottomDistance;
        }
    }

    getShape().move(playerMoveAmount);
}
