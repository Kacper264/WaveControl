#include <Arduino.h>
#include "wifi_manager.h"
#include "mqtt_manager.h"
#include "constant.h"


int btnGPIO = 0;
int btnState = HIGH;


void setup() {
  Serial.begin(baudRate);
  pinMode(btnGPIO, INPUT_PULLUP);

  connectToWiFi();

  wifiStatus = isWiFiConnected();

  initMQTT();
}

void loop() {
  handleMQTT();
  // Lecture du bouton
  btnState = digitalRead(btnGPIO);
  if (btnState == LOW) {
    Serial.println("[Bouton] Appuyé -> envoi MQTT");
    client.publish(mqtt_topic, "Bouton appuyé !");
    delay(500); // anti-rebond
  }
}
