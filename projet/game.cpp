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
bool Game::endGame(SDL_Renderer *renderer)
{
    if (player_.lives_ == 0 || (level_ == 99 && ennemi_list_.size() == 0))
    {
        printEndScreen(renderer);
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

/* This function returns the ennemi type from the enm_types_ enum corresponding
 * to the type string in input
 */
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

/* This function adds one to the current level and modifies the shape and the color
 * of the electricwell, as well as the color of the ennemies and the player
 */
template <class T>
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

    std::array<Uint8, 4> color_flipper;
    std::array<Uint8, 4> color_tanker;
    std::array<Uint8, 4> color_spiker;
    std::array<Uint8, 4> color_pulsar;

    // Ce serait cool de pouvoir la templater pour faire passer les spikes et les ennemies
    auto changeColor = [this, &color_flipper, &color_tanker, &color_spiker, &color_pulsar](T &enm)
    {
        switch (resolve(enm.type_))
        {
        case Game::Flipper:
            enm.color_ = {color_flipper};
            break;
        case Game::Tanker_flipper:
            enm.color_ = {color_tanker};
            break;
        case Game::Tanker_fuseball:
            enm.color_ = {color_tanker};
            break;
        case Game::Tanker_pulsar:
            enm.color_ = {color_tanker};
            break;
        case Game::Spiker:
            enm.color_ = {color_spiker};
            break;
        case Game::Pulsar:
            enm.color_ = {color_pulsar};
            break;
        default:
            break;
        }
    };

    switch (level_) // Change the color for the next set of levels
    {
    case 17:
        electric_well_.color_ = {255, 0, 0, 255};
        player_.color_ = {0, 255, 0, 255};
        player_.zapper_color_ = {0, 255, 255, 255};
        color_flipper = {138, 43, 226, 255};
        color_tanker = {0, 0, 255, 255};
        color_spiker = {0, 255, 255, 255};
        color_pulsar = {255, 255, 0, 255};
        std::for_each(ennemi_list_.begin(), ennemi_list_.end(), changeColor);
        std::for_each(spike_list_.begin(), spike_list_.end(), changeColor);
        break;
    case 33:
        electric_well_.color_ = {255, 255, 0, 255};
        player_.color_ = {0, 0, 255, 255};
        player_.zapper_color_ = {0, 0, 255, 255};
        color_flipper = {0, 255, 0, 255};
        color_tanker = {0, 255, 255, 255};
        color_spiker = {255, 0, 0, 255};
        color_pulsar = {0, 0, 255, 255};
        std::for_each(ennemi_list_.begin(), ennemi_list_.end(), changeColor);
        std::for_each(spike_list_.begin(), spike_list_.end(), changeColor);
        break;
    case 49:
        electric_well_.color_ = {0, 255, 255, 255};
        player_.zapper_color_ = {255, 0, 0, 255};
        color_flipper = {0, 255, 0, 255};
        color_tanker = {138, 43, 226, 255};
        color_spiker = {255, 0, 0, 255};
        color_pulsar = {255, 255, 0, 255};
        std::for_each(ennemi_list_.begin(), ennemi_list_.end(), changeColor);
        std::for_each(spike_list_.begin(), spike_list_.end(), changeColor);
        break;
    case 65:
        electric_well_.color_ = {0, 0, 0, 255};
        player_.color_ = {255, 255, 0, 255};
        player_.zapper_color_ = {255, 255, 255, 255};
        color_flipper = {255, 0, 0, 255};
        color_tanker = {138, 43, 226, 255};
        color_spiker = {0, 255, 0, 255};
        color_pulsar = {0, 255, 255, 255};
        std::for_each(ennemi_list_.begin(), ennemi_list_.end(), changeColor);
        std::for_each(spike_list_.begin(), spike_list_.end(), changeColor);
        break;
    case 81:
        electric_well_.color_ = {0, 255, 0, 255};
        player_.color_ = {255, 0, 0, 255};
        player_.zapper_color_ = {138, 43, 226, 255};
        color_flipper = {225, 225, 0, 255};
        color_tanker = {138, 43, 226, 255};
        color_spiker = {0, 0, 255, 255};
        color_pulsar = {255, 255, 0, 255};
        std::for_each(ennemi_list_.begin(), ennemi_list_.end(), changeColor);
        std::for_each(spike_list_.begin(), spike_list_.end(), changeColor);
        break;
    }
}

/* This function add a certain int to the score depending on the type given in
 * input
 */
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
    }
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

/* This function goes through the columns of the letter_index line of simplex,
 * and, if the coordinates pair isn't equal to -1, it draws the line between them
 */
void Game::printLetter(const int &letter_index, const int &offset_x, const int &offset_y, SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 2; i < 112; i += 2)
    {
        int x1 = simplex[letter_index][i];
        int y1 = simplex[letter_index][i + 1];
        int x2 = simplex[letter_index][i + 2];
        int y2 = simplex[letter_index][i + 3];
        if (x1 != -1 && y1 != -1 && x2 != -1 && y2 != -1)
            SDL_RenderDrawLine(renderer, x1 + offset_x, -y1 + offset_y, x2 + offset_x, -y2 + offset_y);
    }
}

