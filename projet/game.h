#ifndef GAME_H
#define GAME_H

#include "character.h"    // class character
#include "electricwell.h" // class electricwell
#include <vector>         // container vector
#include <algorithm>      // method find

/* Main class of the project. It has the list of the currently displayed
 * caracters and the currently displayed electric well. It also contains two int,
 * one for the current level and one for the score. Those int are for display
 * purpose.
 */
class Game
{
private:
    std::vector<Character> character_list_; // Current scene character list
    ElectricWell electric_well_;            // Current electric well
    int level_;                             // Current level
    int score_;                             // Current score

public:
    // Constructors
    Game(const std::vector<Character> &car_list, const ElectricWell &well, const int &lvl, const int &scr);

    // Game controls
    bool endGame();                             // Stops the game and goes to the end screen
    void addCharacter(Character car);           // Adds a car to the caracter_list_
    void removeCharacter(const Character *car); // Removes character car from the caracter_list_
    void levelUp();                             // Increases level_ and goes to the next stage
    void addScore(const int *score);            // Adds to the score the car.type corresponding value
    bool collisionTest();                       // Tests if the player collides with a caracter

    // IO
    void printAvoidSpikes(); // Prints the "Avoid Spikes" message in the middle of the screen
    void printScore();       // Prints the current score
    void printLevel();       // Prints the current level
    void printEndScreen();   // Prints the end screen
};

#endif // GAME_H