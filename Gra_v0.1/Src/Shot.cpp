#include "..\Inc\Shot.hpp"
#include "..\Inc\Level.hpp"
#include "..\Inc\PointColission.hpp"

Shot::Shot(){}
Shot::Shot(uint8_t X, uint8_t Y, uint8_t speed){
    this->positionX = X;
    this->positionY = Y;
    this->speed = speed;
}
void Shot::setX(uint8_t X){
    this->positionX = X;
}
void Shot::setY(uint8_t Y){
    this->positionY = Y;
}
void Shot::setSpeed(uint8_t speed){
    this->speed = speed;
}
void Shot::movement(){
    this->positionY -= speed;
}

std::pair<std::string, uint8_t> Shot::shooted(Level& activeLevel){
    std::pair<uint8_t, uint8_t> point(this->positionX, this->positionY);
    std::pair<std::string, uint8_t> ret;
    
    for (int i=0; i<activeLevel.Enemies.size(); i++){
        if (pointCollision(activeLevel.Enemies.at(i), point)){
            ret.first = "Enemies";
            ret.second = i;
            return ret;
        }
    }
    
    for (int i=0; i<activeLevel.Constructions.size(); i++){
        if (pointCollision(activeLevel.Constructions.at(i), point)){
            ret.first = "Constructions";
            ret.second = i;
            return ret;
        }
    }

    ret.second = 0;
    
    if (pointCollision(activeLevel.player, point)){
        ret.first = "Player";
        return ret;
    }
    else
    {
        ret.first = "null";
        return ret;
    }
    
}
