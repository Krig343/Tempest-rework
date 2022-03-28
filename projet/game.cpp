#include "game.h"

// Constructors
Game::Game(const std::vector<Character> &car_list, const ElectricWell &well, const int &lvl, const int &scr) : caracter_list_{car_list},
                                                                                                               electric_well_{well},
                                                                                                               level_{lvl},
                                                                                                               score_{scr}
{
}

// Game controls
bool Game::endGame()
{
    // Ajout juste pour créer la branche gameplay
    if (collisionTest)
        return true;
    // TODO
}

void Game::addCharacter(Character car)
{
    caracter_list_.insert(caracter_list_.end(), car);
}

void Game::removeCharacter(Character car)
{
    // Pas le bon car
    caracter_list_.pop_back();
}

void Game::levelUp()
{
    ++level_;
    // TODO
}

void Game::addScore(int score)
{
    score_ += score;
}

bool Game::collisionTest()
{
    // TODO
}

// IO
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
