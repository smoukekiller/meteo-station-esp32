#include <WiFi.h>
#include "credentials.h"
#include "wifi_connection.h"
#include "globals.h"

void setup()
{
  wifi_reconnect_timer = millis();
  Serial.begin(115200);
  wifi_init();

}

void loop()
{
  check_for_connection();
  if (is_connected) Serial.println(WiFi.localIP());
  check_reconnection_timer();
}
