//include classes and headers
#include "../inc/common.hpp"
#include "TimeUtil.hpp"

class BasicShape {
private:
    sf::RectangleShape shape;

    float speed;
    float speedMultiplier;
public:
    BasicShape();
    BasicShape(sf::Vector2f, sf::Vector2f, float, float, sf::Color);

    sf::RectangleShape& getShape();

    float getSpeed();
    float getSpeedMultiplier();

    void setSpeed(float);
    void setSpeedMultiplier(float);
};

BasicShape::BasicShape() {
    shape.setSize(sf::Vector2f(32, 32));
    shape.setPosition(sf::Vector2f(0, 0));

    speed = 100;
    speedMultiplier = 1;

    shape.setFillColor(sf::Color::White);
}

BasicShape::BasicShape(sf::Vector2f size, sf::Vector2f position, float spd, float spdMlt, sf::Color clr) {
    shape.setSize(size);
    shape.setPosition(position);

    speed = spd;
    speedMultiplier = spdMlt;

    shape.setFillColor(clr);
}

sf::RectangleShape& BasicShape::getShape() {return shape;}

float BasicShape::getSpeed() {return speed;}
float BasicShape::getSpeedMultiplier() {return speedMultiplier;}

void BasicShape::setSpeed(float spd) {speed = spd;}
void BasicShape::setSpeedMultiplier(float spdMlt) {speedMultiplier = spdMlt;}

class Base {
private:
    TimeUtil tu;
    float totalTime;

    sf::RenderWindow window;
    BasicShape player;

    sf::Vector2f playerMoveAmount;

    std::vector<BasicShape> collides;

public:
    Base();

    void createWindow();
    void createPlayer();

    bool gameLoop();
    bool checkControls();
    void checkMoves();

    sf::Vector2f getRectCenter(sf::RectangleShape);
    sf::Vector2f getRectDelta(sf::Vector2f, sf::Vector2f);

    void drawWindow();

    float calculateFrameStep();

    int getRandomInt(int x, int y);
};

Base::Base() {
    tu.setTime();
    totalTime = 0;

    collides.push_back(BasicShape(sf::Vector2f(64, 64), sf::Vector2f(512, 512), 0, 1, sf::Color::White));
    //collides.push_back(BasicShape(sf::Vector2f(64, 64), sf::Vector2f(0, 192), 0, 1, sf::Color::White));
    /*collides.push_back(BasicShape(sf::Vector2f(64, 64), sf::Vector2f(0, 256), 0, 1, sf::Color::White));
    collides.push_back(BasicShape(sf::Vector2f(64, 64), sf::Vector2f(0, 320), 0, 1, sf::Color::White));
    collides.push_back(BasicShape(sf::Vector2f(64, 64), sf::Vector2f(0, 384), 0, 1, sf::Color::White));
    collides.push_back(BasicShape(sf::Vector2f(64, 64), sf::Vector2f(0, 448), 0, 1, sf::Color::White));
    collides.push_back(BasicShape(sf::Vector2f(64, 64), sf::Vector2f(64, 448), 0, 1, sf::Color::White));
    collides.push_back(BasicShape(sf::Vector2f(64, 64), sf::Vector2f(128, 448), 0, 1, sf::Color::White));

    collides.push_back(BasicShape(sf::Vector2f(64, 64), sf::Vector2f(128, 256), 0, 1, sf::Color::White));
    collides.push_back(BasicShape(sf::Vector2f(64, 64), sf::Vector2f(128, 320), 0, 1, sf::Color::White));*/
}

void Base::createWindow() {
    window.create(sf::VideoMode(1600 , 900), "SFML works!"/*, sf::Style::Fullscreen*/);
    //window.setFramerateLimit(10);
}

void Base::createPlayer() {
    player.getShape().setSize(sf::Vector2f(64, 64));
    player.getShape().setPosition(sf::Vector2f(64, 32));
    player.getShape().setFillColor(sf::Color::Blue);
}

bool Base::gameLoop() {
    tu.setTime();
    totalTime = tu.getTime();

    bool exit = 0;

    exit =
    checkControls();
    checkMoves();
    drawWindow();

    playerMoveAmount = sf::Vector2f(0, 0);

    return exit;
}

bool Base::checkControls() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
            return 1;
        }
    }

    // Controls.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        playerMoveAmount += sf::Vector2f(0, -calculateFrameStep());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        playerMoveAmount += sf::Vector2f(-calculateFrameStep(), 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        playerMoveAmount += sf::Vector2f(0, calculateFrameStep());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        playerMoveAmount += sf::Vector2f(calculateFrameStep(), 0);
    }

    //if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {}

    return 0;
}

