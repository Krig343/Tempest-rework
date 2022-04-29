#ifndef GAME_H
#define GAME_H

#include "player.h"       // class player
#include "character.h"    // class caracter
#include "electricwell.h" // class electricwell
#include "missile.h"      // class missile
#include "flipper.h"      // class flipper
#include "tanker.h"       // class tanker
#include <algorithm>      // method find
#include <map>            // map container
#include <random>         // random toolbox
#include <memory>
#include "text.h" // simplex list for text draw

using namespace Text;

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
        Tanker_t,
        Spiker_t,
        Fuseball_t,
        Pulsar_t
    }; // All the ennemi types

public:
    Player player_;                     // The player's blaster
    std::vector<Flipper> flipper_list_; // Current scene flippers list
    std::vector<Tanker> tanker_list_;   // Current scene tankers list
    // std::vector<Missile> ennemy_missile_list_; // All the missiles launched by the ennemies
    std::vector<Missile> player_missile_list_; // All the missiles launched by the player
    // std::vector<Spike> spike_list_;                   // The list of all the printed spikes
    ElectricWell electric_well_; // Current electric well
    int level_;                  // Current level
    int score_;                  // Current score
    unsigned long time_;         // Game "time"

public:
    // Constructors
    Game();

    // Game controls
    bool endGame(SDL_Renderer *renderer); // Stops the game and goes to the end screen
    // template <class T>
    // void removeObject(const T &rem_obj); // Removes rem_obj from the correct list
    template <class T>
    void levelUp();                         // Increases level_ and changes the EW color and shape
    void addScore(const std::string &type); // Adds to the score the car.type corresponding value
    // void collisionTest();                   // Tests if there is a collision
    void update();                       // Update game state
    void movePlayer(int movement);       // Change the lane of the player
    void useZapper();                    // Sets used_zapper_ to true
    void addPlayerMissile(int lane);     // Spawn a player missile
    void spawnEnnemies();                // Spawn all relevant ennemies according to time_
    bool collisionTest(const int &lane1, // Tests if there is a collision
                       const int &lane2,
                       const float &pos1,
                       const float &pos2);

    // IO
    void printAvoidSpikes(SDL_Renderer *renderer); // Prints the "Avoid Spikes" message in the middle of the screen
    void printScore(SDL_Renderer *renderer);       // Prints the current score
    void printLevel(SDL_Renderer *renderer);       // Prints the current level
    void printEndScreen(SDL_Renderer *renderer);   // Prints the end screen

    // Draw
    void draw(SDL_Renderer *renderer);

private:
    enm_types_ resolve(std::string type); // Given string type, it returns the corresponding enemy type from the enum
    void printLetter(const int &letter_index,
                     const int &offset_x,
                     const int &offset_y,
                     SDL_Renderer *renderer);                 // Prints the symbol from simples at the letter_index line
    const int computeOffset(const std::vector<int> &letters); // Computs the width of the word stored in letters
    const std::vector<int> decomposeNumbers(const int &number,
                                            const bool &is_level); // Decompose number in the corresponding symbols from simplex
    void printMessage(const std::vector<int> &indexes,
                      SDL_Renderer *renderer,
                      const int &w,
                      const int &offset_y); // Prints the symbols from simplex stored in indexes
};

#endif // GAME_H