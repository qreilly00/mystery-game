#include "../Base.hpp"

void Base::drawWindow() {
    window.clear(sf::Color::Black);

    view.setCenter(ut.getRectCenter(player.getShape()));
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

    for(auto x : corridorWalls) {
        if(x.getLevel() == currentLevel && x.getStage() == currentStage) {
            window.draw(x.getShape());
        }
    }

    for(auto x : objects) {
        if(x.getLevel() == currentLevel && x.getStage() == currentStage) {
            window.draw(x.getShape());
        }
    }

    if(buildMode == 1) window.draw(mu.buildPointer(window.mapPixelToCoords(sf::Mouse::getPosition(window))));

    /*for(auto x : roomWalls) {
        if(x.getStage() == currentStage) {
            window.draw(x.getShape());
        }
    }*/

    //for(auto x : collides) {window.draw(x.getShape());}

    /*for(auto x : corridorsHigher) {window.draw(x.getShape());}
    for(auto x : corridorsMid) {window.draw(x.getShape());}
    for(auto x : corridorsLower) {window.draw(x.getShape());}
    //for(auto x : jigSawPieces) {}*/

    //window.draw(player.getShape());

    window.setView(hu.getHudView());

    // draw hud elements
    hu.drawText(window);

    window.display();

    // reset for MapUtils
    window.setView(view);
}