void Base::checkMoves() {
    player.getShape().move(playerMoveAmount);

    for(auto x : collides) {
        sf::RectangleShape playerTmp = player.getShape();
        sf::RectangleShape xTmp = x.getShape();

        sf::Vector2f playerCenter = getRectCenter(playerTmp);
        sf::Vector2f xCenter = getRectCenter(xTmp);

        sf::Vector2f delta = getRectDelta(playerCenter, xCenter);

        sf::Vector2f intersect = (sf::Vector2f(delta.x - ((playerTmp.getSize().x / 2) + (xTmp.getSize().x / 2)), delta.y - ((playerTmp.getSize().y / 2) + (xTmp.getSize().y / 2))));

        //std::cout << "PlayerCenter: " << playerCenter.x << ", " << playerCenter.y << std::endl << "XCenter: " << xCenter.x << ", " << xCenter.y << std::endl << "Delta: " << delta.x << ", " << delta.y << std::endl << "Result: " << result.x << ", " << result.y << std::endl;

        /*if(result.x < 0 && result.y < 0 ) {
            if(result.x > result.y) {
                player.getShape().move(-result.x, 0);
            } else {
                player.getShape().move(0, -result.y);
            }
        }*/

        if(intersect.x < 0 && intersect.y < 0) {
            if(intersect.x > intersect.y) {

                if(delta.x < 0) {
                    player.getShape().move(-intersect.x, 0);
                } else {
                    player.getShape().move(intersect.x, 0);
                }
            } else {

                if(delta.y < 0) {
                    player.getShape().move(0, -intersect.y);
                } else {
                    player.getShape().move(0, intersect.y);
                }
            }
        }

        //https://www.youtube.com/watch?v=l2iCYCLi6MU&ab_channel=HilzeVonck

        /*float a = (getRectangleCenter(player.getShape()).x - getRectangleCenter(player.getShape()).x) - (player.getShape().getSize().x + x.getShape().getSize().x);
        float b = (getRectangleCenter(player.getShape()).x - getRectangleCenter(player.getShape()).x) - (player.getShape().getSize().y + x.getShape().getSize().y);

        if(a < 0 && getRectangleCenter(player.getShape()) - (player.getShape().getSize().x + x.getShape().getSize().x)) {

        }*/
    }
}

/*
sf::RectangleShape tmp = player.getShape();
tmp.move(playerMoveAmount);

for(auto x : collides) {
    if(tmp.getGlobalBounds().intersects(x.getShape().getGlobalBounds())) {
        if(playerMoveAmount.x != 0) {
            if(player.getShape().getPosition().y + player.getShape().getSize().y >= x.getShape().getPosition().y && player.getShape().getPosition().y <= x.getShape().getPosition().y + player.getShape().getSize().y) {
                playerMoveAmount.x = 0;
            }
        }
        if(playerMoveAmount.y != 0) {
            if(player.getShape().getPosition().x + player.getShape().getSize().x >= x.getShape().getPosition().x && player.getShape().getPosition().x <= x.getShape().getPosition().x + player.getShape().getSize().x) {
                playerMoveAmount.y = 0;
            }
        }
    }
}

player.getShape().move(playerMoveAmount);

if(tmp.getGlobalBounds().intersects(x.getShape().getGlobalBounds())) {
    if((player.getShape().getPosition().y >= x.getShape().getPosition().y + x.getShape().getSize().y || player.getShape().getPosition().y <= x.getShape().getPosition().y)
        && (player.getShape().getPosition().x <= x.getShape().getPosition().x + x.getShape().getSize().x && player.getShape().getPosition().x >= x.getShape().getPosition().x - x.getShape().getSize().x)) {
        playerMoveAmount.y = 0;
    }
    if((player.getShape().getPosition().x >= x.getShape().getPosition().x + x.getShape().getSize().x || player.getShape().getPosition().x <= x.getShape().getPosition().x)
        && (player.getShape().getPosition().y <= x.getShape().getPosition().y + x.getShape().getSize().y && player.getShape().getPosition().y >= x.getShape().getPosition().y - x.getShape().getSize().y)) {
        playerMoveAmount.x = 0;
    }
    //break;
}
*/

sf::Vector2f Base::getRectCenter(sf::RectangleShape rect) {
    return sf::Vector2f(rect.getPosition().x + (rect.getSize().x / 2), rect.getPosition().y + (rect.getSize().y / 2));
}
sf::Vector2f Base::getRectDelta(sf::Vector2f rectCenter1, sf::Vector2f rectCenter2) {
    /*if(rectCenter1.x < rectCenter2.x && rectCenter1.y < rectCenter2.y) {
        return sf::Vector2f(rectCenter1.x - rectCenter2.x, rectCenter1.y - rectCenter2.y);
    } else {
        return sf::Vector2f(rectCenter2.x - rectCenter1.x, rectCenter2.y - rectCenter1.y);
    }*/
    return sf::Vector2f(rectCenter1.x - rectCenter2.x, rectCenter1.y - rectCenter2.y);
}

void Base::drawWindow() {
    window.clear(sf::Color::Black);
    window.draw(player.getShape());

    for(auto x : collides) {window.draw(x.getShape());}
    //for(auto x : jigSawPieces) {}

    window.display();
}

float Base::calculateFrameStep() {return (player.getSpeed() * player.getSpeedMultiplier()) * totalTime;}

int Base::getRandomInt(int x, int y) {
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(x, y);

    return distribution(generator);
}

int main() {

    Base b;
    b.createWindow();
    b.createPlayer();

    bool exit = 0;
    while(exit == 0) {
        exit =
        b.gameLoop();
    }

    // Exit program.
    return 0;
}
