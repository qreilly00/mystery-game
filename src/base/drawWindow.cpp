#include "../Base.hpp"

void Base::drawWindow() {
    view.setCenter(ut.getRectCenter(player.getShape()));
    window.setView(view);

    window.clear(sf::Color::Black);

    //std::cout << rooms[0].getStage();

    for(auto x : rooms) {
        if(x.getStage() == currentStage) {
            window.draw(x.getShape());
        }
    }

    for(auto x : corridors) {
        if(x.getStage() == currentStage) {
            window.draw(x.getShape());
        }
    }

    for(auto x : corridorWalls) {
        if(x.getStage() == currentStage) {
            window.draw(x.getShape());
        }
    }

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

    window.draw(player.getShape());

    window.display();
}
