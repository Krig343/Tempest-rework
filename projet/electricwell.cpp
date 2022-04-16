#include "electricwell.h"

//----------------------------- Constructors -----------------------------------

ElectricWell::ElectricWell(const std::array<Uint8, 4> &color, const std::string &shape, const std::vector<Lane> &lanes) : color_{color},
                                                                                                                          shape_{shape},
                                                                                                                          lane_list_{lanes}
{
}

//------------------------- Electric well controls -----------------------------

void ElectricWell::addLane(Vec2 pb, Vec2 pe, Vec2 eb, Vec2 ee)
{
    Lane lane{pb, pe, eb, ee, color_};
    lane_list_.insert(lane_list_.end(), lane);
}

// Toujours 16 lanes
void ElectricWell::createCircle()
{
    Vec2 pb;
    Vec2 pe;
    Vec2 eb;
    Vec2 ee;
    // Lane 1
    // Player side
    pb = {400, 100};
    pe = {325, 120};
    // Ennemi side
    eb = {400, 375};
    ee = {388, 378};
    addLane(pb, pe, eb, ee);

    // Lane 2
    // Player side
    pb = {325, 120};
    pe = {261, 160};
    // Ennemi side
    eb = {388, 378};
    ee = {377, 385};
    addLane(pb, pe, eb, ee);

    // Lane 3
    // Player side
    pb = {261, 160};
    pe = {224, 226};
    // Ennemi side
    eb = {377, 385};
    ee = {372, 394};
    addLane(pb, pe, eb, ee);

    // Lane 4
    // Player side
    pb = {224, 226};
    pe = {200, 300};
    // Ennemi side
    eb = {372, 394};
    ee = {369, 409};
    addLane(pb, pe, eb, ee);

    // Lane 5
    // Player side
    pb = {200, 300};
    pe = {213, 386};
    // Ennemi side
    eb = {369, 409};
    ee = {372, 423};
    addLane(pb, pe, eb, ee);

    // Lane 6
    // Player side
    pb = {213, 386};
    pe = {253, 464};
    // Ennemi side
    eb = {372, 423};
    ee = {378, 436};
    addLane(pb, pe, eb, ee);

    // Lane 7
    // Player side
    pb = {253, 464};
    pe = {307, 526};
    // Ennemi side
    eb = {378, 436};
    ee = {388, 447};
    addLane(pb, pe, eb, ee);

    // Lane 8
    // Player side
    pb = {307, 526};
    pe = {400, 550};
    // Ennemi side
    eb = {388, 447};
    ee = {400, 450};
    addLane(pb, pe, eb, ee);

    // Lane 9
    // Player side
    pb = {400, 550};
    pe = {493, 526};
    // Ennemi side
    eb = {400, 450};
    ee = {412, 447};
    addLane(pb, pe, eb, ee);

    // Lane 10
    // Player side
    pb = {493, 526};
    pe = {547, 464};
    // Ennemi side
    eb = {412, 447};
    ee = {422, 436};
    addLane(pb, pe, eb, ee);

    // Lane 11
    // Player side
    pb = {547, 464};
    pe = {587, 386};
    // Ennemi side
    eb = {422, 436};
    ee = {428, 423};
    addLane(pb, pe, eb, ee);

    // Lane 12
    // Player side
    pb = {587, 386};
    pe = {600, 298};
    // Ennemi side
    eb = {428, 423};
    ee = {430, 409};
    addLane(pb, pe, eb, ee);

    // Lane 13
    // Player side
    pb = {600, 298};
    pe = {577, 224};
    // Ennemi side
    eb = {430, 409};
    ee = {428, 394};
    addLane(pb, pe, eb, ee);

    // Lane 14
    // Player side
    pb = {577, 224};
    pe = {540, 159};
    // Ennemi side
    eb = {428, 394};
    ee = {423, 385};
    addLane(pb, pe, eb, ee);

    // Lane 15
    // Player side
    pb = {540, 159};
    pe = {476, 119};
    // Ennemi side
    eb = {423, 385};
    ee = {412, 378};
    addLane(pb, pe, eb, ee);

    // Lane 16
    // Player side
    pb = {476, 119};
    pe = {400, 100};
    // Ennemi side
    eb = {412, 378};
    ee = {400, 375};
    addLane(pb, pe, eb, ee);
}

