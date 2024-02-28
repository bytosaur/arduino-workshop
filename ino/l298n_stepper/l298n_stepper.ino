// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation
const int stepsPerRevolution = 200;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution,8,9,10,11);


void setup()
{
	// initialize the serial port:
	Serial.begin(9600);
	// set the speed at 60 rpm:
	myStepper.setSpeed(60);
    // use the built-in LED as a visual indicator
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
	// step one revolution in one direction:
	Serial.println("clockwise");
	myStepper.step(stepsPerRevolution);
	delay(500);
	digitalWrite(LED_BUILTIN, LOW); 

	// step one revolution in the other direction:
	Serial.println("counterclockwise");
	myStepper.step(-stepsPerRevolution);
	delay(500);
	digitalWrite(LED_BUILTIN, HIGH);
}