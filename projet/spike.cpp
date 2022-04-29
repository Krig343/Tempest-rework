#include "spike.h"

//----------------------------- Constructors -----------------------------------

Spike::Spike(const int &lane, const float &pos) : Ennemi::Ennemi(false,
                                                                 pos,
                                                                 lane,
                                                                 "spike")
{
}

//--------------------------------- IO -----------------------------------------
void Spike::initModelPolygon()
{
    
}