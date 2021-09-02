
#include "M5Atom.h"

#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t kIrLed = 12;  // (Atom Lite IR LED is on pin 12.)  ESP8266 GPIO pin to use. Recommended: 4 (D2).

IRsend irsend(kIrLed);  // Set the GPIO to be used to sending the message.

void setup() {
  M5.begin(true, false, true);
  delay(50);
  irsend.begin();
  Serial.begin(115200, SERIAL_8N1);
}

void loop() {
  // White (it can be changed even when the light is off)
  Serial.println("White");
  irsend.sendNEC(0xF7E01FUL); // 0x = Hex, F7 E0 1F, UL = Unsigned long
  delay(50);
  // On
  Serial.println("On");
  M5.dis.drawpix(0, 0xf0f0f0);
  irsend.sendNEC(0xF7C03FUL);
  delay(500);
  // Blue
  Serial.println("Blue");
  M5.dis.drawpix(0, 0x0000f0);
  irsend.sendNEC(0xF7609FUL);
  delay(500);
  // Green
  Serial.println("Green");
  M5.dis.drawpix(0, 0xf00000);
  irsend.sendNEC(0xF7A05FUL);
  delay(500);
  // Red
  Serial.println("Red");
  M5.dis.drawpix(0, 0x00f000);
  irsend.sendNEC(0xF720DFUL);
  delay(500);
  // Off
  Serial.println("Off");
  M5.dis.drawpix(0, 0x0);
  irsend.sendNEC(0xF740BFUL);
  delay(1000);
}
