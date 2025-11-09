#include "mqtt_manager.h"
#include <Arduino.h>

PubSubClient client(espClient); 

void initMQTT() {
  client.setServer(mqtt_server, mqtt_port);
  connectMQTT();
}

void connectMQTT() {

  while (!client.connected()) {
    Serial.print(ConnectTry);
    if (client.connect(MQTTClienID)) {
      Serial.println(ConnectedToMQTT);

      client.publish(mqtt_topic, FirstMessage);
    } else {
      Serial.print(FailedToMQTT);
      Serial.print(client.state());
      Serial.println(NewTry);
      delay(delay5s);
    }
  }
}

void handleMQTT() {
  if (!client.connected()) {
    connectMQTT();
  }
  client.loop();
}