#include "lane.h"

//----------------------------- Constructors -----------------------------------

Lane::Lane(const SDL_Point &f1, const SDL_Point &f2,
           const SDL_Point &b3, const SDL_Point &b4)
{
    frontMiddle_ = {(f1.x + f2.x)/2, 
                    (f1.y + f2.y)/2};
    backMiddle_ = {(b3.x + b4.x)/2, 
                   (b3.y + b4.y)/2};

    laneAngle_ = acos(((backMiddle_.y - frontMiddle_.y)) / 
                      (sqrt((backMiddle_.x - frontMiddle_.x)*(backMiddle_.x - frontMiddle_.x) + 
                            (backMiddle_.y - frontMiddle_.y)*(backMiddle_.y - frontMiddle_.y))));

    if(frontMiddle_.x < backMiddle_.x)
        laneAngle_ = -laneAngle_;

    frontSize_ = sqrt((f2.x - f1.x)*(f2.x - f1.x) + (f2.y - f1.y)*(f2.y - f1.y));
    backSize_ = sqrt((b3.x - b4.x)*(b3.x - b4.x) + (b3.y - b4.y)*(b3.y - b4.y));
}

float Lane::getScale(const float position){
    return position*frontSize_ + (1.0 - position)*backSize_;
}

float Lane::getAngle(){
    return laneAngle_;
}

SDL_Point Lane::getPosition(const float position){
    return {position*frontMiddle_.x + (1.0 - position)*backMiddle_.x,
            position*frontMiddle_.y + (1.0 - position)*backMiddle_.y};
}