#include "Lights.h"

bool initialized = false;

float colorTracker;

Lights::Lights(int rPin, int gPin, int bPin)
	: RED_PIN(rPin),
	GREEN_PIN(gPin),
	BLUE_PIN(bPin) {
	colorTracker = 0;

}

void Lights::enusreInitLights() {

	if (initialized) {
		return;
	}

	//This tells the UNO R3 to send data out to the LEDs.
	pinMode(RED_PIN, OUTPUT);
	pinMode(GREEN_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);

	turnOff();

	initialized = true;
}



void Lights::turnOff() {
	//This sets all the outputs (LEDs) to low (as in off), so that they do not turn on during startup.
	digitalWrite(RED_PIN, LOW);
	digitalWrite(GREEN_PIN, LOW);
	digitalWrite(BLUE_PIN, LOW);
}

void Lights::updateLightCycle() {
	
	float red = MAX_BRIGHTNESS * abs(sin(colorTracker * (COMMON_MATH_VARIABLE)));
	float green = MAX_BRIGHTNESS * abs(sin((colorTracker + PI/3) * (COMMON_MATH_VARIABLE)));
	float blue = MAX_BRIGHTNESS * abs(sin((colorTracker + (2 * PI) / 3) * (COMMON_MATH_VARIABLE)));
	
	analogWrite(RED_PIN, red);
	analogWrite(GREEN_PIN, green);
	analogWrite(BLUE_PIN, blue);

	if (colorTracker < PI) {
		colorTracker += 0.00001;
	}
	else {
		colorTracker = 0;
	}
	

}


Lights::~Lights()
{
}


