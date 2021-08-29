//include classes and headers
#include "../inc/common.hpp"
#include "TimeUtil.hpp"

class Base {
private:
    TimeUtil tu;
    float totalTime = 0;

    sf::RenderWindow window;
    sf::RectangleShape player;

    sf::Vector2f playerMoveAmount;
    float playerSpeed = 100;
    int speedMultiplier = 1;

public:
    Base();

    void createWindow();
    void createPlayer();

    bool gameLoop();
    bool checkControls();
    void checkMoves();
    void drawWindow();

    float calculateFrameStep();

    int getRandomInt(int x, int y);
};

Base::Base() {
    tu.setTime();
}

void Base::createWindow() {
    window.create(sf::VideoMode(1600 , 900), "SFML works!"/*, sf::Style::Fullscreen*/);
    //window.setFramerateLimit(10);
}

void Base::createPlayer() {
    player.setSize(sf::Vector2f(32, 32));
    player.setPosition(sf::Vector2f(32, 32));
    player.setFillColor(sf::Color::White);
}

bool Base::gameLoop() {
    tu.setTime();
    totalTime = tu.getTime();

    bool exit = 0;

    exit =
    checkControls();
    //checkMoves();
    drawWindow();

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
        playerMoveAmount = sf::Vector2f(0, -calculateFrameStep());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        playerMoveAmount = sf::Vector2f(-calculateFrameStep(), 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        playerMoveAmount = sf::Vector2f(0, calculateFrameStep());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        playerMoveAmount = sf::Vector2f(calculateFrameStep(), 0);
    }

    //std::cout << totalTime << std::endl;


    //if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {}

    return 0;
}

void Base::drawWindow() {
    window.clear(sf::Color::Black);
    window.draw(player);

    //for(auto x : gridLines) {}
    //for(auto x : jigSawPieces) {}

    window.display();
}

float Base::calculateFrameStep() {return (playerSpeed * speedMultiplier) * totalTime;}

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
