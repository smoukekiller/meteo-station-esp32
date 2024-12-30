#include <WiFi.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include "dht_sensor_process.h"
#include "credentials.h"
#include "wifi_connection.h"
#include "globals.h"

void setup()
{
  wifi_reconnect_timer = millis();
  dht_sensor_timer = millis();
  
  Serial.begin(115200);
  wifi_init();
  dht.begin();
}

void loop()
{
  check_for_connection();
  read_dht_sensor();
  check_reconnection_timer();
}
