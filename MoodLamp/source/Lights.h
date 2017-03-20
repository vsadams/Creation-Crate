#pragma once

#include <arduino.h>
#include <pins_arduino.h>
class Lights
{
	const int RED_PIN; //red LED Digital Pin.
	const int GREEN_PIN; //green LED Digital Pin.
	const int BLUE_PIN; //blue LED Digital Pin.
	const int MAX_BRIGHTNESS = 150; //max brightness per light
	const float COMMON_MATH_VARIABLE = 180 / PI;
	
public:

	//digital pin locations for the red green and blue light.  lTransitionSpeed is the smoothness at which lights change
	Lights(int, int, int);

	~Lights();
	
	//turns off all the lights
	void turnOff();

	//updates the light cycle by slowly increasing one light while decreasing another
	void updateLightCycle();

	//initializes the lights to their base state...call before cycling the lights
	void enusreInitLights();

};
