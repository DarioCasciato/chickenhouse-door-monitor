// =============================================================================
// chickehouse-door-monitor | Hardware
// =============================================================================

#include "hardware.h"
#include "general.h"

namespace Hardware
{
    EdgeDetection doorSignal(&General::statusDoorSignal);
    EdgeDetection switchMidway(&General::statusSwitchMidway);
    EdgeDetection switchEnd(&General::statusSwitchEnd);
} // namespace Hardware