#define button 3
#define ledSet1 4
#define ledSet2 5
#define ledSet3 6
#define ledSet4 7

//buttonState will determine if the button is on or off
int buttonState;

int roll;

//time is a value measured in milliseconds
int time = 2000;


void setup()
{
	Serial.begin(9600);
	pinMode(ledSet1, OUTPUT);
	pinMode(ledSet2, OUTPUT);
	pinMode(ledSet3, OUTPUT);
	pinMode(ledSet4, OUTPUT);
	pinMode(button, INPUT);
	randomSeed(analogRead(0));


}


void loop()
{
	buttonState = digitalRead(button);
	
	if (buttonState == HIGH) {
		
		roll = random(1, 7);

		if (roll == 1) {
			digitalWrite(ledSet4, HIGH);
		}

		if (roll == 2) {
			digitalWrite(ledSet1, HIGH);
		}

		if (roll == 3) {
			digitalWrite(ledSet1, HIGH);
			digitalWrite(ledSet4, HIGH);
		}
		if (roll == 4) {
			digitalWrite(ledSet1, HIGH);
			digitalWrite(ledSet2, HIGH);
		}

		if (roll == 5) {
			digitalWrite(ledSet4, HIGH);
			digitalWrite(ledSet1, HIGH);
			digitalWrite(ledSet2, HIGH);
		}

		if (roll == 6) {
			digitalWrite(ledSet1, HIGH);
			digitalWrite(ledSet2, HIGH);
			digitalWrite(ledSet3, HIGH);
		}
		else {

		}

		delay(time);
	}

	digitalWrite(ledSet1, LOW);
	digitalWrite(ledSet2, LOW);
	digitalWrite(ledSet3, LOW);
	digitalWrite(ledSet4, LOW);
}
