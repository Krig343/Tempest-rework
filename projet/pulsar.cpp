// Will be removed

#include "pulsar.h"

// Constructors
Pulsar::Pulsar(const bool &shooting, const int &pos, const std::array<Uint8, 4> &color, const std::string &tpe, bool pulse) : Ennemi::Ennemi(shooting,
                                                                                                                                             pos,
                                                                                                                                             color,
                                                                                                                                             "pulsar"),
                                                                                                                              is_pulsing_{pulse}
{
}

Pulsar::Pulsar(const Pulsar &puls) : Pulsar::Pulsar(puls.is_shooting_,
                                                    puls.position_,
                                                    puls.color_,
                                                    "pulsar",
                                                    puls.is_pulsing_)
{
}

// Spiker controls
void Pulsar::pulse()
{
    is_pulsing_ = true;
    // TODO
    is_pulsing_ = false;
}