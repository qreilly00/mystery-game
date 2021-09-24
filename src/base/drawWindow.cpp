#include "../Base.hpp"

void Base::drawWindow() {
    view.setCenter(ut.getRectCenter(player.getShape()));
    window.setView(view);

    window.clear(sf::Color::Black);

    for(auto x : collides) {window.draw(x.getShape());}
    for(auto x : rooms) {window.draw(x.getShape());}
    for(auto x : corridorsHigher) {window.draw(x.getShape());}
    for(auto x : corridorsMid) {window.draw(x.getShape());}
    for(auto x : corridorsLower) {window.draw(x.getShape());}
    //for(auto x : jigSawPieces) {}

    window.draw(player.getShape());

    window.display();
}
