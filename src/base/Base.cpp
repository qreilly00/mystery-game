#include "../Base.hpp"
Base::Base() {
    //tu.setTime();
    totalTime = 0;

    playerBorders.resize(4);

    currentLevel = 1;
    currentStage = 1;

    buildMode = 0;

    createWindow();
    createPlayer();
    //mu.designLevel(currentLevel, rooms, roomWalls, corridors, corridorWalls);

    hu.initHudView(window, sf::Vector2f(1000, 0));

    sf::Vector2f playerPosition = mu.designLevel(currentLevel, rooms, corridors, roomWalls, corridorWalls);
    player.getShape().setPosition(playerPosition.x - (player.getShape().getSize().x / 2), playerPosition.y - (player.getShape().getSize().y / 2));

    mu.addCollides(collides, roomWalls);
    mu.addCollides(collides, corridorWalls);

    objects = mu.loadObjects(1);

    view.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));

    // Example.
    //collides.push_back(BasicShape(sf::Vector2f(64, 64), sf::Vector2f(512, 512), 0, 1, sf::Color::White));
}
