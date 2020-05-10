#include "screen.hpp"
/*
void Screen::display(display_config cfg, Character* p) {
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
*/

void display(display_config cfg, Shot* p) {
	int w = 1;
	int h = 1;
	uint8_t disp = 0x08;

	display_set_dxy(&cfg, vertical, p->positionX, p->positionY);
	display_write_data(&cfg, disp);
}

void display(display_config cfg, Entity* p) {
	uint16_t row  = p->positionY/8;
	uint8_t temp = 0;
	uint8_t toAdd = 0;

	int w = p->getWidth();
	int h = p->getHeight();
	std::vector<uint8_t> dispVec = p->getDisplayVec();

	for (int i = 0; i < w; i++) {
		display_set_dxy(&cfg, vertical, p->positionX+i, row);

		toAdd=0;
		temp = dispVec[i];
		for (int j = 0; j < p->positionY%8; j++) {
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

void clear(display_config cfg) {
	for (int i = 0; i < 504; i++)
			display_write_data(&cfg, 0x00);
}

void displayLevel(display_config cfg, Level* l){

	for (int i = 0; i < l->Constructions.size(); i++){
		display(cfg, &l->Constructions[i]);
	}
	for (int i = 0; i < l->Enemies.size(); i++){
			display(cfg, &l->Enemies[i]);
		}

	display(cfg, &l->player);
	if (l->enemyShot != nullptr)
		display(cfg, l->enemyShot);
	if (l->playerShot != nullptr)
		display(cfg, l->playerShot);
}