void ElectricWell::createSquare()
{
    Vec2 pb;
    Vec2 pe;
    Vec2 eb;
    Vec2 ee;
    // Lane 1
    // Player side
    pb = {400, 100};
    pe = {300, 100};
    // Ennemi side
    eb = {400, 375};
    ee = {383, 375};
    addLane(pb, pe, eb, ee);

    // Lane 2
    // Player side
    pb = {300, 100};
    pe = {200, 100};
    // Ennemi side
    eb = {383, 375};
    ee = {367, 375};
    addLane(pb, pe, eb, ee);

    // Lane 3
    // Player side
    pb = {200, 100};
    pe = {200, 225};
    // Ennemi side
    eb = {367, 375};
    ee = {367, 395};
    addLane(pb, pe, eb, ee);

    // Lane 4
    // Player side
    pb = {200, 225};
    pe = {200, 350};
    // Ennemi side
    eb = {367, 395};
    ee = {367, 416};
    addLane(pb, pe, eb, ee);

    // Lane 5
    // Player side
    pb = {200, 350};
    pe = {200, 450};
    // Ennemi side
    eb = {367, 416};
    ee = {367, 433};
    addLane(pb, pe, eb, ee);

    // Lane 6
    // Player side
    pb = {200, 450};
    pe = {200, 550};
    // Ennemi side
    eb = {367, 433};
    ee = {367, 450};
    addLane(pb, pe, eb, ee);

    // Lane 7
    // Player side
    pb = {200, 550};
    pe = {300, 550};
    // Ennemi side
    eb = {367, 450};
    ee = {383, 450};
    addLane(pb, pe, eb, ee);

    // Lane 8
    // Player side
    pb = {300, 550};
    pe = {400, 550};
    // Ennemi side
    eb = {383, 450};
    ee = {400, 450};
    addLane(pb, pe, eb, ee);

    // Lane 9
    // Player side
    pb = {400, 550};
    pe = {500, 550};
    // Ennemi side
    eb = {400, 450};
    ee = {416, 450};
    addLane(pb, pe, eb, ee);

    // Lane 10
    // Player side
    pb = {500, 550};
    pe = {600, 550};
    // Ennemi side
    eb = {416, 450};
    ee = {433, 450};
    addLane(pb, pe, eb, ee);

    // Lane 11
    // Player side
    pb = {600, 550};
    pe = {600, 450};
    // Ennemi side
    eb = {433, 450};
    ee = {433, 433};
    addLane(pb, pe, eb, ee);

    // Lane 12
    // Player side
    pb = {600, 450};
    pe = {600, 350};
    // Ennemi side
    eb = {433, 433};
    ee = {433, 416};
    addLane(pb, pe, eb, ee);

    // Lane 13
    // Player side
    pb = {600, 350};
    pe = {600, 225};
    // Ennemi side
    eb = {433, 416};
    ee = {433, 395};
    addLane(pb, pe, eb, ee);

    // Lane 14
    // Player side
    pb = {600, 225};
    pe = {600, 100};
    // Ennemi side
    eb = {433, 395};
    ee = {433, 375};
    addLane(pb, pe, eb, ee);

    // Lane 15
    // Player side
    pb = {600, 100};
    pe = {500, 100};
    // Ennemi side
    eb = {433, 375};
    ee = {416, 375};
    addLane(pb, pe, eb, ee);

    // Lane 16
    // Player side
    pb = {500, 100};
    pe = {400, 100};
    // Ennemi side
    eb = {416, 375};
    ee = {400, 375};
    addLane(pb, pe, eb, ee);
}

void ElectricWell::createPlus()
{
    // Lane 1
    // Player side

    // Ennemi side

    // Lane 2
    // Player side

    // Ennemi side

    // Lane 3
    // Player side

    // Ennemi side

    // Lane 4
    // Player side

    // Ennemi side

    // Lane 5
    // Player side

    // Ennemi side

    // Lane 6
    // Player side

    // Ennemi side

    // Lane 7
    // Player side

    // Ennemi side

    // Lane 8
    // Player side

    // Ennemi side

    // Lane 9
    // Player side

    // Ennemi side

    // Lane 10
    // Player side

    // Ennemi side

    // Lane 11
    // Player side

    // Ennemi side

    // Lane 12
    // Player side

    // Ennemi side

    // Lane 13
    // Player side

    // Ennemi side

    // Lane 14
    // Player side

    // Ennemi side

    // Lane 15
    // Player side

    // Ennemi side

    // Lane 16
    // Player side

    // Ennemi side
}

