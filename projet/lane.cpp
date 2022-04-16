#include "lane.h"

//----------------------------- Constructors -----------------------------------

Lane::Lane(const Vec2 &pp1, const Vec2 &pp2, const Vec2 &ep1, const Vec2 &ep2, std::array<Uint8, 4> color) : player_begin_point_{pp1},
                                                                                                             player_end_point_{pp2},
                                                                                                             ennemi_begin_point_{ep1},
                                                                                                             ennemi_end_point_{ep2},
                                                                                                             color_{color}
{
}

//----------------------------- Lane controls ----------------------------------

/* The function sets the renderer's color to the color of the lane and then
 * prints the four lines composing a lane :
 * - the one on which the blaster is
 * - the one on which the ennemies appear
 * - the two binding the first ones without crossing eachother
 */
void Lane::drawLane(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, color_[0], color_[1], color_[2], color_[3]);
    SDL_RenderDrawLine(renderer, player_begin_point_.first, player_begin_point_.second, player_end_point_.first, player_end_point_.second);
    SDL_RenderDrawLine(renderer, player_end_point_.first, player_end_point_.second, ennemi_end_point_.first, ennemi_end_point_.second);
    SDL_RenderDrawLine(renderer, ennemi_end_point_.first, ennemi_end_point_.second, ennemi_begin_point_.first, ennemi_begin_point_.second);
    SDL_RenderDrawLine(renderer, ennemi_begin_point_.first, ennemi_begin_point_.second, player_begin_point_.first, player_begin_point_.second);
}