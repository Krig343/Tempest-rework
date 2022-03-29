#include "game.h"

//----------------------------- Constructors -----------------------------------

Game::Game(const std::vector<Character> &car_list, const ElectricWell &well, const int &lvl, const int &scr) : caracter_list_{car_list},
                                                                                                               electric_well_{well},
                                                                                                               level_{lvl},
                                                                                                               score_{scr}
{
}

//---------------------------- Game controls -----------------------------------

/* The game should stop (ie. got to the end screen) when, either the player
 * has no lives left, or when he finishes level 99
 */
void Game::endGame()
{
    // TODO
}

void Game::addCharacter(Character car)
{
    caracter_list_.insert(caracter_list_.end(), car);
}

void Game::removeCharacter(Character car)
{
    // not the correct car
    caracter_list_.pop_back();
}

void Game::levelUp()
{
    ++level_;
}

void Game::addScore(int score)
{
    score_ += score;
}

/* Return true if the players lane corresponds to an ennemis lane
 */
bool Game::collisionTest()
{
    // TODO
}

//--------------------------------- IO -----------------------------------------

/* Just print the string "avoid spikes" on the middle top of the screen
 */
void Game::printAvoidSpikes()
{
    // TODO
}

void Game::printScore()
{
    // TODO
}

void Game::printLevel()
{
    // TODO
}