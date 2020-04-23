//make sure the file config_example.h is renamed to config.h
#include "config.h"

// set up the group
AdafruitIO_Group *group = io.group("energymonitor");

// set up command parsing variables
String inputString = "";
String cmdString = "";
String ctOneString = "";
String ctTwoString = "";
boolean stringComplete = false;
boolean inputState = false;

void setup() {

  // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while (! Serial);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // wait for a connection
  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
  Serial.println("Waiting for commands...");
  // send notification upon startup, if there are a lot of these there is a problem
  group->set("connect", 1);
  group->save();

}

void loop() {

  io.run();

  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
  parseCommand();
}

void parseCommand() {
  /*
   * Protocol to send two current transformer values:
   * S:<value1>:<value2><ENTER>
   * Example: S:5.3:12.0<ENTER> send 5.3 amps for ct1 and 12.0 amps for ct2
   */
 
  // print the string when a newline arrives:
  if (stringComplete) {
    inputString.trim();
    Serial.println(inputString);
    if (inputString.startsWith("S")) {
      int separatorIndex = inputString.indexOf(':');
      int separatorIndex2 = inputString.indexOf(':', separatorIndex + 1);
      ctOneString = inputString.substring(separatorIndex + 1, separatorIndex2);
      ctTwoString = inputString.substring(separatorIndex2 + 1);
      group->set("ct1", ctOneString);
      group->set("ct2", ctTwoString);
      group->save();

    }
    // clear the strings
    inputString = "";
    cmdString = "";
    ctOneString = "";
    ctTwoString = "";
    stringComplete = false;
  }
}
