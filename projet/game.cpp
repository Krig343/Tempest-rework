#include "game.h"

//----------------------------- Constructors -----------------------------------

Game::Game() : player_{Player{false, 0.0, 0, 5}},
               electric_well_{ElectricWell{1, "Circle"}}
{
    // Game attributes
    score_ = 0;
    level_ = 1;
    time_ = 0;
}

//---------------------------- Game controls -----------------------------------

/* The game should stop (ie. go to the end screen) when, either the player
 * has no lives left, or when he finishes level 99. Return true so the main
 * script known he has to exit th egame loop. If false is returned the nothing
 * appens
 */
bool Game::endGame(SDL_Renderer *renderer)
{
    if (player_.lives_ == 0 || (level_ == 99) && (flipper_list_.size() + tanker_list_.size() == 0))
    {
        printEndScreen(renderer);
        return true;
    }
    return false;
}

// /* This function searches for the object rem_obj in the correct list and removes
//  * it when found and stops with an error message if not
//  */
// template <class T>
// void Game::removeObject(const T &rem_obj)
// {
//     // Remove a flipper
//     if constexpr (std::is_same_v<T, Flipper>)
//     {
//         auto flp_index = std::find(flipper_list_.begin(), flipper_list_.end(), rem_obj);
//         if (flp_index == flipper_list_.end())
//         {
//             std::cout << "L'élément " << rem_obj.type_ << " n'est pas dans la liste" << std::endl;
//             exit(EXIT_FAILURE);
//         }
//         else
//             flipper_list_.erase(flp_index);
//     }

//     // Remove a tanker
//     else if constexpr (std::is_same_v<T, Tanker>)
//     {
//         auto tkr_index = std::find(tanker_list_.begin(), tanker_list_.end(), rem_obj);
//         if (tkr_index == tanker_list_.end())
//         {
//             std::cout << "L'élément " << rem_obj.type_ << " n'est pas dans la liste" << std::endl;
//             exit(EXIT_FAILURE);
//         }
//         else
//             tanker_list_.erase(tkr_index);
//     }

//     // Remove a missile
//     else if constexpr (std::is_same_v<T, Missile>)
//     {
//         auto msl_index = std::find(player_missile_list_.begin(), player_missile_list_.end(), rem_obj);
//         if (msl_index == player_missile_list_.end())
//         {
//             msl_index = std::find(ennemi_missile_list_.begin(), ennemi_missile_list_.end(), rem_obj);
//             if (msl_index == ennemi_missile_list_.end())
//             {
//                 std::cout << "Le missile n'est dans aucune liste" << std::endl;
//                 exit(EXIT_FAILURE);
//             }
//             else
//                 ennemi_missile_list_.erase(msl_index);
//         }
//         else
//             player_missile_list_.erase(msl_index);
//     }
// }

void Game::addPlayerMissile(int lane)
{
    // Maximum of 15 missiles at all time
    if (player_missile_list_.size() < 15)
        player_missile_list_.push_back(Missile(lane, 0.0));
}

void Game::spawnEnnemies()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 16);
    auto rndm_lane = distrib(gen);
    if (time_ % 250 == 0)
        flipper_list_.push_back(Flipper{1.0, rndm_lane});

    if (time_ % 500 == 0)
        tanker_list_.push_back(Tanker{1.0, rndm_lane});
}

/* This function returns the enemy type from the enm_types_ enum corresponding
 * to the type string in input
 */
Game::enm_types_ Game::resolve(std::string type)
{
    static const std::map<std::string, enm_types_> typeStrings{
        {"Flipper", Flipper_t},
        {"Tanker", Tanker_t},
        {"Spiker", Spiker_t},
        {"Fuseball", Fuseball_t},
        {"Pulsar", Pulsar_t}};

    auto itr = typeStrings.find(type);
    if (itr != typeStrings.end())
    {
        return itr->second;
    }
    std::cout << "Le type " << type << " n'existe pas" << std::endl;
    exit(EXIT_FAILURE);
}

/* This function adds one to the current level and
            // Points for each dead flipper
            score_ += 100; modifies the shape and the color
 * of the electricwell, as well as the color of the ennemies and the player
 */
