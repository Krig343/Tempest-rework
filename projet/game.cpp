#include "game.h"

//----------------------------- Constructors -----------------------------------

Game::Game(const Player &player, const std::vector<Ennemi> &enm_list, const ElectricWell &well, const int &lvl, const int &scr) : player_{player},
                                                                                                                                  ennemi_list_{enm_list},
                                                                                                                                  electric_well_{well},
                                                                                                                                  level_{lvl},
                                                                                                                                  score_{scr}
{
}

//---------------------------- Game controls -----------------------------------

/* The game should stop (ie. go to the end screen) when, either the player
 * has no lives left, or when he finishes level 99
 */
bool Game::endGame()
{
    if (player_.lives_ == 0 || (level_ == 99 && ennemi_list_.size() == 0))
    {
        printEndScreen();
        return true;
    }
    return false;
}

/* This function searches for the character car in the ennemi list and removes
 * it when found and stops with an error message if not
 */
void Game::removeCharacter(const Ennemi &car)
{
    auto car_index = std::find(ennemi_list_.begin(), ennemi_list_.end(), car);
    if (car_index == ennemi_list_.end())
    {
        std::cout << "L'élément " << car.index_ << " n'est pas dans la liste" << std::endl;
        exit(EXIT_FAILURE);
    }
    else
        ennemi_list_.erase(car_index);
}

Game::enm_types_ Game::resolve(std::string type)
{
    static const std::map<std::string, enm_types_> typeStrings{
        {"Flipper", Flipper},
        {"Tanker_flipper", Tanker_flipper},
        {"Tanker_fuseball", Tanker_fuseball},
        {"Tanker_pulsar", Tanker_pulsar},
        {"Spiker", Spiker},
        {"Fuseball", Fuseball},
        {"Pulsar", Pulsar}};

    auto itr = typeStrings.find(type);
    if (itr != typeStrings.end())
    {
        return itr->second;
    }
    std::cout << "Le type " << type << " n'existe pas" << std::endl;
    exit(EXIT_FAILURE);
}

void Game::addScore(const std::string &type)
{
    switch (resolve(type))
    {
    case Game::Flipper:
        score_ += 150;
        break;
    case Game::Tanker_flipper:
        score_ += 100;
        break;
    case Game::Tanker_fuseball:
        score_ += 100;
        break;
    case Game::Tanker_pulsar:
        score_ += 100;
        break;
    case Game::Spiker:
        score_ += 50;
        break;
    case Game::Fuseball: // Add 500 and 750
        score_ += 250;
        break;
    case Game::Pulsar:
        score_ += 200;
        break;
    };
}

/* Return true if the players lane corresponds to an ennemi's lane
 */
bool Game::collisionTest()
{
    // TODO
}

//--------------------------------- IO -----------------------------------------

/* Prints the string "avoid spikes" on the middle top of the screen
 */
void Game::printAvoidSpikes()
{
    // TODO
}

/* Prints continiously the score on top of the screen
 */
void Game::printScore()
{
    // TODO
}

/* Prints continiously the level on top left of the screen
 */
void Game::printLevel()
{
    // TODO
}

/* Erases the screen and prints "game over", the score and the level in the
 * center of the screen
 */
void Game::printEndScreen()
{
    // TODO
}
