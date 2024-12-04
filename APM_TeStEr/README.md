# **APM & EPM Game**

APM & EPM Game is a simple **Actions Per Minute (APM)** and **Effective Actions Per Minute (EPM)** tracking game developed in **C++** using the **SFML** library. The game challenges the player to click on randomly appearing squares as quickly and accurately as possible within 60 seconds.

## **Features**
- **Customizable Gameplay:**
  - Choose the number of squares and difficulty level.
  - Randomized square colors and positions.
  
- **APM and EPM Metrics:**
  - **APM** (Actions Per Minute) measures all player actions.
  - **EPM** (Effective Actions Per Minute) counts only accurate clicks.
  
- **Game Flow:**
  - Click "START" to begin the game.
  - Play for 60 seconds while clicking on visible squares.
  - View results and options to restart or exit at the end.
  
- **Dynamic UI:**
  - Clean interface with buttons for start, restart, and exit.
  - End screen displays calculated **APM** and **EPM**.

## **How to Play**
- **Start the Game:**
  - Run the program and click the "START" button.
  
- **Play:**
  - Click on the squares as they appear on the screen.
  - Be quick and precise! Clicking on invisible squares will not count.
  
- **View Results:**
  - After 60 seconds, the game ends.
  - The end screen will display your **APM** and **EPM** metrics.
  
- **Restart or Exit:**
  - Click "RESTART" to play again or "END" to close the game.

## **Controls**
- **Mouse:**
  - Left-click on visible squares to score points.
  - Use the mouse to interact with buttons (Start, Restart, Exit).

## **Build Instructions**

### **Prerequisites:**
- Install **C++ compiler** (e.g., GCC or Visual Studio).
- Install **SFML library** ([Download SFML](https://www.sfml-dev.org/download.php)).

### **Build the game:**

- Use CMake or your preferred IDE (e.g., Visual Studio) to build the project.
- Make sure SFML is linked correctly.
### **Run the Game:**
- Execute the compiled binary to start the game.
Code Structure
plaintext

## **Code Structure**
```plaintext
├── src
│   ├── main.cpp          # Entry point of the game
│   ├── Game.cpp          # Core game logic
│   ├── Square.cpp        # Square behavior (visibility, click handling)
│   ├── Button.cpp        # Button logic (Start, Restart, Exit)
│
├── include
│   ├── Game.h            # Header for Game class
│   ├── Square.h          # Header for Square class
│   ├── Button.h          # Header for Button class
│
├── assets
│   ├── arial.ttf         # Font for UI text
│
└── README.md             # Project documentation
```

## **Dependencies**
- SFML 2.5.1+Graphics, window handling, and event management.
- C++17 or higher.
## **Acknowledgments**
- SFML Library: Simple and Fast Multimedia Library.
- Inspired by classic APM trackers in strategy games like StarCraft.
## **Future Enhancements**
- Add sound effects for clicks and button interactions.
- Introduce multiple difficulty levels with varying square visibility durations.
- Save high scores for players to track their performance.
## **License**
This project is licensed under the MIT License. You are free to modify and distribute this software as per the license terms.
