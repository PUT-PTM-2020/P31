#include "screen.hpp"

void Screen::display(display_config cfg, Entity* p) {
	uint16_t row  = p->positionY/8;
	uint8_t up = 0;
	uint8_t down = 0;

	for (int i = 0; i < p->width; i++) {
		display_set_dxy(&cfg, vertical, p->positionX+i, row);

		down=0;
		up = p->displayVector[i];
		for (int j = 0; j < p->positionY%8; j++) {
			down = down << 1;
		  	if (up>127) {
		  		down+=1;
		  		}
		  	up = up << 1;
		  }
		  display_write_data(&cfg, up);
		  display_write_data(&cfg, down);
	}
}

void Screen::display(display_config cfg, Construction p) {
	uint16_t row  = p.positionY/8;
	uint8_t temp = 0;
	uint8_t toAdd = 0;

	for (int i = 0; i < p.width; i++) {
		display_set_dxy(&cfg, vertical, p.positionX+i, row);

		toAdd=0;
		temp = p.displayVector[i];
		for (int j = 0; j < p.positionY%8; j++) {
			toAdd = toAdd << 1;
		  	if (temp>127) {
		  		toAdd+=1;
		  		}
		  	temp = temp << 1;
		  }
		  display_write_data(&cfg, temp);
		  if (toAdd != 0)
			  display_write_data(&cfg, toAdd);
	}
}


void Screen::clear(display_config cfg) {
	for (int i = 0; i < 504; i++)
			display_write_data(&cfg, 0x00);
}
