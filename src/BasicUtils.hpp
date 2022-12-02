#ifndef BASICUTILS_HPP
#define BASICUTILS_HPP

#include "../inc/common.hpp"

class BasicUtils {
private:
    // Required for time util.
	sf::Clock clock;
    sf::Time dt;
	float dtAsSeconds;

    void resetTime() {dt = clock.restart();dtAsSeconds = dt.asSeconds();};
public:
    // General util functions.
    int generateRandomInt(int x, int y);
    sf::Vector2f calcRectCenter(sf::RectangleShape);
    std::vector<std::string> readFileLines(std::string);

    // Property get utils.
	float getTime() {resetTime(); return dtAsSeconds;}
};

#endif
