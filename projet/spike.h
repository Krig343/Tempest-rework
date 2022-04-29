#ifndef SPIKE_H
#define SPIKE_H

#include <SDL.h> // Graphical interface
#include <string>

class Spike
{
public:
    std::string type_;
    int position_;

public:
    // Constructors
    Spike(const std::string &type, const float &pos);

    // IO
    void draw(SDL_Renderer *renderer);

private:
    friend inline bool operator==(const Spike &lhs, const Spike &rhs)
    {
        if (lhs.type_ == rhs.type_ &&
            lhs.position_ == rhs.position_)
            return true;
        return false;
    }
};

#endif // SPIKE_H