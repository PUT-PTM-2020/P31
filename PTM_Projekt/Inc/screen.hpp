#pragma once

#include "libraries.hpp"

class Screen {
public:
	void display(display_config cfg, Entity* p);
	void display(display_config cfg, Construction p);

	void clear(display_config cfg);
};
