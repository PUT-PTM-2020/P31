#include "..\Inc\PointColission.hpp"


bool lineCollision(uint8_t a, uint8_t b, uint8_t c){
    if (a <= b) return (c >= a)&&(c <= b);
    else if (a > b) return (c >= b)&&(c <= a);
}


bool pointCollision(Entity& entity, uint8_t& width, uint8_t& height, std::pair<uint8_t, uint8_t> point){
    uint8_t x = entity.positionX + width;
    uint8_t y = entity.positionY + height;
    return lineCollision(entity.positionX, x, point.first) && lineCollision(entity.positionY, y, point.second);
}