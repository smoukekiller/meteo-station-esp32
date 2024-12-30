#include "globals.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include "config.h"
#include <HTTPClient.h>
bool is_connected = false;

uint64_t wifi_reconnect_timer;
uint64_t dht_sensor_timer;
uint64_t http_request_timer;

DHT dht(DHTPIN, DHTTYPE);
float humidity;
float temperature;
