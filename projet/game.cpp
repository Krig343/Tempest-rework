#include "game.h"

//----------------------------- Constructors -----------------------------------

Game::Game(Player &player,
           const ElectricWell &well,
           const int &lvl,
           const int &scr) : player_{player},
                             electric_well_{well},
                             level_{lvl},
                             score_{scr}
{
}

//---------------------------- Game controls -----------------------------------

/* The game should stop (ie. go to the end screen) when, either the player
 * has no lives left, or when he finishes level 99. Return true so the main
 * script known he has to exit th egame loop. If false is returned the nothing
 * appens
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

void Game::addCharacter(Ennemi &car)
{
    ennemi_list_.emplace_back(car);
}

/* This function searches for the character car in the ennemi list and removes
 * it when found and stops with an error message if not
 */
void Game::removeCharacter(const Ennemi &car)
{
    auto car_index = std::find(ennemi_list_.begin(), ennemi_list_.end(), car);
    if (car_index == ennemi_list_.end())
    {
        std::cout << "L'élément " << car.type_ << " n'est pas dans la liste" << std::endl;
        exit(EXIT_FAILURE);
    }
    else
        ennemi_list_.erase(car_index);
}

void Game::levelUp()
{
    ++level_;

    if (level_ < 97)
    {
        switch (level_ % 16) // The list starts again every 16 levels until level 97
        {
        case 1:
            electric_well_.shape_ = "Circle";
            break;
        case 2:
            electric_well_.shape_ = "Square";
            break;
        case 3:
            electric_well_.shape_ = "Plus";
            break;
        case 4:
            electric_well_.shape_ = "Binoculars";
            break;
        case 5:
            electric_well_.shape_ = "Cross";
            break;
        case 6:
            electric_well_.shape_ = "Triangle";
            break;
        case 7:
            electric_well_.shape_ = "X";
            break;
        case 8:
            electric_well_.shape_ = "V";
            break;
        case 9:
            electric_well_.shape_ = "Staires";
            break;
        case 10:
            electric_well_.shape_ = "U";
            break;
        case 11:
            electric_well_.shape_ = "Flat";
            break;
        case 12:
            electric_well_.shape_ = "Heart";
            break;
        case 13:
            electric_well_.shape_ = "Star";
            break;
        case 14:
            electric_well_.shape_ = "W";
            break;
        case 15:
            electric_well_.shape_ = "Bird";
            break;
        case 0:
            electric_well_.shape_ = "Infinite";
            break;
        }
    }
    else // From level 97 the levels are chosen randomly
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, 16);
        auto rndm_level = distrib(gen);
        switch (rndm_level)
        {
        case 1:
            electric_well_.shape_ = "Circle";
            break;
        case 2:
            electric_well_.shape_ = "Square";
            break;
        case 3:
            electric_well_.shape_ = "Plus";
            break;
        case 4:
            electric_well_.shape_ = "Binoculars";
            break;
        case 5:
            electric_well_.shape_ = "Cross";
            break;
        case 6:
            electric_well_.shape_ = "Triangle";
            break;
        case 7:
            electric_well_.shape_ = "X";
            break;
        case 8:
            electric_well_.shape_ = "V";
            break;
        case 9:
            electric_well_.shape_ = "Staires";
            break;
        case 10:
            electric_well_.shape_ = "U";
            break;
        case 11:
            electric_well_.shape_ = "Flat";
            break;
        case 12:
            electric_well_.shape_ = "Heart";
            break;
        case 13:
            electric_well_.shape_ = "Star";
            break;
        case 14:
            electric_well_.shape_ = "W";
            break;
        case 15:
            electric_well_.shape_ = "Bird";
            break;
        case 16:
            electric_well_.shape_ = "Infinite";
            break;
        }
    }

    switch (level_) // Change the color for the next set of levels
    {
    case 17:
        electric_well_.color_ = {255, 0, 0, 255}; //
        break;
    case 33:
        electric_well_.color_ = {255, 255, 0, 255};
        break;
    case 49:
        electric_well_.color_ = {0, 255, 255, 255};
        break;
    case 65:
        electric_well_.color_ = {0, 0, 0, 255};
        break;
    case 81:
        electric_well_.color_ = {0, 255, 0, 255};
        break;
    }
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

/* Tests the collision between objects. The collision test depends on the number
 * test_nb.
 * - 1 : collision test between an ennemi and the player
 * - 2 : collision between an ennemi and a missile
 * - 3 : collision between the player and a missile
 * - 4 : collision between the player and a Spike (maybe it will be an ennemi)
 */
bool Game::collisionTest(const int &test_nb)
{
    switch (test_nb)
    {
    case 1:
        for (auto e : ennemi_list_)
        {
            if (player_.position_ == e.position_)
                return true;
        }
        break;
    case 2:
        // Collision between player's missiles and ennemies
        break;
    case 3:
        // Collision between player and ennemie's missiles
        break;
    case 4:
        // Collision between player and spike
        break;
    }
}

//--------------------------------- IO -----------------------------------------

void Game::printLetter(const int &letter_index, const int &offset, SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 2; i < 112; i += 2)
    {
        int x1 = simplex[letter_index][i];
        int y1 = simplex[letter_index][i + 1];
        int x2 = simplex[letter_index][i + 2];
        int y2 = simplex[letter_index][i + 3];
        if (x1 != -1 && y1 != -1 && x2 != -1 && y2 != -1)
            SDL_RenderDrawLine(renderer, x1 + offset, -y1 + 50, x2 + offset, -y2 + 50);
    }
}

/* Prints the string "avoid spikes" on the middle top of the screen
 */
void Game::printAvoidSpikes(SDL_Renderer *renderer)
{
    // TODO
    int offset = 200;
    // C = 35
    printLetter(35, offset, renderer);
    offset += simplex[35][1];
    // O = 47
    printLetter(47, offset, renderer);
    offset += simplex[47][1];
    // U = 53
    printLetter(53, offset, renderer);
    offset += simplex[53][1];
    // C = 35
    printLetter(35, offset, renderer);
    offset += simplex[35][1];
    // O = 47
    printLetter(47, offset, renderer);
    offset += simplex[47][1];
    // U = 53
    printLetter(53, offset, renderer);
}

/* Prints continiously the score on top of the screen
 */
void Game::printScore(SDL_Renderer *renderer)
{
    // TODO
}

/* Prints continiously the level on top left of the screen
 */
void Game::printLevel(SDL_Renderer *renderer)
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
