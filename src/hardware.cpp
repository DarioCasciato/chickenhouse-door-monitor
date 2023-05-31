// =============================================================================
// chickehouse-door-monitor | Hardware
// =============================================================================

#include "hardware.h"
#include "general.h"

namespace Hardware
{
    //Temporary, current solution should work without doorSignal
    //EdgeDetection doorSignal(&General::statusDoorSignal);

    EdgeDetection switchMidway(&General::statusSwitchMidway);
    EdgeDetection switchEnd(&General::statusSwitchEnd);
} // namespace Hardware