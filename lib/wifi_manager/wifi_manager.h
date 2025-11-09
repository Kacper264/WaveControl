#pragma once
#include <WiFi.h>
#include "string_file.h"
#include "constant.h"

extern WiFiClient espClient;

// Fonctions principales
void connectToWiFi();
void disconnectFromWiFi();
String isWiFiConnected();