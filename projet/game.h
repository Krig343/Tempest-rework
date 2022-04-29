#ifndef GAME_H
#define GAME_H

#include "enemy.h"        // class enemy
#include "player.h"       // class player
#include "electricwell.h" // class electricwell
#include "missile.h"      // class missile
#include "spike.h"        // class spike
#include <algorithm>      // method find
#include <map>            // map container
#include <random>         // random toolbox
#include "text.h"         // simplex list for text draw

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
        Flipper,
        Tanker_flipper,
        Tanker_fuseball,
        Tanker_pulsar,
        Spiker,
        Fuseball,
        Pulsar
    }; // All the enemy types

public:
    Player player_;                            // The player's blaster
    std::vector<Enemy> ennemi_list_;           // Current scene ennemies list
    std::vector<Missile> ennemi_missile_list_; // All the missiles launched by the ennemies
    std::vector<Missile> player_missile_list_; // All the missiles launched by the player
    std::vector<Spike> spike_list_;            // The list of all the printed spikes
    ElectricWell electric_well_;               // Current electric well
    int level_;                                // Current level
    int score_;                                // Current score

public:
    // Constructors
    Game();

    // Game controls
    bool endGame(SDL_Renderer *renderer); // Stops the game and goes to the end screen
    inline void addCharacter(Enemy &car)
    {
        ennemi_list_.push_back(car);
    }; // Adds car to the character_list_
    template <class T>
    void removeObject(const T &rem_obj); // Removes rem_obj from the correct list
    template <class T>
    void levelUp();                         // Increases level_ and changes the EW color and shape
    void addScore(const std::string &type); // Adds to the score the car.type corresponding value
    void collisionTest();                   // Tests if there is a collision
    void update();                          // Update game state
    void movePlayer(int movement);          // Change the lane of the player
    inline void addPlayerMissile(int lane)
    {
        player_missile_list_.push_back(Missile(lane, 0.0));
    };                // Spawn a player missile
    void useZapper(); // Sets used_zapper_ to true

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