// =============================================================================
// chickehouse-door-monitor | Hardware
// =============================================================================

#include "hardware.h"
#include "general.h"

uint8_t General::statusSwitchMidway = 0;
uint8_t General::statusSwitchEnd = 0;

namespace Hardware
{
    EdgeDetection switchMidway(&General::statusSwitchMidway);
    EdgeDetection switchEnd(&General::statusSwitchEnd);
} // namespace Hardware