void ElectricWell::createBinoculars()
{
    // Lane 1
    // Player side

    // Ennemi side

    // Lane 2
    // Player side

    // Ennemi side

    // Lane 3
    // Player side

    // Ennemi side

    // Lane 4
    // Player side

    // Ennemi side

    // Lane 5
    // Player side

    // Ennemi side

    // Lane 6
    // Player side

    // Ennemi side

    // Lane 7
    // Player side

    // Ennemi side

    // Lane 8
    // Player side

    // Ennemi side

    // Lane 9
    // Player side

    // Ennemi side

    // Lane 10
    // Player side

    // Ennemi side

    // Lane 11
    // Player side

    // Ennemi side

    // Lane 12
    // Player side

    // Ennemi side

    // Lane 13
    // Player side

    // Ennemi side

    // Lane 14
    // Player side

    // Ennemi side

    // Lane 15
    // Player side

    // Ennemi side

    // Lane 16
    // Player side

    // Ennemi side
}

void ElectricWell::createCross()
{
    // Lane 1
    // Player side

    // Ennemi side

    // Lane 2
    // Player side

    // Ennemi side

    // Lane 3
    // Player side

    // Ennemi side

    // Lane 4
    // Player side

    // Ennemi side

    // Lane 5
    // Player side

    // Ennemi side

    // Lane 6
    // Player side

    // Ennemi side

    // Lane 7
    // Player side

    // Ennemi side

    // Lane 8
    // Player side

    // Ennemi side

    // Lane 9
    // Player side

    // Ennemi side

    // Lane 10
    // Player side

    // Ennemi side

    // Lane 11
    // Player side

    // Ennemi side

    // Lane 12
    // Player side

    // Ennemi side

    // Lane 13
    // Player side

    // Ennemi side

    // Lane 14
    // Player side

    // Ennemi side

    // Lane 15
    // Player side

    // Ennemi side

    // Lane 16
    // Player side

    // Ennemi side
}

void ElectricWell::createTriangle()
{
    // Lane 1
    // Player side

    // Ennemi side

    // Lane 2
    // Player side

    // Ennemi side

    // Lane 3
    // Player side

    // Ennemi side

    // Lane 4
    // Player side

    // Ennemi side

    // Lane 5
    // Player side

    // Ennemi side

    // Lane 6
    // Player side

    // Ennemi side

    // Lane 7
    // Player side

    // Ennemi side

    // Lane 8
    // Player side

    // Ennemi side

    // Lane 9
    // Player side

    // Ennemi side

    // Lane 10
    // Player side

    // Ennemi side

    // Lane 11
    // Player side

    // Ennemi side

    // Lane 12
    // Player side

    // Ennemi side

    // Lane 13
    // Player side

    // Ennemi side

    // Lane 14
    // Player side

    // Ennemi side

    // Lane 15
    // Player side

    // Ennemi side

    // Lane 16
    // Player side

    // Ennemi side
}

void ElectricWell::createX()
{
    // Lane 1
    // Player side

    // Ennemi side

    // Lane 2
    // Player side

    // Ennemi side

    // Lane 3
    // Player side

    // Ennemi side

    // Lane 4
    // Player side

    // Ennemi side

    // Lane 5
    // Player side

    // Ennemi side

    // Lane 6
    // Player side

    // Ennemi side

    // Lane 7
    // Player side

    // Ennemi side

    // Lane 8
    // Player side

    // Ennemi side

    // Lane 9
    // Player side

    // Ennemi side

    // Lane 10
    // Player side

    // Ennemi side

    // Lane 11
    // Player side

    // Ennemi side

    // Lane 12
    // Player side

    // Ennemi side

    // Lane 13
    // Player side

    // Ennemi side

    // Lane 14
    // Player side

    // Ennemi side

    // Lane 15
    // Player side

    // Ennemi side

    // Lane 16
    // Player side

    // Ennemi side
}

