#include "../HudUtils.hpp"

void HudUtils::initHudView(sf::RenderWindow &window) {
    hudView.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    hudView.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
    hudView.move(1000.f, 0.f);
}
