#include <Arduino.h>
#include "scheduler.h"

// Create two scheduler instances
Scheduler scheduler_1(500);   // executes every 500 ms
Scheduler scheduler_2(1000);  // executes every 1000 ms

void setup() {
  Serial.begin(115200);
  delay(100);

  Serial.println("Scheduler test started");
}

void loop() {
  scheduler_1.run([]() { Serial.println("Task 1 executed at " + String(millis()) + " ms"); });

  scheduler_2.run([]() { Serial.println("Task 2 executed at " + String(millis()) + " ms"); });
}
