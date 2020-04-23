#include "EmonLib.h"
EnergyMonitor emon1;
EnergyMonitor emon2;

double previousMillis;
int publish_interval = 10000; // 10000 milliseconds = 10 seconds

void setup() {
  Serial.begin(115200);

  emon1.current(1, 111.1);
  emon2.current(3, 111.1);
  
}

void loop() {

  if (millis() - previousMillis > publish_interval) {
    // Get data
    double valIrms1 = emon1.calcIrms(1480);
    double valIrms2 = emon2.calcIrms(1480);

    // Publish feeds
    Serial.print("S:");
    Serial.print(valIrms1);
    Serial.print(":");
    Serial.print(valIrms2);
    Serial.println();
    previousMillis = millis();
  }

}
