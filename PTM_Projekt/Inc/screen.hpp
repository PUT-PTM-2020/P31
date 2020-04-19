#pragma once

#include "libraries.hpp"

class Screen {
public:
	void display(display_config cfg, Player p);
	void display(display_config cfg, Enemy p);
	void display(display_config cfg, Construction p);
	void clear(display_config cfg);
};
