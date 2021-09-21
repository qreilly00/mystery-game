#include "../Base.hpp"

void Base::checkMoves() {
    updatePlayerBorders();

    for(auto x : collides) {
        // Figure out before-hand, the distance between each side of the shape and the current object.
        float playerLeftDistance = (x.getShape().getPosition().x + x.getShape().getSize().x) - player.getShape().getPosition().x;
        float playerRightDistance = player.getShape().getPosition().x + player.getShape().getSize().x - (x.getShape().getPosition().x);
        float playerTopDistance = (x.getShape().getPosition().y + x.getShape().getSize().y) - player.getShape().getPosition().y;
        float playerBottomDistance = player.getShape().getPosition().y + player.getShape().getSize().y - (x.getShape().getPosition().y);

        // While moving left, right, top and bottom.
        if(playerMoveAmount.x < 0 && playerBorders[0].intersects(x.getShape().getGlobalBounds())) {
            if(playerMoveAmount.x > (playerLeftDistance)) {
                playerMoveAmount.x = playerLeftDistance;
            } else {
                playerMoveAmount.x = 0;
            }
        }
        if(playerMoveAmount.x > 0 && playerBorders[1].intersects(x.getShape().getGlobalBounds())) {
            if(-playerMoveAmount.x > (playerRightDistance)) {
                playerMoveAmount.x = -playerRightDistance;
            } else {
                playerMoveAmount.x = 0;
            }
        }
        if(playerMoveAmount.y < 0 && playerBorders[2].intersects(x.getShape().getGlobalBounds())) {
            if(playerMoveAmount.y > (playerTopDistance)) {
                playerMoveAmount.y = playerTopDistance;
            } else {
                playerMoveAmount.y = 0;
            }
        }
        if(playerMoveAmount.y > 0 && playerBorders[3].intersects(x.getShape().getGlobalBounds())) {
            if(-playerMoveAmount.y > (playerBottomDistance)) {
                playerMoveAmount.y = -playerBottomDistance;
            } else {
                playerMoveAmount.y = 0;
            }
        }
    }

    player.getShape().move(playerMoveAmount);
}
