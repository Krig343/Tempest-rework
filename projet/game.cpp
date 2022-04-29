#include "game.h"

//----------------------------- Constructors -----------------------------------

Game::Game() : player_{Player{false, 0.0, 0, 3, true}},
               electric_well_{ElectricWell{1}},
               currentWellCopy_{ElectricWell{1}},
               nextWellCopy_{ElectricWell{2}}
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
    if (player_.lives_ == 0 || (level_ == 99) && (flipper_list_.size()
                                                +  tanker_list_.size() == 0))
    {
        printEndScreen();
        return true;
    }
    return false;
}

void Game::addPlayerMissile(int lane)
{
    // Maximum of 5 * level
    if(player_missile_list_.size() < (5 * level_))
        player_missile_list_.push_back(Missile(lane, 0.0));
}

void Game::spawnEnnemies()
{
    if(time_%(200-level_) == 0)
        flipper_list_.push_back(Flipper(time_%3, 1.0));

    if((time_%(400-level_) == 0)&&(level_ >= 2))
        tanker_list_.push_back(Tanker(time_%7, 1.0));

    if((time_%(200-level_) == 0)&&(level_ >= 3))
        flipper_list_.push_back(Flipper(time_%3 + 1, 1.0));

    if((time_%(400-level_) == 0)&&(level_ >= 4))
        tanker_list_.push_back(Tanker(time_%7 + 1, 1.0));
}

void Game::levelUp()
{
    int newLevel = level_;

    if(score_ > 1000)
        newLevel = 2;

    if(score_ > 2500)
        newLevel = 3;

    if(score_ > 5000)
        newLevel = 4;

    if(score_ > 8500)
        newLevel = static_cast<int> (score_ - 8500.0)/4000.0 + 5;

    if(newLevel != level_)
    {
        level_ = newLevel;
        startMorphing();
    }  
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
    // Check if leveled up
    levelUp();

    // Speed is 1 a level 1, 2.5 at level 2
    float speed = level_*3.0/196.0 + 193.0/196.0;

    // Update ennemy positions
    for(auto &f : flipper_list_)
        f.move(1, speed, electric_well_.isCyclic_, electric_well_.polygonSize_);

    for(auto &t : tanker_list_)
        t.move(1, speed, electric_well_.isCyclic_, electric_well_.polygonSize_);

    // Update missile positions and check for collisions
    for(auto &m : player_missile_list_){
        m.move();

        for(auto &f : flipper_list_){
            if(collisionTest(f.lane_, m.lane_, f.position_, m.position_)){
                m.kill();
                f.kill();
            }
        }

        for(auto &t : tanker_list_){
            if(collisionTest(t.lane_, m.lane_, t.position_, m.position_)){
                m.kill();
                t.kill();
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
        if(!m.dead_)
            newMissiles.push_back(m);
    }

    player_missile_list_ = newMissiles;

    // Check for dead flippers
    std::vector<Flipper> newFlippers;

    for (auto f : flipper_list_)
    {
        // Keep non dead flippers
        if(!f.dead_){
            newFlippers.push_back(f);
        } else {
        // Points for each dead flipper
            score_+= 150 + level_;
        }
    }

    flipper_list_ = newFlippers;

    // Check for dead tankers
    std::vector<Tanker> newTankers;

    for (auto t : tanker_list_)
    {
        // Keep non dead tankers
        if(!t.dead_){
            newTankers.push_back(t);
        } else {
        // Points for each dead flipper
            score_+= 100 + level_;
        // Spawn 2 flippers (for now)
            flipper_list_.push_back(Flipper(t.lane_, t.position_));
            flipper_list_.push_back(Flipper((t.lane_ + 1)%electric_well_.polygonSize_, t.position_));
        }
    }

    tanker_list_ = newTankers;

    // Check for collisions with player   
    for(auto &f : flipper_list_){
        if(collisionTest(f.lane_, player_.lane_, f.position_, player_.position_)){
            player_.loseLife();
            f.kill();
            score_+= 100 + level_;
        } 
    }

    for(auto &t : tanker_list_){
        if(collisionTest(t.lane_, player_.lane_, t.position_, player_.position_)){
            player_.loseLife();
            t.kill();
            score_+= 100 + level_;
        } 
    }

    // Update time
    time_++;
}

void Game::startMorphing(){
    currentWellCopy_ = ElectricWell{level_ - 1};
    nextWellCopy_ = ElectricWell{level_};

    isMorphing_ = true;
    morphingStep_ = 250;
}

void Game::morphLevel()
{
    morphingStep_--;

    if(morphingStep_ == 0){
        electric_well_ = nextWellCopy_;
        return;
    }

    float t0 = static_cast<float> (250 - morphingStep_)/250;
    float t1 = 1.0 - t0;

    for(int p = 0; p < electric_well_.polygonSize_; p++){
        electric_well_.backPolygon_[p] = {currentWellCopy_.backPolygon_[p].x * t1 + nextWellCopy_.backPolygon_[p].x * t0,
                                          currentWellCopy_.backPolygon_[p].y * t1 + nextWellCopy_.backPolygon_[p].y * t0};
                                        
        electric_well_.frontPolygon_[p] = {currentWellCopy_.frontPolygon_[p].x * t1 + nextWellCopy_.frontPolygon_[p].x * t0,
                                           currentWellCopy_.frontPolygon_[p].y * t1 + nextWellCopy_.frontPolygon_[p].y * t0};
    }

    electric_well_.lanes_.clear();
    electric_well_.initLevelLanes();
}

void Game::draw(SDL_Renderer *renderer)
{
    // Clear display
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderClear(renderer);

    // If level is changing
    if((isMorphing_)&&(morphingStep_ > 0))
    {
        morphLevel();
    }

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
    for(auto f : flipper_list_){
        f.draw(renderer, 
               electric_well_.lanes_[f.lane_].getScale(f.position_*f.position_), 
               electric_well_.lanes_[f.lane_].getAngle(), 
               electric_well_.lanes_[f.lane_].getPosition(f.position_*f.position_));
    }

    for(auto t : tanker_list_){
        t.draw(renderer, 
               electric_well_.lanes_[t.lane_].getScale(t.position_*t.position_), 
               electric_well_.lanes_[t.lane_].getAngle(), 
               electric_well_.lanes_[t.lane_].getPosition(t.position_*t.position_));
    }

    // Draw spikes

    SDL_RenderPresent(renderer);
}
