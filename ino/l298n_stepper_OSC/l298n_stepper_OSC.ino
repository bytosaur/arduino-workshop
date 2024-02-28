// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation
const int stepsPerRevolution = 200;

float serialValue = 0;
int outputValue = 0;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 2,3,4,5);


void setup()
{
  Serial.begin(9600);
	// set the speed at 60 rpm:
	myStepper.setSpeed(200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{

   // check if data has been sent from the computer:
  if (Serial.available() > 0){
    serialValue = Serial.parseFloat();
  
    // convert the floating point value to integer
    outputValue = (int) serialValue;

	  myStepper.step(outputValue * stepsPerRevolution);
    Serial.println(outputValue);
  }

  digitalWrite(LED_BUILTIN, LOW); 
	delay(20);
  digitalWrite(LED_BUILTIN, HIGH);
	delay(20);
}