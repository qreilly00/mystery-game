#include "../Base.hpp"

bool Base::checkControls() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
            return 1;
        }
    }

    // Controls.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        playerMoveAmount += sf::Vector2f(0, -calculateFrameStep());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        playerMoveAmount += sf::Vector2f(-calculateFrameStep(), 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        playerMoveAmount += sf::Vector2f(0, calculateFrameStep());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        playerMoveAmount += sf::Vector2f(calculateFrameStep(), 0);
    }

    //if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {}

    return 0;
}
