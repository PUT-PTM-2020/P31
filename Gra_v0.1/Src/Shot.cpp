#include "..\Inc\Shot.hpp"

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
void Shot::movement(){}

Entity shooted(){

}