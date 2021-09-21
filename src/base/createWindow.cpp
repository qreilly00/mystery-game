#include "../Base.hpp"

void Base::createWindow() {
    window.create(sf::VideoMode(1600 , 900), "SFML works!"/*, sf::Style::Fullscreen*/);
    //window.setFramerateLimit(10);
}
