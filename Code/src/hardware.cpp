// =============================================================================
// chickehouse-door-monitor | Hardware
// =============================================================================

#include <Arduino.h>
#include "hardware.h"
#include "general.h"

uint8_t General::statusSwitchMidway = 0;
uint8_t General::statusSwitchEnd = 0;

namespace Hardware
{
    EdgeDetection switchMidway(&General::statusSwitchMidway);
    EdgeDetection switchEnd(&General::statusSwitchEnd);

    bool getPort(Port port)
    {
        return digitalRead((uint8_t)port);
    }
} // namespace Hardware