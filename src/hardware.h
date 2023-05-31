// =============================================================================
// chickehouse-door-monitor | Hardware
// =============================================================================

#ifndef _CHICKENHOUSE_DOOR_MONITOR_HARDWARE_
#define _CHICKENHOUSE_DOOR_MONITOR_HARDWARE_

#include "EdgeDetection.h"

namespace Hardware
{
    //Temporary, current solution should work without doorSignal
    //extern EdgeDetection doorSignal;

    extern EdgeDetection switchMidway;
    extern EdgeDetection switchEnd;
} // namespace Hardware


#endif // _CHICKENHOUSE_DOOR_MONITOR_HARDWARE_