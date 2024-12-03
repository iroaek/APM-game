#include "Button.h"

Button::Button(float x, float y, float width, float height, const std::string& label) {
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::Red);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(2.0f);

    if (!font.loadFromFile("arial.ttf")) {
        throw std::runtime_error("Failed to load font!");
    }

    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setPosition(
        x + (width - text.getLocalBounds().width) / 2,
        y + (height - text.getLocalBounds().height) / 2
    );
}

void Button::render(sf::RenderWindow& window) {
    if (enabled) {
        window.draw(shape);
        window.draw(text);
    }
}

bool Button::isClicked(float mouseX, float mouseY) const {
    if (enabled) {
        return shape.getGlobalBounds().contains(mouseX, mouseY);
    }
}