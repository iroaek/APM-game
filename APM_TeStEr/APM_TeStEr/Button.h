#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;

public:
    Button(float x, float y, float width, float height, const std::string& label);
    bool enabled;
    void render(sf::RenderWindow& window);
    bool isClicked(float mouseX, float mouseY) const;
};

#endif