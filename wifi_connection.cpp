#include <WiFi.h>
#include "globals.h"
#include "credentials.h"
#include "config.h"
void wifi_init()
{
  WiFi.mode(WIFI_STA); //Optional
  WiFi.begin(NETWORK_SSID, NETWORK_PASSWORD);
  Serial.println(WiFi.localIP());
}

bool check_for_connection()
{
  is_connected = (WiFi.status() == WL_CONNECTED);
  return is_connected;
}

void check_reconnection_timer()
{
  if (is_connected) wifi_reconnect_timer = millis();
  else
  {
    if ((wifi_reconnect_timer + WIFI_RECONNECT_TIME) <= millis()) {
      Serial.println("reconnecting");
      wifi_init();
      wifi_reconnect_timer = millis();
    }
  }
}
