
import oscP5.*;
import netP5.*;
import processing.serial.*;

OscP5 oscP5;
Serial mySerial;
float valueToSend = 0.0;

void setup() {
  // Start the OSC listener on port 12000
  oscP5 = new OscP5(this, 12000);
  
  // List all the available serial ports
  printArray(Serial.list());

  // Open the serial port that the Arduino is connected to
  mySerial = new Serial(this, Serial.list()[4], 9600);
  mySerial.bufferUntil('\n'); // Set the serial to read until newline character
}

void draw() {
  // Processing's draw loop runs continuously but we do nothing here
}

void oscEvent(OscMessage theOscMessage) {
  // Check if the message is on address /bla
  if (theOscMessage.addrPattern().equals("/bla")) {
    if (theOscMessage.checkTypetag("f")) {
      // Get the first float value from the OSC message
      valueToSend = theOscMessage.get(0).floatValue();
      
      valueToSend = (valueToSend + 1) * 127;
      
      // Send the float value over serial to the Arduino as a string
      mySerial.write(str(valueToSend) + '\n');
    }
  }
}

void serialEvent(Serial mySerial) {
  // Read the string from the serial port until a '\n'
  String incomingString = mySerial.readStringUntil('\n');
  
  if (incomingString != null) {
    // Trim the string to remove any whitespace
    incomingString = incomingString.trim();
    
    // Print the debug string to the Processing console
    println("From Arduino: " + incomingString);
  }
}
