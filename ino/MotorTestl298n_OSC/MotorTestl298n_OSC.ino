

// These constants won't change. They're used to give names to the pins used:
const int analogOutPin = 11; 
const int digitalOutPin1 = 9;
const int digitalOutPin2 = 8;

float sensorValue = 0.0;  // value read from the pot
int outputValue = 0;  // value output to the PWM (analog out)
int counter = 0; 
int rotDirection = 0;
int pressed = false;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(analogOutPin, OUTPUT);
  pinMode(digitalOutPin1, OUTPUT);
  pinMode(digitalOutPin2, OUTPUT);
}

void loop() {
  // read the analog in value:
  if (Serial.available() > 0){
    sensorValue = Serial.parseFloat();
  
  outputValue = sensorValue;
  //outputValue = sensorValue;

  // change the analog out value:
  analogWrite(analogOutPin, outputValue);
  digitalWrite(digitalOutPin1, HIGH);
  digitalWrite(digitalOutPin2, LOW);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  counter++;
  counter=counter%1024;

  }

}
