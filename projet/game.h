#ifndef GAME_H
#define GAME_H

#include "ennemi.h"       // class ennemi
#include "player.h"       // class player
#include "electricwell.h" // class electricwell
#include "missile.h"      // class missile
#include "spike.h"        // class spike
#include <algorithm>      // method find
#include <map>            // map container
#include <random>         // random toolbox

/* Main class of the project. It has the list of the currently displayed
 * ennemies and the currently displayed electric well as the player class as
 * well. It also contains two int, one for the current level and one for the
 * score. Those int are for display purpose.
 */
class Game
{
private:
    enum enm_types_
    {
        Flipper,
        Tanker_flipper,
        Tanker_fuseball,
        Tanker_pulsar,
        Spiker,
        Fuseball,
        Pulsar
    }; // All the ennemi types

public:
    Player player_;                            // The player's blaster
    std::vector<Ennemi> ennemi_list_;          // Current scene ennemies list
    std::vector<Missile> ennemi_missile_list_; // All the missiles launched by the ennemies
    std::vector<Missile> player_missile_list_; // All the missiles launched by the player
    std::vector<Spike> spike_list_;            // The list of all the printed spikes
    ElectricWell electric_well_;               // Current electric well
    int level_;                                // Current level
    int score_;                                // Current score

public:
    // Constructors
    Game(Player &player,
         const ElectricWell &well,
         const int &lvl,
         const int &scr);

    // Game controls
    bool endGame();                          // Stops the game and goes to the end screen
    void addCharacter(Ennemi &car);          // Adds car to the character_list_
    void removeCharacter(const Ennemi &car); // Removes car from the caracter_list_
    void levelUp();                          // Increases level_ and changes the EW color and shape
    void addScore(const std::string &type);  // Adds to the score the car.type corresponding value
    bool collisionTest(const int &test_nb);  // Tests if there is a collision

    // IO
    void printAvoidSpikes(); // Prints the "Avoid Spikes" message in the middle of the screen
    void printScore();       // Prints the current score
    void printLevel();       // Prints the current level
    void printEndScreen();   // Prints the end screen

private:
    enm_types_ resolve(std::string type);
};

#endif // GAME_H