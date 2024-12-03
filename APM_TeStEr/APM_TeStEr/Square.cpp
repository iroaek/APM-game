#include "Square.h"
#include <cstdlib>
#include <ctime>

Square::Square(int x, int y, float size, const sf::Color& color) {
    shape.setSize(sf::Vector2f(size, size));
    setnewposition(x, y);
    shape.setFillColor(color);
    visible = false; // Ètverec je neviditelný na zaèátku
    timeElapsed = 0;
}
void Square::setnewposition(int x, int y) {
    float posx = std::rand() % (x - 50);
    float posy = std::rand() % (y - 50);
    shape.setPosition(posx, posy);
}

void Square::update(float deltaTime) {
    if (visible) {
        timeElapsed += deltaTime;
        if (timeElapsed >= timeToAppear or remove) {
            visible = false; // Ètverec se schová po uplynutí doby
            remove = true;
            timeElapsed = 0;
        }
    }
}

void Square::render(sf::RenderWindow& window) {
    if (visible) {
        window.draw(shape);
    }
}

bool Square::isClicked(float mouseX, float mouseY) const {
    return visible && shape.getGlobalBounds().contains(mouseX, mouseY);
}

bool Square::isVisible() const {
    return visible;
}

void Square::activate(float duration, int x, int y) {
    //setnewposition(x, y);
    visible = true;
    remove = false;
    timeToAppear = duration;
    timeElapsed = 0;
}