void ElectricWell::createV()
{
    // Lane 1
    // Player side

    // Ennemi side

    // Lane 2
    // Player side

    // Ennemi side

    // Lane 3
    // Player side

    // Ennemi side

    // Lane 4
    // Player side

    // Ennemi side

    // Lane 5
    // Player side

    // Ennemi side

    // Lane 6
    // Player side

    // Ennemi side

    // Lane 7
    // Player side

    // Ennemi side

    // Lane 8
    // Player side

    // Ennemi side

    // Lane 9
    // Player side

    // Ennemi side

    // Lane 10
    // Player side

    // Ennemi side

    // Lane 11
    // Player side

    // Ennemi side

    // Lane 12
    // Player side

    // Ennemi side

    // Lane 13
    // Player side

    // Ennemi side

    // Lane 14
    // Player side

    // Ennemi side

    // Lane 15
    // Player side

    // Ennemi side

    // Lane 16
    // Player side

    // Ennemi side
}

void ElectricWell::createStaires()
{
    // Lane 1
    // Player side

    // Ennemi side

    // Lane 2
    // Player side

    // Ennemi side

    // Lane 3
    // Player side

    // Ennemi side

    // Lane 4
    // Player side

    // Ennemi side

    // Lane 5
    // Player side

    // Ennemi side

    // Lane 6
    // Player side

    // Ennemi side

    // Lane 7
    // Player side

    // Ennemi side

    // Lane 8
    // Player side

    // Ennemi side

    // Lane 9
    // Player side

    // Ennemi side

    // Lane 10
    // Player side

    // Ennemi side

    // Lane 11
    // Player side

    // Ennemi side

    // Lane 12
    // Player side

    // Ennemi side

    // Lane 13
    // Player side

    // Ennemi side

    // Lane 14
    // Player side

    // Ennemi side

    // Lane 15
    // Player side

    // Ennemi side

    // Lane 16
    // Player side

    // Ennemi side
}

void ElectricWell::createU()
{
    // Lane 1
    // Player side

    // Ennemi side

    // Lane 2
    // Player side

    // Ennemi side

    // Lane 3
    // Player side

    // Ennemi side

    // Lane 4
    // Player side

    // Ennemi side

    // Lane 5
    // Player side

    // Ennemi side

    // Lane 6
    // Player side

    // Ennemi side

    // Lane 7
    // Player side

    // Ennemi side

    // Lane 8
    // Player side

    // Ennemi side

    // Lane 9
    // Player side

    // Ennemi side

    // Lane 10
    // Player side

    // Ennemi side

    // Lane 11
    // Player side

    // Ennemi side

    // Lane 12
    // Player side

    // Ennemi side

    // Lane 13
    // Player side

    // Ennemi side

    // Lane 14
    // Player side

    // Ennemi side

    // Lane 15
    // Player side

    // Ennemi side

    // Lane 16
    // Player side

    // Ennemi side
}

void ElectricWell::createFlat()
{
    // Lane 1
    // Player side

    // Ennemi side

    // Lane 2
    // Player side

    // Ennemi side

    // Lane 3
    // Player side

    // Ennemi side

    // Lane 4
    // Player side

    // Ennemi side

    // Lane 5
    // Player side

    // Ennemi side

    // Lane 6
    // Player side

    // Ennemi side

    // Lane 7
    // Player side

    // Ennemi side

    // Lane 8
    // Player side

    // Ennemi side

    // Lane 9
    // Player side

    // Ennemi side

    // Lane 10
    // Player side

    // Ennemi side

    // Lane 11
    // Player side

    // Ennemi side

    // Lane 12
    // Player side

    // Ennemi side

    // Lane 13
    // Player side

    // Ennemi side

    // Lane 14
    // Player side

    // Ennemi side

    // Lane 15
    // Player side

    // Ennemi side

    // Lane 16
    // Player side

    // Ennemi side
}

void ElectricWell::createHeart()
{
    // Lane 1
    // Player side

    // Ennemi side

    // Lane 2
    // Player side

    // Ennemi side

    // Lane 3
    // Player side

    // Ennemi side

    // Lane 4
    // Player side

    // Ennemi side

    // Lane 5
    // Player side

    // Ennemi side

    // Lane 6
    // Player side

    // Ennemi side

    // Lane 7
    // Player side

    // Ennemi side

    // Lane 8
    // Player side

    // Ennemi side

    // Lane 9
    // Player side

    // Ennemi side

    // Lane 10
    // Player side

    // Ennemi side

    // Lane 11
    // Player side

    // Ennemi side

    // Lane 12
    // Player side

    // Ennemi side

    // Lane 13
    // Player side

    // Ennemi side

    // Lane 14
    // Player side

    // Ennemi side

    // Lane 15
    // Player side

    // Ennemi side

    // Lane 16
    // Player side

    // Ennemi side
}

