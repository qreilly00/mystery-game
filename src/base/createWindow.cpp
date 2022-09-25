#include "../Base.hpp"

void Base::createWindow() {
    window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "SFML works!", sf::Style::Fullscreen);
    //window.setFramerateLimit(10);
}
