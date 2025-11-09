#include "wifi_manager.h"
#include <Arduino.h>

WiFiClient espClient;

void connectToWiFi() {
  Serial.println();
  Serial.println(SSID);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
}

void disconnectFromWiFi() {
  if (WiFi.disconnect(true, false)) {
    Serial.println(SucDisconnected);
  }
}

String isWiFiConnected() {
  while (true) {
    switch (WiFi.status()) {
      case WL_NO_SSID_AVAIL: 
        return ErrSSID; 
        break;
      case WL_CONNECT_FAILED:  
        return ErrConnect;
        break;
      case WL_DISCONNECTED:
        return ErrDisconnected;
        break;
      case WL_CONNECTED:
        Serial.print(IPAddressMsg);
        Serial.println(WiFi.localIP());
        return SucConnected;
        break;
      default:
        Serial.println(WiFi.status());
        return DefaultWiFiStatusMsg;
        break;
    }

    delay(tryDelay);

    if (numberOfTries <= zero) {
      WiFi.disconnect();
      return ErrTryOut;
    } else {
      numberOfTries--;
    }
  }
}