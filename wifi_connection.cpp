#include <WiFi.h>
#include "globals.h"
#include "credentials.h"
void wifi_init()
{
  WiFi.mode(WIFI_STA); //Optional
  WiFi.begin(NETWORK_SSID, NETWORK_PASSWORD);
}

bool check_for_connection()
{
  is_connected = (WiFi.status() == WL_CONNECTED);
  return is_connected;
}
