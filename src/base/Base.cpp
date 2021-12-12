#include "../Base.hpp"
Base::Base() {
    //tu.setTime();
    totalTime = 0;

    playerBorders.resize(4);

    currentLevel = 1;
    currentStage = 1;

    createWindow();
    createPlayer();
    designLevel(currentLevel);

    view.setSize(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

    // Example.
    //collides.push_back(BasicShape(sf::Vector2f(64, 64), sf::Vector2f(512, 512), 0, 1, sf::Color::White));
}
