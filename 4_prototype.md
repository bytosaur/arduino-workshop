# PROTOTYPE: motor control with OSC


### Three types of motors
There are mainly three types of motors used in DIY electronics.

##### DC Motor
- driver required: yes
- positioning: no
- ↑ simple, linear, high starting torque, quick
- ↓ no positioning


##### Stepper Motor
- driver required: yes
- positioning: yes
- ↑ simple, realiable, cheap
- ↓ no error correction, resonance issues, less efficient, looses torque at high speed

##### Servo motor
- driver required: no
- positioning: yes
- ↑ error correction, efficient, high speed torque
- ↓ expensive, noisy, difficult to setup

When precision is a top priority and the system may encounter variable loads or requires dynamic speed changes, a servo motor system is usually the better choice. However, for simpler applications where the load is controlled and constant, and the speed is low to moderate, a stepper motor can be a cost-effective solution that provides sufficient precision.

### The L298N motor driver
The L298N motor driver is a popular choice for controlling DC motors. It is a dual H-bridge motor driver that can drive two DC motors or one stepper motor.

__NOTE:__ The L298N is not intended for stepper motors as it does not support microstepping. It's better to use DRV8825 or A4988.

##### Features of the L298N motor driver:
- independent control of two motors
-maximum current of 2A per channel
- up to 46V
- built-in protection against overcurrent and overheating.
- direction and speed control for DC motors
- precise positioning and control of stepper motors.

##### Wiring the L298N motor driver:
To use the L298N motor driver, you need to connect it to your microcontroller or Arduino board. Here is a basic wiring diagram:


### Hardware Requirements
- Arduino Board
- USB cable
- 12V 1A power supply
- power supply adapter (pinout)
- stepper motor nema 17
- laptop
- l298n driver
- cables

### Software Requirements
- [Processing](https://processing.org/)
- [Pure Data](https://puredata.info)

### Setup

First, make sure you have installed the `oscP5` library in Processing. You can install it via the Processing IDE under Sketch -> Import Library -> Add Library, then search for `oscP5` and install it.

The Processing script starts an OSC server that listens for messages on port 12000 and opens a serial connection to an Arduino. It checks for incoming OSC messages with the address `/bla` and sends the float value from these messages over the serial connection to the Arduino.

Make sure to replace `Serial.list()[0]` with the index of the serial port that your Arduino is connected to. You can find the correct index by looking at the output of `printArray(Serial.list());` in the Processing console when you run your sketch.



[Back <](3_breadboard.md) ~~~