// =============================================================================
// chickehouse-door-monitor | Main
// =============================================================================

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "hardware.h"
#include "EdgeDetection.h"
#include "general.h"
#include "configurations.h"
#include "state.h"

void refreshData();
void WiFiEstablish();

//------------------------------------------------------------------------------

void setup()
{
  Serial.begin(115200);
  ESP.wdtEnable(WDTO_1S);

  WiFiEstablish();
}

void loop()
{
  for (;;)
  {
    refreshData();

    State::stateDriver();

    ESP.wdtFeed();
  }
}

//------------------------------------------------------------------------------

void refreshData()
{
  General::statusSwitchMidway = Hardware::getPort(Hardware::Port::switchMidway);
  General::statusSwitchEnd = Hardware::getPort(Hardware::Port::switchEnd);

  EdgeDetection::updateEdges();
}

void WiFiEstablish()
{
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi!");
}