// =============================================================================
// chickehouse-door-monitor | Hardware
// =============================================================================

#include "hardware.h"
#include "general.h"

uint8_t General::statusSwitchMidway = 0;
uint8_t General::statusSwitchEnd = 0;

namespace Hardware
{
    //Temporary, current solution should work without doorSignal
    //EdgeDetection doorSignal(&General::statusDoorSignal);

    EdgeDetection switchMidway(&General::statusSwitchMidway);
    EdgeDetection switchEnd(&General::statusSwitchEnd);
} // namespace Hardware