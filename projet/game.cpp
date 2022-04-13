#include "game.h"

// Constructors
Game::Game(const std::vector<Character> &car_list, const ElectricWell &well, const int &lvl, const int &scr) : character_list_{car_list},
                                                                                                               electric_well_{well},
                                                                                                               level_{lvl},
                                                                                                               score_{scr}
{
}

// Game controls
bool Game::endGame()
{
    if (collisionTest)
    {
        printEndScreen();
        return true;
    }
    return false;
}

void Game::addCharacter(Character car)
{
    character_list_.insert(character_list_.end(), car);
}

void Game::removeCharacter(const Character *car)
{
    auto car_index = std::find(character_list_.begin(), character_list_.end(), car);
    if (car_index == character_list_.end())
    {
        std::cout << "L'élément " << car->index_ << " n'est pas dans la liste" << std::endl;
        exit(EXIT_FAILURE);
    }
    else
        character_list_.erase(car_index);
}

void Game::levelUp()
{
    ++level_;
}

void Game::addScore(const int *score)
{
    score_ += *score;
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

void Game::printEndScreen()
{
    // TODO
}
