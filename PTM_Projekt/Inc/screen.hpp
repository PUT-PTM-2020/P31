#pragma once

#include "libraries.hpp"
#include "Includes.hpp"

class Screen {
public:
	/**
	 * Displays character: player or enemy
	 *
	 * ARG:
	 *  cfg - display config
	 *  p - character
	 * RET:
	 *  void
	*/
	void display(display_config cfg, Character* p);
	/**
	 * Displays construction
	 *
	 * ARG:
	 *  cfg - display config
	 *  p - construction
	 * RET:
	 *  void
	*/
	void display(display_config cfg, Entity p);
	/**
	 * Clears display
	 *
	 * ARG:
	 *  cfg - display config
	 * RET:
	 *  void
	*/
	void clear(display_config cfg);
};
