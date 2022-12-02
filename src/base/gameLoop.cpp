#include "../Base.hpp"

bool Base::gameLoop() {
    totalTime = ut.getTime();

    fadeForeGround();
    drawWindow();

    int exit =
    checkControls();

    player.checkMoves(collides, playerMoveAmount, currentStage);

    playerMoveAmount = sf::Vector2f(0, 0);
    return exit;
}
