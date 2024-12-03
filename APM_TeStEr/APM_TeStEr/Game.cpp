#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Game::Game(int squareCount, int windowWidth, int windowHeight, const std::string& difficulty)
    : score(0), misses(0), clicks(0), effectiveClicks(0), apm(0), epm(0), elapsedSeconds(0) {
    windowW = windowWidth;
    windowH = windowHeight;
    // Nastaven� obt�nosti
    if (difficulty == "easy") {
        difficultyMultiplier = 0.5f;
    }
    else if (difficulty == "medium") {
        difficultyMultiplier = 1.0f;
    }
    else if (difficulty == "hard") {
        difficultyMultiplier = 1.5f;
    }
    else {
        difficultyMultiplier = 1.0f; // V�choz� obt�nost
    }

    font.loadFromFile("arial.ttf");

    // Generov�n� �tverc�
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (int i = 0; i < squareCount; ++i) {
        
        sf::Color color = sf::Color(std::rand() % 256, std::rand() % 256, std::rand() % 256); // N�hodn� barva
        squares.emplace_back(windowWidth, windowHeight, 50.0f, color); // Pou�it� nov�ho konstruktoru
    }
}

bool Game::handleMouseClick(float mouseX, float mouseY) {
    clicks++;
    for (int i = 0; i < squares.size(); i++) {
        if (squares[i].isClicked(mouseX, mouseY)) {
            score++;
            effectiveClicks++;
            squares[i].remove = true;
            return true;
        }
    }
    misses++;
    return false;
}

void Game::update(float deltaTime) {
    elapsedSeconds += deltaTime;

    for (Square& square : squares) {
        square.update(deltaTime);
        if (!square.isVisible() && std::rand() % 100 < 2 * difficultyMultiplier) {
            square.activate(2.0f / difficultyMultiplier, windowW, windowH); // Rychlej�� obt�nost = krat�� �as
        }
    }

    // V�po�et APM a EPM
    if (elapsedSeconds >= 1.0f) {
        apm = clicks / elapsedSeconds * 60.0f;
        epm = effectiveClicks / elapsedSeconds * 60.0f;
    }
}

void Game::render(sf::RenderWindow& window) {   
    for (int i = 0; i < squares.size(); i++) {     
            squares[i].render(window);
    }

    // Zobrazen� statistik
    
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score: " + std::to_string(score));
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);
    window.draw(scoreText);

    sf::Text apmText;
    apmText.setFont(font);
    apmText.setString("APM: " + std::to_string(static_cast<int>(apm)));
    apmText.setCharacterSize(24);
    apmText.setFillColor(sf::Color::White);
    apmText.setPosition(10, 40);
    window.draw(apmText);
}

void Game::renderGameOver(sf::RenderWindow& window) {
    // �ern� pozad�
    //window.clear(sf::Color::Black);

    // Vytvo�en� kruhu pro APM
    sf::CircleShape circle(100);
    circle.setFillColor(sf::Color(100, 100, 255));
    circle.setPosition(150, 200);

    // Text pro APM
    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text apmText;
    apmText.setFont(font);
    apmText.setString("APM: " + std::to_string(static_cast<int>(apm)) + "\nActions Per Minute \n= \nAll clicks including \nmissed ones.");
    apmText.setCharacterSize(18);
    apmText.setFillColor(sf::Color::White);
    apmText.setPosition(175, 250);

    // Vytvo�en� kruhu pro EPM
    sf::CircleShape epmCircle(100);
    epmCircle.setFillColor(sf::Color(255, 100, 100));
    epmCircle.setPosition(400, 200);

    // Text pro EPM
    sf::Text epmText;
    epmText.setFont(font);
    epmText.setString("EPM: " + std::to_string(static_cast<int>(epm)) + "\nEffective Actions \nPer Minute \n= \nOnly valid clicks.");
    epmText.setCharacterSize(18);
    epmText.setFillColor(sf::Color::White);
    epmText.setPosition(425, 250);

    window.draw(circle);
    window.draw(apmText);
    window.draw(epmCircle);
    window.draw(epmText);
}
void Game::restart() {
    score = 0; misses = 0; clicks = 0; effectiveClicks = 0; apm = 0; epm = 0; elapsedSeconds = 0;
}

int Game::getScore() const {
    return score;
}