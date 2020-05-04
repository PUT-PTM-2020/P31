#pragma once

#include "libraries.hpp"
#include "Includes.hpp"

class Joystick{
public:
	uint16_t valueX;
	uint16_t valueY;

	/**
	 * Setter valueX and valueY
	 *
	 * RET:
	 *  void
	*/
	void getJoystick();
};
