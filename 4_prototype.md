# PROTOTYPE: motor control with OSC

In this example we want to control a stepper motor using the OSC protocol which is widely known among creative application. Again we split our example in two tasks: 1. controlling the motor and 2. interpreting incoming OSC messages and using serial interface to communicate with the Arduino.

## PART I: controlling a motor
Let's start with setting up the hardware.

### Hardware Requirements
- 12V 1A power supply
- power supply adapter (pinout)
- stepper motor Nema 17
- l298n driver
- cables


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
- ↑ simple, reliable, cheap
- ↓ no error correction, resonance issues, less efficient, looses torque at high speed

##### Servo motor
- driver required: no
- positioning: yes
- ↑ error correction, efficient, high speed torque
- ↓ expensive, noisy, difficult to setup

When precision is a top priority and the system may encounter variable loads or requires dynamic speed changes, a servo motor system is usually the better choice. However, for simpler applications where the load is controlled and constant, and the speed is low to moderate, a stepper motor can be a cost-effective solution that provides sufficient precision.

### The L298N motor driver
The L298N motor driver is a popular choice for controlling DC motors. It is a dual H-bridge motor driver that can drive two DC motors or one stepper motor.

![](/media/etechnophiles.com_l298n.jpg)

__NOTE:__ The L298N is not ideal for stepper motors as it does not support microstepping. It's better to use DRV8825 or A4988.

##### Features of the L298N motor driver:
- independent control of two motors
- maximum current of 2A per channel
- high voltage range (5V - 35V)
- direction and speed control for DC motors

### Wiring it all up
__IMPORTANT__: Before we begin the wiring we need to identify the phases of the stepper motor. Use a multimeter to measure the resistance. A small resistance (~ 10 Ohms) between two cables identifies a phase. Connect them to one motor output. The polarity is not important.

__Important__: In a project with multiple power sources it is important to share the same ground!

![](/media/makersguide_l298n_schematic.jpg)


### Code: stepper motor control
The code can be found in [ino/l298n_stepper/l298n_stepper.ino](/ino/l298n_stepper/l298n_stepper.ino)


## PART II: adding the OSC protocol

### Software Requirements
- [Pure Data](https://puredata.info): creating a patch that sends OSC
- [Processing](https://processing.org/): creating a program that reads OSC and sends the data over the serial interface
- [Arduino](ino/l298n_stepper_OSC/l298n_stepper_OSC.ino): The update code can be found in [ino/l298n_stepper_OSC/l298n_stepper_OSC.in](ino/l298n_stepper_OSC/l298n_stepper_OSC.ino)

### Processing Setup

First, make sure you have installed the __OSCp5__ library in Processing. You can install it via the Processing IDE under `Sketch` -> `Import Library` -> `Add Library`, then search for __OSCp5__ and install it.

Load the code from [osc/processing/osc2serial.pde](osc/processing/osc2serial.pde) into the Processing application.

The Processing script starts an OSC server that listens for messages on port 12000 and opens a serial connection to an Arduino. It checks for incoming OSC messages with the address `/bla` and sends the float value from these messages over the serial connection to the Arduino.

__NOTE__: only one application can use the Serial port a time. You may need to close the Serial Monitor. When programming a new sketch to the Arduino, you need to stop the Processing application.

-> Hit Play!

Make sure to replace the `0` in `Serial.list()[0]` with the index of the serial port that your Arduino is connected to. You can find the correct index by looking at the output of `printArray(Serial.list());` in the Processing console when you run your sketch.

-> Hit Play!


### Pure Data Setup
After installing PD, click `File` -> `Open` and select the file in `osc/puredata/sender_single.pd`.

-> Hit the Message Boxes with the numbers in it.

### et voilà


[Back <](3_breadboard.md) ~~~