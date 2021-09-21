#include "../Base.hpp"

bool Base::gameLoop() {
    ut.setTime();
    totalTime = ut.getTime();

    bool exit = 0;

    exit =
    checkControls();
    checkMoves();
    drawWindow();

    playerMoveAmount = sf::Vector2f(0, 0);

    return exit;
}
