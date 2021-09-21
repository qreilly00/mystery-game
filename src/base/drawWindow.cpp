#include "../Base.hpp"

void Base::drawWindow() {
    window.clear(sf::Color::Black);
    window.draw(player.getShape());

    for(auto x : collides) {window.draw(x.getShape());}
    //for(auto x : jigSawPieces) {}

    window.display();
}
