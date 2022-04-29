#include "game.h"

//----------------------------- Constructors -----------------------------------

Game::Game() : player_{Player{false, 0.0, 0, 0, false}},
               electric_well_{ElectricWell{1}}
{
    score_ = 0;
    level_ = 1;
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

void Game::movePlayer(int movement)
{
    int newLane = player_.lane_ + movement;

    // To avoid % of negative integers
    if((electric_well_.isCyclic_)&&(newLane < 0)){
        player_.move(electric_well_.polygonSize_ - 1);
        return;
    }

    if(electric_well_.isCyclic_)
    {
        player_.move(newLane%electric_well_.polygonSize_);
    } else {
        if(movement < 0)
        {
            player_.move(std::min(0, newLane));
        } else {
            player_.move(std::max(newLane, electric_well_.polygonSize_ - 1));
        }
    }
}

void Game::addPlayerMissile(int lane)
{
    player_missile_list_.push_back(Missile(lane, 0.0));
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

void Game::update()
{   
    // Update ennemy positions

    // Update missile positions
    for(auto &m : player_missile_list_)
        m.move();

    // Check for dead missiles
    std::vector<Missile> newMissiles;

    for (auto m : player_missile_list_)
    {
        if (m.position_ < 1.05)
            newMissiles.push_back(m);
    }

    player_missile_list_ = newMissiles;

    // Check for collisons
}

void Game::draw(SDL_Renderer *renderer)
{
    // Clear display
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderClear(renderer);

    // Draw electric well
    electric_well_.draw(renderer);

    // Draw player
    player_.draw(renderer, 
                 electric_well_.lanes_[player_.lane_].getScale(player_.position_), 
                 electric_well_.lanes_[player_.lane_].getAngle(), 
                 electric_well_.lanes_[player_.lane_].getPosition(player_.position_));

    // Draw missiles
    for(auto m : player_missile_list_){
        m.draw(renderer, 
               electric_well_.lanes_[m.lane_].getScale(m.position_*m.position_), 
               electric_well_.lanes_[m.lane_].getAngle(), 
               electric_well_.lanes_[m.lane_].getPosition(m.position_*m.position_));
    }

    // Draw ennemies

    // Draw spikes

    SDL_RenderPresent(renderer);
}
