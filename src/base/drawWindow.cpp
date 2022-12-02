#include "../Base.hpp"

void Base::drawWindow() {
    window.clear(sf::Color::Black);

    view.setCenter(ut.calcRectCenter(player.getShape()));
    window.setView(view);

    //std::cout << rooms[0].getStage();

    for(auto x : rooms) {
        if(x.getLevel() == currentLevel && x.getStage() == currentStage) {
            window.draw(x.getShape());
        }
    }

    for(auto x : corridors) {
        if(x.getLevel() == currentStage) {
            window.draw(x.getShape());
        }
    }

    for(auto x : collides) {
        if(x.getLevel() == currentLevel && x.getStage() == currentStage) {
            window.draw(x.getShape());
        }
    }

    for(auto x : objects) {
        if(x.getLevel() == currentLevel && x.getStage() == currentStage) {
            window.draw(x.getShape());
        }
    }

    window.draw(player.getShape());

    /*for(auto x : farmObjects) {
        if(x.getLevel() == currentLevel && x.getStage() == currentStage) {
            window.draw(x.getShape());
        }
    }*/

    if(buildMode == 1) window.draw(mu.buildPointer(window.mapPixelToCoords(sf::Mouse::getPosition(window))));


    window.setView(hu.getHudView());

    // draw hud elements
    if(buildMode == 1) {
        std::stringstream ss;
        ss << mu.buildObjectVarName() << ": "<< mu.buildObjectVarValue();

        hu.drawText(window, ss.str());
    }

    window.display();

    // reset for MapUtils
    window.setView(view);
}
