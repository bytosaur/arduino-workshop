# EXAMPLE I

### Installing Arduino IDE 2.X

1. Visit [the Arduino webpage](https://www.arduino.cc/en/software) to download the Arduino Integrated Development Editor (IDE) version 2.X for your operating System. Click [here](https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/) for a guide on installing.

2. Plug in your Arduino Development Board

3. Open the Arduino IDE

##### Understanding the code

The following piece of code is the bare minimum that is expected by the Arduino Platform. It defines two functions __setup()__ and __loop()__. This is the same approach as in Processing or OpenFrameworks. 
```C++
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}
```

### Hello Arduino
Let's fill the blanks:

1. Go to `File` -> `Examples` -> `01.Basics` -> `Blink`

2. Hit the `Verify` √ button to compile the code and check for errors

3. If there are no errors you can upload the code to the board using the `Upload` → button

4. Check that the LED 13 on the board is blinking

```C++
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function repeats forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (5V)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off (0V)
  delay(1000);                      // wait for a second
}
```
Remember:
- Using a digital pin (here builtin) requires setting its mode
- __digitalWrite()__ allows us to apply 5V or 0V (ground) to an output pin
- __delay()__ allows us to slow down the loop

### References
- [IDE Getting Started](https://docs.arduino.cc/software/ide-v2/tutorials/getting-started-ide-v2/)

[Back <](1_arduino.md) ~~~ [> Next](3_breadboard.md)