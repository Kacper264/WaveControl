#pragma once
#include <PubSubClient.h>
#include "string_file.h"
#include "wifi_manager.h"
#include "constant.h"

extern PubSubClient client;

void initMQTT();
void connectMQTT();
void handleMQTT();