#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Square.h"

class Game {
private:
    std::vector<Square> squares;
    int score;
    int misses;
    int clicks;
    int effectiveClicks;  // Po�et efektivn�ch kliknut�
    float apm;
    float epm;  // Effective Actions Per Minute
    float elapsedSeconds;
    float difficultyMultiplier;

public:
    Game(int squareCount, int windowWidth, int windowHeight, const std::string& difficulty);
    void restart();
    bool handleMouseClick(float mouseX, float mouseY);
    void update(float deltaTime);
    void render(sf::RenderWindow& window);
    void renderGameOver(sf::RenderWindow& window);
    int getScore() const; // Getter pro sk�re
    sf::Font font;
    int windowW;
    int windowH;
};

#endif