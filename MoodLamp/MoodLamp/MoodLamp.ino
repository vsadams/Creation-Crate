#include "Lights.h"
/*Creation Create Mood Lamp
This lamp smoothly cycles through a color spectrum.
It only turns on when surroundings are dark.
*/


const int RED_PIN = 11; //red LED in Digital Pin 11.
const int GREEN_PIN = 10; //green LED in Digital Pin 10.
const int BLUE_PIN = 9; //blue LED in Digital Pin 9.
const int AMBIENT_LIGHT_MIN = 100; //This is the minimum value the ldr must return in order for the light to turn on


//The sre the pins we are using wth the UNO R3 (Arduino-Compatible).  You can see the numbers on the board itself.
int ldrPin = 0; //LDR in Analog Input 0 to read the surrounding light.

int _ambientLight = 0; //This variable stores the value of the light in the room.
unsigned long lastAmbientLightCheck = 0; //This variable stores the last time the ambient light check was hit

Lights lights = Lights(RED_PIN, GREEN_PIN, BLUE_PIN); //holds the current values of all the lights

//We will be using the value 180/PI a lot in the main loop, so to save time we will calculate it once here in the setup and store in the CommonmathVariable.  Note; it is PI(i) not P1(one)
float CommonMathVariable = 180 / PI;


void setup() {
	
}


//gets the value from the light sensor. only checks every second.
int get_ambientLight() {
	unsigned long currentMillis = millis(); //get how long the current program has been running
	unsigned long millisForNextCheck = lastAmbientLightCheck + 1000; //only check every second
	
	//if the ambient light has not been checked at all
	//or
	//the last time checked + 1 second is less than now
	//or
	//if millis() has reset then update ambient light and set lastAmbientLightCheck
	if (lastAmbientLightCheck == 0 
		|| millisForNextCheck <= currentMillis 
		|| currentMillis <= lastAmbientLightCheck ) {
		_ambientLight = analogRead(ldrPin);
		lastAmbientLightCheck = currentMillis;
	}
		
	return _ambientLight;
}
void loop() {

	int currentAmbientLight;
	//make sure the lights are ready to receive commands
	lights.enusreInitLights();

	currentAmbientLight = get_ambientLight();
	//This if statement will make the lamp turn on only if it is dark.  the darker it is, the higher the number.
	if (currentAmbientLight > AMBIENT_LIGHT_MIN) {
		Serial.println(currentAmbientLight);
		lights.updateLightCycle();
	}
	//This else statement will only activate if the if statement does not (ie. If it is too bright in the room).  The LEDs will turn off.
	else {
		lights.turnOff();
	}
	delay(5);
	
}
