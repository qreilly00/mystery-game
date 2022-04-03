#include "../Base.hpp"

void Base::fadeForeGround() {
    for(int i = 0; i < objects.size(); i++) {
        if(objects[i].getIsForGround() == 1
                && (ut.getRectCenter(objects[i].getShape()).x - window.mapPixelToCoords(sf::Mouse::getPosition(window)).x <= 256 && ut.getRectCenter(objects[i].getShape()).y - window.mapPixelToCoords(sf::Mouse::getPosition(window)).y <= 256)
                && (ut.getRectCenter(objects[i].getShape()).x - window.mapPixelToCoords(sf::Mouse::getPosition(window)).x >= -256 && ut.getRectCenter(objects[i].getShape()).y - window.mapPixelToCoords(sf::Mouse::getPosition(window)).y >= -256)) {

            int xPos = ut.getRectCenter(objects[i].getShape()).x;
            int yPos = ut.getRectCenter(objects[i].getShape()).y;
            if(xPos < 0) {xPos = -xPos;}
            if(yPos < 0) {yPos = -yPos;}

            int xDiff = xPos - window.mapPixelToCoords(sf::Mouse::getPosition(window)).x;
            int yDiff = yPos - window.mapPixelToCoords(sf::Mouse::getPosition(window)).y;
            if(xDiff < 0) {xDiff = -xDiff;}
            if(yDiff < 0) {yDiff = -yDiff;}

            int alpha =  (xDiff + yDiff) / 3 - 1;
            if(alpha < 0) {alpha = -alpha;}
            objects[i].getShape().setFillColor(sf::Color(objects[i].getShape().getFillColor().r, objects[i].getShape().getFillColor().g, objects[i].getShape().getFillColor().b, alpha));
        } else {
            objects[i].getShape().setFillColor(sf::Color(objects[i].getShape().getFillColor().r, objects[i].getShape().getFillColor().g, objects[i].getShape().getFillColor().b, 255));
        }
    }
    /*int xPos = ut.getRectCenter(objects[62].getShape()).x;
    int yPos = ut.getRectCenter(objects[62].getShape()).y;
    if(xPos < 0) {xPos = -xPos;}
    if(yPos < 0) {yPos = -yPos;}

    int x = xPos - window.mapPixelToCoords(sf::Mouse::getPosition(window)).x;
    int y = yPos - window.mapPixelToCoords(sf::Mouse::getPosition(window)).y;
    if(x < 0) {x = -x;}
    if(y < 0) {y = -y;}
    int alpha =  x + y - 1;
    if(alpha < 0) {alpha = -alpha;}
    std::cout << x << ", " << y << ", " << alpha << std::endl;*/

}
