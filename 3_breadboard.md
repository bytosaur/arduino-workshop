# Example II: Interfacing the real world
![](/media/breadboard_shepherdingelectrons_uart.jpg)UART transceiver with 7400 series ICs, 
[shepherdingelectrons](https://shepherdingelectrons.blogspot.com/2020/07/uart-transceiver-for-breadboard-computer.html)

In the above picture we see a circuit expanding over several solderless breadboards. This is usually how a design is first implemented. The breadboard consist of groups of internally connected sockets. Once you know how it is mapped out it's very handy to connect two components and keep them in place.

![](/media/breadboard.jpg)

In this example we will connect a potentiometer and an led to our Arduino Board. More specifically, we want to control the blinking rate and intensity of the LED using a potentiometer. Let's split our problem into two: reading the analog potentiometer and controlling the led.

### Reading an analog sensor to the Serial Interface
![](/media/poti.jpg)

Let's introduce two new concepts: 
- __variables__: placeholders for values (integer, float, ...)
- __analogRead()__: converting an analog signal to a digital value (sampling)
- __Serial__: a class having different functionalities involved in serial communication (here over USB)

___NOTE___: in order to see the values coming from the Arduino, you need to open `Tools` -> `Serial Monitor`.

```C++
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
}
```

### Adding the LED
![](/media/poti_led.jpg)

Add the following lines to the correct location. Make sure to use `pinMode()`.
```C++
  ...
  int analogValue = sensorValue / 4;
  analogWrite(3, analogValue);
  ...
```
Think about a way to control the rate to led blinking.

[Back <](2_arduino_ide.md) ~~~ [> Next](4_prototype.md)