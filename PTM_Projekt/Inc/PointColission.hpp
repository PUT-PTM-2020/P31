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
bool pointCollision(Entity& entity, std::pair<uint8_t, uint8_t> point);

/**
 * Checks if there is a collision between insides of 2 entities
 * 
 * Checks if one entity is within another with assumption 
 * that none of the corners are in the area of another entity
 * 
 * ARG:
 *  entity1 - first entity to check
 *  entity2 - second entity to check
 * RET:
 *  true if there was a collision, flase otherwise
*/
bool entityInnerCollision(Entity& entity1, Entity& entity2);

/**
 * Chcecks is one entity is in area of another in any way.
 * 
 * ARG:
 *  entity1 - first entity to check
 *  entity2 - second entity to check
 * RET:
 *  true if there was a collision, flase otherwise
*/
bool entityCollision(Entity& entity1, Entity& entity2);