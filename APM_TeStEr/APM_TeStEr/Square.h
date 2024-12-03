#ifndef SQUARE_H
#define SQUARE_H

#include <SFML/Graphics.hpp>

class Square {
private:
    sf::RectangleShape shape;
    bool visible;
    float timeToAppear = 0;
    float timeElapsed;
    void setnewposition(int x, int y);

public:
    Square(int x, int y, float size, const sf::Color& color); // Konstruktor pro ètverec

    void update(float deltaTime);
    void render(sf::RenderWindow& window);
    bool isClicked(float mouseX, float mouseY) const;
    bool isVisible() const;
    void activate(float duration, int x, int y);
    bool remove = false;
};

#endif