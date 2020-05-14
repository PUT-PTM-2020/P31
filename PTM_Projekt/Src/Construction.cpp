#include "..\Inc\Construction.hpp"

const std::vector<uint8_t> Construction::displayVector = {0x18, 0x3C, 0x7E, 0xFF, 0xFF, 0x7F, 0x3F, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0x7E, 0x3C, 0x18};
const uint8_t Construction::height = 8;
const uint8_t Construction::width = 15;

Construction::Construction(uint8_t x, uint8_t y, uint8_t hp)
{
	this->positionX = x;
	this->positionY = y;
	this->hp = hp;
}

Construction::~Construction(){}
std::vector<uint8_t> Construction::getDisplayVec(){return displayVector;}
uint8_t Construction::getHeight(){return height;}
uint8_t Construction::getWidth(){return width;}