/* This function takes simplex indexes list as input and computes the total width
 * of thoses symbols
 */
const int Game::computeOffset(const std::vector<int> &letters)
{
    int offset = 0;
    for (auto l : letters)
    {
        offset += simplex[l][1];
    }
    return offset;
}

/* This function draws all the symbols indexed by indexes in the way that w is
 * the middle of the width of the symbols and offset_y if the bottom of the symbols
 */
void Game::printMessage(const std::vector<int> &indexes, SDL_Renderer *renderer, const int &w, const int &offset_y)
{
    int offset_sum = computeOffset(indexes);
    int offset_x = w - (offset_sum / 2);
    for (auto i : indexes)
    {
        printLetter(i, offset_x, offset_y, renderer);
        offset_x += simplex[i][1];
    }
}

/* Prints the string "avoid spikes" on the center top of the screen
 */
void Game::printAvoidSpikes(SDL_Renderer *renderer)
{
    int w, h;
    std::vector<int> letters{33, 54, 47, 41, 36, 0, 51, 48, 41, 43, 37, 51};
    SDL_GetRendererOutputSize(renderer, &w, &h);
    printMessage(letters, renderer, w / 2, 200);
}

/* This function checks if the input number is a score or a level. If it is a
 * a level, the first digit is the result of the int division by 10 and the second
 * digit is the rest of this division. If the number is a score, with isolate each
 * digit with successive division by 10^x (from 100000 to 10). Those digits are stored
 * in a vector container after adding 16 to each (16 reprensents the 0 symbol in simplex).
 */
const std::vector<int> Game::decomposeNumbers(const int &number, const bool &is_level)
{
    std::vector<int> numbers;
    if (is_level)
    {
        numbers.insert(numbers.begin(), (number / 10) + 16);
        numbers.insert(numbers.end(), (number % 10) + 16);
    }
    if (!is_level)
    {
        int q = number;
        int r;
        for (int i = 100000; i > 0; i /= 10)
        {
            r = q % i;
            q = q / i;
            numbers.insert(numbers.end(), q + 16);
            q = r;
        }
    }
    return numbers;
}

/* Prints continiously the score on top of the screen
 */
void Game::printScore(SDL_Renderer *renderer)
{
    int w, h;
    std::vector<int> letters = decomposeNumbers(score_, false);
    SDL_GetRendererOutputSize(renderer, &w, &h);
    printMessage(letters, renderer, (2 * w) / 5, 80);
}

/* Prints continiously the level on top left of the screen
 */
void Game::printLevel(SDL_Renderer *renderer)
{
    int w, h;
    std::vector<int> letters = decomposeNumbers(level_, true);
    SDL_GetRendererOutputSize(renderer, &w, &h);
    printMessage(letters, renderer, (2 * w) / 3, 80);
}

/* Erases the screen and prints "game over", the score and the level in the
 * center of the screen
 */
void Game::printEndScreen(SDL_Renderer *renderer)
{
    int w, h;
    SDL_GetRendererOutputSize(renderer, &w, &h);
    std::vector<int> message;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    if (level_ == 99)
    {
        // Game over
        message = {39, 65, 77, 69, 0, 79, 86, 69, 82};
        printMessage(message, renderer, w / 2, 100);
        // Victory !
        message = {54, 73, 67, 84, 79, 82, 89, 0, 1};
        printMessage(message, renderer, w / 2, 200);
        // Score :
        message = {51, 67, 79, 82, 69, 0, 26};
        printMessage(message, renderer, (2 * w) / 5, 300);
        printMessage(decomposeNumbers(score_, false), renderer, (3 * w) / 5, 300);
        // Level :
        message = {44, 69, 86, 69, 76, 0, 26};
        printMessage(message, renderer, (2 * w) / 5, 400);
        printMessage(decomposeNumbers(level_, true), renderer, (3 * w) / 5, 400);
        // Press exit to quit
        message = {48, 82, 69, 83, 83, 0, 69, 88, 73, 84, 0, 84, 79, 0, 81, 85, 73, 84};
        printMessage(message, renderer, w / 2, 500);
    }
    if (player_.lives_ == 0)
    {
        // Game over
        message = {39, 65, 77, 69, 0, 79, 86, 69, 82};
        printMessage(message, renderer, w / 2, 100);
        // Defeat >.<
        message = {36, 69, 70, 69, 65, 84, 0, 30, 14, 28};
        printMessage(message, renderer, w / 2, 200);
        // Score :
        message = {51, 67, 79, 82, 69, 0, 26};
        printMessage(message, renderer, (2 * w) / 5, 300);
        printMessage(decomposeNumbers(score_, false), renderer, (3 * w) / 5, 300);
        // Level :
        message = {44, 69, 86, 69, 76, 0, 26};
        printMessage(message, renderer, (2 * w) / 5, 400);
        printMessage(decomposeNumbers(level_, true), renderer, (3 * w) / 5, 400);
        // Press exit to quit
        message = {48, 82, 69, 83, 83, 0, 69, 88, 73, 84, 0, 84, 79, 0, 81, 85, 73, 84};
        printMessage(message, renderer, w / 2, 500);
    }
    SDL_RenderPresent(renderer);
}
