#ifndef GAME_H
#define GAME_H

#include "player.h"       // class player
#include "character.h"
#include "electricwell.h" // class electricwell
#include "missile.h"      // class missile
#include "flipper.h"
#include "tanker.h"
#include <algorithm>      // method find
#include <map>            // map container
#include <random>         // random toolbox
#include <memory>

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
        Flipper_t,
        Tanker_flipper_t,
        Tanker_fuseball_t,
        Tanker_pulsar_t,
        Spiker_t,
        Fuseball_t,
        Pulsar_t
    }; // All the ennemi types

public:
    Player player_;                                     // The player's blaster
    std::vector<Flipper> flipper_list_;                 // Current scene flippers list
    std::vector<Tanker> tanker_list_;                 // Current scene tankers list
    std::vector<Missile> ennemy_missile_list_;          // All the missiles launched by the ennemies
    std::vector<Missile> player_missile_list_;          // All the missiles launched by the player
    //std::vector<Spike> spike_list_;                   // The list of all the printed spikes
    ElectricWell electric_well_;                        // Current electric well
    int level_;                                         // Current level
    int score_;                                         // Current score
    unsigned long time_;                                // Game "time"
 
public:
    // Constructors
    Game();

    // Game controls
    void update();                              // Update game state
    bool endGame();                             // Stops the game and goes to the end screen
    void addPlayerMissile(int lane);            // Spawn a player missile      
    void spawnEnnemies();                       // Spawn all relevant ennemies according to time_
    void levelUp();                             // Increases level_ and changes the EW color and shape
    void addScore(const std::string &type);     // Adds to the score the car.type corresponding value
    bool collisionTest(const int &lane1,        // Tests if there is a collision
                       const int &lane2, 
                       const float &pos1, 
                       const float &pos2);     

    // IO
    void printAvoidSpikes(); // Prints the "Avoid Spikes" message in the middle of the screen
    void printScore();       // Prints the current score
    void printLevel();       // Prints the current level
    void printEndScreen();   // Prints the end screen

    // Draw
    void draw(SDL_Renderer *renderer);

private:
    enm_types_ resolve(std::string type);
};

#endif // GAME_H