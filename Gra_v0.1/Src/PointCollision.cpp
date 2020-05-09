#include "..\Inc\PointColission.hpp"


bool lineCollision(uint8_t a, uint8_t b, uint8_t c){
    if (a <= b) return (c >= a)&&(c <= b);
    else if (a > b) return (c >= b)&&(c <= a);
}


bool pointCollision(Entity& entity, std::pair<uint8_t, uint8_t> point){
    uint8_t x = entity.positionX + entity.getWidth()-1;
    uint8_t y = entity.positionY + entity.getHeight()-1;
    return lineCollision(entity.positionX, x, point.first) && lineCollision(entity.positionY, y, point.second);
}

bool entityInnerCollision(Entity& entity1, Entity& entity2){
    if (entity2.positionY <= entity1.positionY && entity1.positionX <= entity2.positionX){
        return (lineCollision(entity2.positionY, entity2.positionY+entity2.getHeight()-1, entity1.positionY)
            && lineCollision(entity1.positionX, entity1.positionX+entity1.getWidth()-1, entity2.positionX));
    }
    else if (entity1.positionY <= entity2.positionY && entity2.positionX <= entity1.positionX) {
        return (lineCollision(entity1.positionY, entity1.positionY+entity1.getHeight()-1, entity2.positionY)
            && lineCollision(entity2.positionX, entity2.positionX+entity2.getWidth()-1, entity1.positionX));
    }
    else {
        return false;
    }
    
}

bool entityCollision(Entity& entity1, Entity& entity2){
    std::pair<uint8_t, uint8_t> corner;
    
    corner.first = entity1.positionX;
    corner.second = entity1.positionY;
    if (pointCollision(entity2, corner)){return true;} //(X,Y)

    corner.first += entity1.getWidth()-1;
    if (pointCollision(entity2, corner)){return true;} //(X+w-1, Y)

    corner.second += entity1.getHeight()-1;
    if (pointCollision(entity2, corner)){return true;} //(X+w-1, Y+h-1)
    
    corner.first = entity1.positionX;
    if (pointCollision(entity2, corner)){return true;} //(X, Y+h-1)

    corner.first = entity2.positionX;
    corner.second = entity2.positionY;
    if (pointCollision(entity1, corner)){return true;}

    corner.first += entity2.getWidth()-1;
    corner.second += entity2.getHeight()-1;
    if (pointCollision(entity1, corner)){return true;}

    return entityInnerCollision(entity1, entity2);
}