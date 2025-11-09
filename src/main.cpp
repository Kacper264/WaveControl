#include <Arduino.h>
#include "wifi_manager.h"

int btnGPIO = 0;
int btnState = false;

void setup() {
  Serial.begin(115200);
  delay(10);
  
  pinMode(btnGPIO, INPUT);
  connectToWiFi();
  // Connexion Wi-Fi via la librairie
  
}

void loop() {
  btnState = digitalRead(btnGPIO);
  if (btnState == LOW) {
    disconnectFromWiFi();
    delay(1000);
  }
}
