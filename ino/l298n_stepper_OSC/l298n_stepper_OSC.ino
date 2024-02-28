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
    // set the speed at 200 rpm:
    myStepper.setSpeed(200);
    // use the built-in LED as a visual indicator
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
    // check if data has been sent from the computer:
    if (Serial.available() > 0){
        float serialValue = Serial.parseFloat();

        // convert the floating point value to integer
        int outputValue = (int) serialValue;

        myStepper.step(outputValue * stepsPerRevolution);
        Serial.println(outputValue);
    }

    digitalWrite(LED_BUILTIN, LOW); 
    delay(20);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(20);
}