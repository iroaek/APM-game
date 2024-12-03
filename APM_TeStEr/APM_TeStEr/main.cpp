#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream> // Pro std::cout
#include "Square.h"
#include "Game.h"
#include "Button.h"

int main() {
    // Nastavení okna
    sf::RenderWindow window(sf::VideoMode(800, 600), "APM Game", sf::Style::Close);
    window.setFramerateLimit(60);

    // Inicializace tlaèítka Start
    Button startButton = Button(300, 250, 100, 50, "Start");
    Button restartButton = Button(150, 450, 100, 50, "Restart");
    Button endButton = Button(450, 450, 100, 50, "END");
    restartButton.enabled = false;
    endButton.enabled = false;
    // Inicializace hry
    Game game(10, 800, 600, "medium"); // 10 ètvercù, støední obtížnost

    bool Running = true;
    bool GameStarted = false;
    bool GameOver = false;
    sf::Clock gameClock; // Mìøení èasu
    sf::Clock frameClock; // Mìøení èasu mezi snímky

    while (Running) {
        // Zpracovávání inputu
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Running = false;
            }

            if (!GameStarted && !GameOver && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (startButton.isClicked(event.mouseButton.x, event.mouseButton.y)) {
                    startButton.enabled = false;
                    GameStarted = true;
                    gameClock.restart(); // Zaèátek hry
                }
            }

            if (GameStarted && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                game.handleMouseClick(event.mouseButton.x, event.mouseButton.y);
            }
            if (GameOver && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (restartButton.isClicked(event.mouseButton.x, event.mouseButton.y)) {
                    startButton.enabled = true;
                    GameOver = false;
                    game.restart();
                    GameStarted = false;
                }
                if (endButton.isClicked(event.mouseButton.x, event.mouseButton.y)) {
                    Running = false;
                }
            }
        }

        // Logika
        float deltaTime = frameClock.restart().asSeconds();
        if (GameStarted) {
            float elapsed = gameClock.getElapsedTime().asSeconds();
            if (elapsed >= 10.0f) { // Po 60 sekundách se hra ukonèí
                GameStarted = false;
                GameOver = true;
                restartButton.enabled = true;
                endButton.enabled = true;
                std::cout << "Game Over! Your Score: " << game.getScore() << std::endl;
            }
            game.update(deltaTime);
        }

        // Renderování
        window.clear();
        if (GameStarted) {
            game.render(window);
        }
        else if (GameOver) {
            restartButton.render(window);
            endButton.render(window);
            game.renderGameOver(window);
        }
        else {
            startButton.render(window);
        }
        window.display();
    }

    return 0;
}