template <class T>
void Game::levelUp()
{
    ++level_;
    player_.regenZapper();

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

    std::array<Uint8, 4> color;

    // Ce serait cool de pouvoir la templater pour faire passer les spikes et les ennemies
    auto changeColor = [this, &color](T &list_elem)
    {
        list_elem.model_color_ = {color};
    };

    switch (level_) // Change the color for the next set of levels
    {
    case 17:
        electric_well_.color_ = {255, 0, 0, 255};
        player_.model_color_ = {0, 255, 0, 255};
        player_.zapper_color_ = {0, 255, 255, 255};
        color = {138, 43, 226, 255};
        std::for_each(flipper_list_.begin(), flipper_list_.end(), changeColor);
        color = {0, 0, 255, 255};
        std::for_each(tanker_list_.begin(), tanker_list_.end(), changeColor);
        break;
    case 33:
        electric_well_.color_ = {255, 255, 0, 255};
        player_.model_color_ = {0, 0, 255, 255};
        player_.zapper_color_ = {0, 0, 255, 255};
        color = {0, 255, 0, 255};
        std::for_each(flipper_list_.begin(), flipper_list_.end(), changeColor);
        color = {0, 255, 255, 255};
        std::for_each(tanker_list_.begin(), tanker_list_.end(), changeColor);
        break;
    case 49:
        electric_well_.color_ = {0, 255, 255, 255};
        player_.zapper_color_ = {255, 0, 0, 255};
        color = {0, 255, 0, 255};
        std::for_each(flipper_list_.begin(), flipper_list_.end(), changeColor);
        color = {138, 43, 226, 255};
        std::for_each(tanker_list_.begin(), tanker_list_.end(), changeColor);
        break;
    case 65:
        electric_well_.color_ = {0, 0, 0, 255};
        player_.model_color_ = {255, 255, 0, 255};
        player_.zapper_color_ = {255, 255, 255, 255};
        color = {255, 0, 0, 255};
        std::for_each(flipper_list_.begin(), flipper_list_.end(), changeColor);
        color = {138, 43, 226, 255};
        std::for_each(tanker_list_.begin(), tanker_list_.end(), changeColor);
        break;
    case 81:
        electric_well_.color_ = {0, 255, 0, 255};
        player_.model_color_ = {255, 0, 0, 255};
        player_.zapper_color_ = {138, 43, 226, 255};
        color = {225, 225, 0, 255};
        std::for_each(flipper_list_.begin(), flipper_list_.end(), changeColor);
        color = {138, 43, 226, 255};
        std::for_each(tanker_list_.begin(), tanker_list_.end(), changeColor);
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
    case Game::Flipper_t:
        score_ += 150;
        break;
    case Game::Tanker_t:
        score_ += 100;
        break;
    case Game::Spiker_t:
        score_ += 50;
        break;
    case Game::Fuseball_t: // Add 500 and 750
        score_ += 250;
        break;
    case Game::Pulsar_t:
        score_ += 200;
        break;
    }
}

// /* Tests the collision between objects. The collision test depends on the number
//  * test_nb.
//  * - 1 : collision test between an enemy and the player
//  * - 2 : collision between an enemy and a missile
//  * - 3 : collision between the player and a missile
//  * - 4 : collision between the player and a Spike (maybe it will be an enemy)
//  */
// void Game::collisionTest()
// {
//     // Collision between player and ennemies
//     for (auto e : ennemi_list_)
//         if (player_.position_ == e.position_)
//         {
//             player_.loseLife();
//             removeObject(e);
//         }

//     // Collision between player's missiles and ennemies
//     for (auto m : player_missile_list_)
//         for (auto e : ennemi_list_)
//             if (m.position_ == e.position_)
//             {
//                 removeObject(e);
//                 removeObject(m);
//             }

//     // Collision between player and ennemie's missiles
//     for (auto m : ennemi_missile_list_)
//         if (player_.position_ == m.position_)
//         {
//             removeObject(m);
//             player_.loseLife();
//         }

//     // Collision between player and spike
//     for (auto s : spike_list_)
//         if (player_.position_ == s.position_)
//             player_.loseLife();

//     // Collision between player's missile and spike
//     for (auto m : player_missile_list_)
//         for (auto s : spike_list_)
//             if (m.position_ == s.position_)
//             {
//                 removeObject(m);
//                 removeObject(s);
//             }
// }

void Game::useZapper()
{
    if (player_.zapper_left == 2)
    {
        --player_.zapper_left;
        flipper_list_.clear();
        tanker_list_.clear();
    }
    else if (player_.zapper_left == 1)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, 2);
        auto rndm_enmi = distrib(gen);
        if (rndm_enmi == 1)
        {
            auto remove_at_flipper = [this](int i)
            {
                std::swap(flipper_list_[i], flipper_list_.back());
                flipper_list_.pop_back();
            };
            std::uniform_int_distribution<> distrib1(1, flipper_list_.size());
            auto rndm_flipper = distrib1(gen);
            remove_at_flipper(rndm_flipper);
        }
        else if (rndm_enmi == 2)
        {
            auto remove_at_tanker = [this](int i)
            {
                std::swap(tanker_list_[i], tanker_list_.back());
                tanker_list_.pop_back();
            };
            std::uniform_int_distribution<> distrib2(1, tanker_list_.size());
            auto rndm_tanker = distrib2(gen);
            remove_at_tanker(rndm_tanker);
        }
    }
    else
        std::cout << "no more zappers left for this level" << std::endl;
}

