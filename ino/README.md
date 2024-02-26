


### Hardware Requirements
- Arduino Board
- USB cable
- 12V 2A power supply
- laptop

### Software Requirements
- [Processing](https://processing.org/)
- [Pure Data](https://puredata.info)

### Setup

First, make sure you have installed the `oscP5` library in Processing. You can install it via the Processing IDE under Sketch -> Import Library -> Add Library, then search for `oscP5` and install it.

The Processing script starts an OSC server that listens for messages on port 12000 and opens a serial connection to an Arduino. It checks for incoming OSC messages with the address `/bla` and sends the float value from these messages over the serial connection to the Arduino.

Make sure to replace `Serial.list()[0]` with the index of the serial port that your Arduino is connected to. You can find the correct index by looking at the output of `printArray(Serial.list());` in the Processing console when you run your sketch.

#### References
- [l298n and stepper](https://lastminuteengineers.com/stepper-motor-l298n-arduino-tutorial/)