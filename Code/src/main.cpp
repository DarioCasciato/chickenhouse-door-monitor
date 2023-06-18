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

//------------------------------------------------------------------------------

void setup()
{
  Serial.begin(115200);
  ESP.wdtEnable(WDTO_1S);

  // Wifi Connection
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");
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
  //Temporary, current solution should work without doorSignal
  //General::statusDoorSignal = digitalRead(PIN_DOORSIGNAL);

  General::statusSwitchMidway = digitalRead(PIN_SWITCH_MIDWAY);
  General::statusSwitchEnd = digitalRead(PIN_SWITCH_END);

  EdgeDetection::updateEdges();
}