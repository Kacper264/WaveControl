#include "string_file.h"

const char* const SSID     = "Freebox-35CC49";
const char* const PASSWORD = "Mama1980";

const char* const ErrSSID            = "[WiFi] SSID not found";
const char* const ErrConnect         = "[WiFi] Failed - WiFi not connected!";
const char* const ErrDisconnected    = "[WiFi] WiFi is disconnected";
const char* const SucConnected       = "[WiFi] WiFi is connected!";
const char* const SucDisconnected    = "[WiFi] Disconnected from WiFi!";
const char* const IPAddressMsg       = "[WiFi] IP address: ";
const char* const DefaultWiFiStatusMsg = "[WiFi] WiFi Status: ";
const char* const ErrTryOut          = "[WiFi] Tried to connect too many times - giving up!";

const char* const mqtt_server   = "192.168.1.164";
const int        mqtt_port      = 1883;
const char* const mqtt_topic    = "xiao/test";

const char* const ConnectedToMQTT = "[MQTT] Connected to MQTT broker!";
const char* const FailedToMQTT    = "[MQTT] Failed to connect to MQTT broker, rc=";
const char* const MQTTClienID     = "XIAO_ESP32S3";
const char* const ConnectTry      = "[MQTT] Trying to connect to MQTT broker...";
const char* const NewTry          = " -> new try in 5s";
const char* const FirstMessage    = "XIAO ESP32-S3 started!";
