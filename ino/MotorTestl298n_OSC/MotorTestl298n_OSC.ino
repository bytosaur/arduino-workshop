

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
float serialValue = 0.0;  // value read from the serial port
int outputValue = 0;      // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(analogOutPin, OUTPUT);
  pinMode(digitalOutPin1, OUTPUT);
  pinMode(digitalOutPin2, OUTPUT);
  control(1); // forward
}


void loop() {

  // check if data has been sent from the computer:
  if (Serial.available() > 0){
    serialValue = Serial.parseFloat();
  
    // convert the floating point value to integer
    outputValue = (int) serialValue;

    // change the analog out value:
    analogWrite(analogOutPin, outputValue);
  }

  // wait 10 milliseconds before the next loop for the analog-to-digital
  delay(10);

}
