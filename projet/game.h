#ifndef GAME_H
#define GAME_H

#include "character.h"    // classe character
#include "electricwell.h" // classe electricwell
#include <vector>         // container vector

class Game
{
private:
    std::vector<Character> caracter_list_; // Current scene caracter list
    ElectricWell electric_well_;           // Current electric well
    int level_;                            // Current level
    int score_;                            // Current score

public:
    // Constructors
    Game(const std::vector<Character> &car_list, const ElectricWell &well, const int &lvl, const int &scr);
    ~Game() = default;

    // Game controls
    bool endGame();                      // Stops the game and goes to the end screen
    void addCharacter(Character car);    // Adds a car to the caracter_list_
    void removeCharacter(Character car); // Removes car from the caracter_list_
    void levelUp();                      // Increases level_ and goes to the next stage
    void addScore(int score);            // Adds to the score the car.type corresponding value
    bool collisionTest();                // Tests if the player collides with a caracter

    // IO
    void printAvoidSpikes(); // Prints the "Avoid Spikes" message in the middle of the screen
    void printScore();       // Prints the current score
    void printLevel();       // Prints the current level
};

#endif // GAME_H