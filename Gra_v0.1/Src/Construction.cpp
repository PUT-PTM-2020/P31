#include "..\Inc\Construction.hpp"

Construction::Construction() {
	positionX = 40;
	positionY = 0;
	height = 8;
	width = 15;
	hp = 10;
	displayVector = {0x18, 0x3C, 0x7E, 0xFF, 0xFF, 0x7F, 0x3F, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0x7E, 0x3C, 0x18};
}