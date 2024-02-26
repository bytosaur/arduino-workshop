

// These constants won't change. They're used to give names to the pins used:
const int analogOutPin = 11; 
const int digitalOutPin1 = 9;
const int digitalOutPin2 = 8;

void control(int controlValue){
  if (controlValue > 0){
    digitalWrite(digitalOutPin1, HIGH);
    digitalWrite(digitalOutPin2, LOW);
  }
  else if (controlValue < 0){
    digitalWrite(digitalOutPin1, LOW);
    digitalWrite(digitalOutPin2, HIGH);
  }
  else{
    digitalWrite(digitalOutPin1, LOW);
    digitalWrite(digitalOutPin2, LOW);
  }
}

// instanciate global variables
int sensorValue = 0;  // value read from the pot
int outputValue = 0;  // value output to the PWM (analog out)
int counter = 0;      // counter for the loop

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(analogOutPin, OUTPUT);
  pinMode(digitalOutPin1, OUTPUT);
  pinMode(digitalOutPin2, OUTPUT);
}

void loop() {

  counter = counter % 1024; // keep counter between 0 and 1023
  sensorValue = counter % 512; // keep sensorValue between 0 and 511

  // If counter is smaller than 512, go forward and speed down
  if (counter<512) {
    control(1);
    outputValue = map(sensorValue, 0, 511, 0, 255);
  }
  // If not, go backwards and speed up
  else {
    control(-1);
    outputValue = map(sensorValue, 511, 0, 255, 0);
  }

  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  delay(50);

  // increment the counter
  counter++;
  
  // print the results to the Serial Monitor:
  Serial.print("counter = " );
  Serial.print(counter);

}