/* Tests the collision between objects. */
bool Game::collisionTest(const int &lane1, const int &lane2, const float &pos1, const float &pos2)
{
    return (lane1 == lane2) && (pos1 * pos1 > pos2 * pos2 - 0.025) && (pos1 * pos1 < pos2 * pos2 + 0.025);
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

void Game::update()
{
    // Update ennemy positions
    for (auto &f : flipper_list_)
        f.move(1, electric_well_.is_cyclic_, electric_well_.polygon_size_);

    for (auto &t : tanker_list_)
        t.move(1, electric_well_.is_cyclic_, electric_well_.polygon_size_);

    // Update missile positions and check for collisions
    for (auto &m : player_missile_list_)
    {
        m.move();

        for (auto &f : flipper_list_)
        {
            if (collisionTest(f.lane_, m.lane_, f.position_, m.position_))
            {
                m.kill();
                f.kill();
                addScore("Flipper");
            }
        }

        for (auto &t : tanker_list_)
        {
            if (collisionTest(t.lane_, m.lane_, t.position_, m.position_))
            {
                m.kill();
                t.kill();
                addScore("Tanker");
            }
        }
    }

    // Spawn new ennemies
    spawnEnnemies();

    // Check for dead missiles
    std::vector<Missile> newMissiles;

    for (auto m : player_missile_list_)
    {
        // Keep non dead missiles
        if (!m.dead_)
            newMissiles.push_back(m);
    }

    player_missile_list_ = newMissiles;

    // Check for dead flippers
    std::vector<Flipper> newFlippers;

    for (auto f : flipper_list_)
    {
        // Keep non dead flippers
        if (!f.dead_)
            newFlippers.push_back(f);
    }

    flipper_list_ = newFlippers;

    // Check for dead tankers
    std::vector<Tanker> newTankers;

    for (auto t : tanker_list_)
    {
        // Keep non dead tankers
        if (!t.dead_)
        {
            newTankers.push_back(t);
        }
        else
        {
            // Points for each dead flipper
            score_ += 100;
            // Spawn 2 flippers (for now)
            flipper_list_.push_back(Flipper(t.position_, t.lane_));
            flipper_list_.push_back(Flipper(t.position_, t.lane_ + 1));
        }
    }

    tanker_list_ = newTankers;

    // Check for collisions with player
    for (auto &f : flipper_list_)
    {
        if (collisionTest(f.lane_, player_.lane_, f.position_, player_.position_))
        {
            player_.loseLife();
            f.kill();
        }
    }

    for (auto &t : tanker_list_)
    {
        if (collisionTest(t.lane_, player_.lane_, t.position_, player_.position_))
        {
            player_.loseLife();
            t.kill();
        }
    }

    // Update time
    time_++;
}

void Game::draw(SDL_Renderer *renderer)
{
    // Clear display
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw electric well
    electric_well_.draw(renderer);
    electric_well_.highlightLane(renderer, player_.lane_);

    // Draw player
    player_.draw(renderer,
                 electric_well_.lanes_[player_.lane_].getScale(player_.position_),
                 electric_well_.lanes_[player_.lane_].getAngle(),
                 electric_well_.lanes_[player_.lane_].getPosition(player_.position_));

    // Draw missiles
    for (auto m : player_missile_list_)
    {
        m.draw(renderer,
               electric_well_.lanes_[m.lane_].getScale(m.position_ * m.position_),
               electric_well_.lanes_[m.lane_].getAngle(),
               electric_well_.lanes_[m.lane_].getPosition(m.position_ * m.position_));
    }

    // Draw ennemies
    for (auto f : flipper_list_)
    {
        f.draw(renderer,
               electric_well_.lanes_[f.lane_].getScale(f.position_ * f.position_),
               electric_well_.lanes_[f.lane_].getAngle(),
               electric_well_.lanes_[f.lane_].getPosition(f.position_ * f.position_));
    }

    for (auto t : tanker_list_)
    {
        t.draw(renderer,
               electric_well_.lanes_[t.lane_].getScale(t.position_ * t.position_),
               electric_well_.lanes_[t.lane_].getAngle(),
               electric_well_.lanes_[t.lane_].getPosition(t.position_ * t.position_));
    }

    // Draw spikes

    SDL_RenderPresent(renderer);
}