void ElectricWell::createStar()
{
    // Lane 1
    // Player side

    // Ennemi side

    // Lane 2
    // Player side

    // Ennemi side

    // Lane 3
    // Player side

    // Ennemi side

    // Lane 4
    // Player side

    // Ennemi side

    // Lane 5
    // Player side

    // Ennemi side

    // Lane 6
    // Player side

    // Ennemi side

    // Lane 7
    // Player side

    // Ennemi side

    // Lane 8
    // Player side

    // Ennemi side

    // Lane 9
    // Player side

    // Ennemi side

    // Lane 10
    // Player side

    // Ennemi side

    // Lane 11
    // Player side

    // Ennemi side

    // Lane 12
    // Player side

    // Ennemi side

    // Lane 13
    // Player side

    // Ennemi side

    // Lane 14
    // Player side

    // Ennemi side

    // Lane 15
    // Player side

    // Ennemi side

    // Lane 16
    // Player side

    // Ennemi side
}

void ElectricWell::createW()
{
    // Lane 1
    // Player side

    // Ennemi side

    // Lane 2
    // Player side

    // Ennemi side

    // Lane 3
    // Player side

    // Ennemi side

    // Lane 4
    // Player side

    // Ennemi side

    // Lane 5
    // Player side

    // Ennemi side

    // Lane 6
    // Player side

    // Ennemi side

    // Lane 7
    // Player side

    // Ennemi side

    // Lane 8
    // Player side

    // Ennemi side

    // Lane 9
    // Player side

    // Ennemi side

    // Lane 10
    // Player side

    // Ennemi side

    // Lane 11
    // Player side

    // Ennemi side

    // Lane 12
    // Player side

    // Ennemi side

    // Lane 13
    // Player side

    // Ennemi side

    // Lane 14
    // Player side

    // Ennemi side

    // Lane 15
    // Player side

    // Ennemi side

    // Lane 16
    // Player side

    // Ennemi side
}

void ElectricWell::createBird()
{
    // Lane 1
    // Player side

    // Ennemi side

    // Lane 2
    // Player side

    // Ennemi side

    // Lane 3
    // Player side

    // Ennemi side

    // Lane 4
    // Player side

    // Ennemi side

    // Lane 5
    // Player side

    // Ennemi side

    // Lane 6
    // Player side

    // Ennemi side

    // Lane 7
    // Player side

    // Ennemi side

    // Lane 8
    // Player side

    // Ennemi side

    // Lane 9
    // Player side

    // Ennemi side

    // Lane 10
    // Player side

    // Ennemi side

    // Lane 11
    // Player side

    // Ennemi side

    // Lane 12
    // Player side

    // Ennemi side

    // Lane 13
    // Player side

    // Ennemi side

    // Lane 14
    // Player side

    // Ennemi side

    // Lane 15
    // Player side

    // Ennemi side

    // Lane 16
    // Player side

    // Ennemi side
}

void ElectricWell::createInfinite()
{
    // Lane 1
    // Player side

    // Ennemi side

    // Lane 2
    // Player side

    // Ennemi side

    // Lane 3
    // Player side

    // Ennemi side

    // Lane 4
    // Player side

    // Ennemi side

    // Lane 5
    // Player side

    // Ennemi side

    // Lane 6
    // Player side

    // Ennemi side

    // Lane 7
    // Player side

    // Ennemi side

    // Lane 8
    // Player side

    // Ennemi side

    // Lane 9
    // Player side

    // Ennemi side

    // Lane 10
    // Player side

    // Ennemi side

    // Lane 11
    // Player side

    // Ennemi side

    // Lane 12
    // Player side

    // Ennemi side

    // Lane 13
    // Player side

    // Ennemi side

    // Lane 14
    // Player side

    // Ennemi side

    // Lane 15
    // Player side

    // Ennemi side

    // Lane 16
    // Player side

    // Ennemi side
}

void ElectricWell::draw(SDL_Renderer *renderer)
{
    for (auto l : lane_list_)
        l.drawLane(renderer);
}
