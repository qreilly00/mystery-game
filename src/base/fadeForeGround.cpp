#include "../Base.hpp"

void Base::fadeForeGround() {
    for(int i = 0; i < objects.size(); i++) {
        if(objects[i].getIsForGround() == 1
            && (ut.calcRectCenter(objects[i].getShape()).x - ut.calcRectCenter(player.getShape()).x <= 256 && ut.calcRectCenter(objects[i].getShape()).y - ut.calcRectCenter(player.getShape()).y <= 256)
            && (ut.calcRectCenter(objects[i].getShape()).x - ut.calcRectCenter(player.getShape()).x >= -256 && ut.calcRectCenter(objects[i].getShape()).y - ut.calcRectCenter(player.getShape()).y >= -256))
                /*&& (ut.calcRectCenter(objects[i].getShape()).x - window.mapPixelToCoords(sf::Mouse::getPosition(window)).x <= 256 && ut.calcRectCenter(objects[i].getShape()).y - window.mapPixelToCoords(sf::Mouse::getPosition(window)).y <= 256)
                && (ut.calcRectCenter(objects[i].getShape()).x - window.mapPixelToCoords(sf::Mouse::getPosition(window)).x >= -256 && ut.calcRectCenter(objects[i].getShape()).y - window.mapPixelToCoords(sf::Mouse::getPosition(window)).y >= -256))*/ {

            int xPos = ut.calcRectCenter(objects[i].getShape()).x;
            int yPos = ut.calcRectCenter(objects[i].getShape()).y;
            if(xPos < 0) {xPos = -xPos;}
            if(yPos < 0) {yPos = -yPos;}

            int xDiff = xPos - ut.calcRectCenter(player.getShape()).x;
            int yDiff = yPos - ut.calcRectCenter(player.getShape()).y;
            if(xDiff < 32) {xDiff = -xDiff;}
            if(yDiff < 32) {yDiff = -yDiff;}

            int alpha;
            alpha = (xDiff + yDiff) <= 128 ? 0: (xDiff + yDiff);

            if(alpha < 0) {alpha = -alpha;}
            if(alpha > 255) {alpha = 255;}
            objects[i].getShape().setFillColor(sf::Color(objects[i].getShape().getFillColor().r, objects[i].getShape().getFillColor().g, objects[i].getShape().getFillColor().b, alpha));
        } else {
            objects[i].getShape().setFillColor(sf::Color(objects[i].getShape().getFillColor().r, objects[i].getShape().getFillColor().g, objects[i].getShape().getFillColor().b, 255));
        }
    }

}
