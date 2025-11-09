#include "wifi_manager.h"
#include <Arduino.h>

void connectToWiFi() {
  Serial.println();
  Serial.print("[WiFi] Connecting to ");
  Serial.println(SSID);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);

  int tryDelay = 500;
  int numberOfTries = 20;

  while (true) {
    switch (WiFi.status()) {
      case WL_NO_SSID_AVAIL: Serial.println("[WiFi] SSID not found"); break;
      case WL_CONNECT_FAILED: Serial.println("[WiFi] Failed - WiFi not connected!"); return;
      case WL_CONNECTION_LOST: Serial.println("[WiFi] Connection was lost"); break;
      case WL_SCAN_COMPLETED:  Serial.println("[WiFi] Scan is completed"); break;
      case WL_DISCONNECTED:    Serial.println("[WiFi] WiFi is disconnected"); break;
      case WL_CONNECTED:
        Serial.println("[WiFi] WiFi is connected!");
        Serial.print("[WiFi] IP address: ");
        Serial.println(WiFi.localIP());
        return;
      default:
        Serial.print("[WiFi] WiFi Status: ");
        Serial.println(WiFi.status());
        break;
    }

    delay(tryDelay);

    if (numberOfTries <= 0) {
      Serial.println("[WiFi] Failed to connect to WiFi!");
      WiFi.disconnect();
      return;
    } else {
      numberOfTries--;
    }
  }
}

void disconnectFromWiFi() {
  Serial.println("[WiFi] Disconnecting from WiFi!");
  if (WiFi.disconnect(true, false)) {
    Serial.println("[WiFi] Disconnected from WiFi!");
  }
}
