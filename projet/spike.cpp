#include "spike.h"

//----------------------------- Constructors -----------------------------------

Spike::Spike(const std::string &type, const float &pos) : type_{type},
                                                          position_{pos}
{
}

//--------------------------------- IO -----------------------------------------
void Spike::draw(SDL_Renderer *renderer)
{
}