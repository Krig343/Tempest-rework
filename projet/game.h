#ifndef GAME_H
#define GAME_H

#include "character.h"    // class character
#include "electricwell.h" // class electricwell
#include <vector>         // container vector

/* Main class of the project. It has the list of the currently displayed
 * caracters and the currently displayed electric well. It also contains two int,
 * one for the current level and one for the score. Those int are for display
 * purpose.
 */
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
    void endGame();                      // Stops the game and goes to the end screen
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