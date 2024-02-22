

// These constants won't change. They're used to give names to the pins used:
const int analogOutPin = 10; 
const int digitalOutPin1 = 9;
const int digitalOutPin2 = 8;

int sensorValue = 0;  // value read from the pot
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
  sensorValue = counter % 512;

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  pressed = counter%1024==0;

  // If button is pressed - change rotation direction
  if (counter>512) {
    digitalWrite(digitalOutPin1, HIGH);
    digitalWrite(digitalOutPin2, LOW);
    rotDirection = 1;
    // map it to the range of the analog out:
    outputValue = map(sensorValue, 512, 0, 0, 255);
  }
  // If button is pressed - change rotation direction
  else {
    digitalWrite(digitalOutPin1, LOW);
    digitalWrite(digitalOutPin2, HIGH);
    rotDirection = 0;
    // map it to the range of the analog out:
    outputValue = map(sensorValue, 0, 512, 0, 255);
  }

  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(50);
  counter++;
  counter=counter%1024;

  Serial.print(rotDirection);
}
