#pragma once

#include "libraries.hpp"

class Screen {
public:
	void display(display_config cfg, Character* p);
	void display(display_config cfg, Entity p);

	void clear(display_config cfg);
};
