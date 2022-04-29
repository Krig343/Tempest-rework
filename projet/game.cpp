#include "game.h"

//----------------------------- Constructors -----------------------------------

Game::Game() : player_{Player{false, 0.0, 0, 0, false}},
               electric_well_{ElectricWell{1}}
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
bool Game::endGame()
{
    if (player_.lives_ == 0 || (level_ == 99 && flipper_list_.size() == 0))
    {
        printEndScreen();
        return true;
    }
    return false;
}

void Game::addPlayerMissile(int lane)
{
    // Maximum of 5 missiles at all time
    if(player_missile_list_.size() < 5)
        player_missile_list_.push_back(Missile(lane, 0.0));
}

void Game::spawnEnnemies()
{
    if(time_%250 == 0)
        flipper_list_.push_back(Flipper(time_%3, 1.0));
}

void Game::levelUp()
{
}

Game::enm_types_ Game::resolve(std::string type)
{
    static const std::map<std::string, enm_types_> typeStrings{
        {"Flipper", Flipper_t},
        {"Tanker_flipper", Tanker_flipper_t},
        {"Tanker_fuseball", Tanker_fuseball_t},
        {"Tanker_pulsar", Tanker_pulsar_t},
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

void Game::addScore(const std::string &type)
{
    switch (resolve(type))
    {
    case Game::Flipper_t:
        score_ += 150;
        break;
    case Game::Tanker_flipper_t:
        score_ += 100;
        break;
    case Game::Tanker_fuseball_t:
        score_ += 100;
        break;
    case Game::Tanker_pulsar_t:
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
    };
}

/* Tests the collision between objects. */
bool Game::collisionTest(const int &lane1, const int &lane2, const float &pos1, const float &pos2)
{
    return (lane1 == lane2)&&(pos1*pos1 > pos2*pos2 - 0.025)&&(pos1*pos1 < pos2*pos2 + 0.025);
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
    for(auto &f : flipper_list_)
        f.move(1, electric_well_.isCyclic_, electric_well_.polygonSize_);

    // Update missile positions and check for collisions
    for(auto &m : player_missile_list_){
        m.move();

        for(auto &f : flipper_list_){
            if(collisionTest(f.lane_, m.lane_, f.position_, m.position_)){
                m.kill();
                f.kill();
            }
        }
    }

    // Spawn new ennemies
    spawnEnnemies();

    // Check for dead missiles
    std::vector<Missile> newMissiles;

    for (auto m : player_missile_list_)
    {
        if(!m.dead_)
            newMissiles.push_back(m);
    }

    player_missile_list_ = newMissiles;

    // Check for dead ennemies
    std::vector<Flipper> newFlippers;

    for (auto f : flipper_list_)
    {
        if(!f.dead_)
            newFlippers.push_back(f);
    }

    flipper_list_ = newFlippers;

    // Update time
    time_++;
}

void Game::draw(SDL_Renderer *renderer)
{
    // Clear display
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
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
    for(auto m : player_missile_list_){
        m.draw(renderer, 
               electric_well_.lanes_[m.lane_].getScale(m.position_*m.position_), 
               electric_well_.lanes_[m.lane_].getAngle(), 
               electric_well_.lanes_[m.lane_].getPosition(m.position_*m.position_));
    }

    // Draw ennemies
    for(auto e : flipper_list_){
        e.draw(renderer, 
               electric_well_.lanes_[e.lane_].getScale(e.position_*e.position_), 
               electric_well_.lanes_[e.lane_].getAngle(), 
               electric_well_.lanes_[e.lane_].getPosition(e.position_*e.position_));
    }

    // Draw spikes

    SDL_RenderPresent(renderer);
}
