#include "../Base.hpp"

bool Base::checkControls() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
            return 1;
        }

        if (event.type == sf::Event::KeyPressed) {
            /*if (event.key.code == sf::Keyboard::Return) {
                currentStage == 2 ? currentStage = 1 : currentStage = 2;
            }*/

            if (event.key.code == sf::Keyboard::Num0)
                buildMode == 0 ? buildMode = 1 : buildMode = 0;

            if(buildMode == 1) {
                if (event.key.code == sf::Keyboard::RBracket) {
                    mu.adjustObjectVar(1);
                } else if (event.key.code == sf::Keyboard::LBracket) {
                    mu.adjustObjectVar(0);
                }
            }
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if(buildMode == 1)
                    objects.push_back(mu.leftMousePressed(window.mapPixelToCoords(sf::Mouse::getPosition(window))));
            }
        }

        if (event.type == sf::Event::TextEntered) {
            if(buildMode == 1) {
                if (event.text.unicode >= 49 && event.text.unicode <= 57)
                    mu.setCurrentObjectVar(int(event.text.unicode) - 48);
            }
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
