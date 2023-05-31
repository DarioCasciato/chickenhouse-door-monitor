// =============================================================================
// chickehouse-door-monitor | Main
// =============================================================================

#include <Arduino.h>
#include "hardware.h"
#include "EdgeDetection.h"
#include "general.h"
#include "configurations.h"
#include "state.h"

void refreshData();

//------------------------------------------------------------------------------

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  for (;;)
  {
    refreshData();

    State::stateDriver();
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