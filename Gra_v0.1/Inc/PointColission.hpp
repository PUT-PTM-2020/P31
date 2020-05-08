#pragma once

#include "Includes.hpp"
#include "Level.hpp"


/**
 * Checks if c is in <a,b> or <b,a>
 * 
 * ARG:
 *  a - first number of including interval
 *  b - second number of including interval
 *  c - number to be checked
 * RET:
 *  true if c is in the interval; false otherwise
*/
bool lineCollision(uint8_t a, uint8_t b, uint8_t c);

/**
 * Checks if entity geometrically contains point (x,y) based on entity's coordinates, hight and width
 * 
 * ARG:
 *  entity - entity for checking
 *  w - width if entity
 *  h - height of entity
 *  point - ordered pair of 2 coordinates, x as first, y as second 
 * RET:
 *  true if entity contains point; false otherwise
*/
bool pointCollision(Entity& entity, uint8_t width, uint8_t height, std::pair<uint8_t, uint8_t> point);