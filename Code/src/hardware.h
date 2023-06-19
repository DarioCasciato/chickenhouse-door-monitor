// =============================================================================
// chickehouse-door-monitor | Hardware
// =============================================================================

#ifndef _CHICKENHOUSE_DOOR_MONITOR_HARDWARE_
#define _CHICKENHOUSE_DOOR_MONITOR_HARDWARE_

#include "EdgeDetection.h"
#include "configurations.h"

namespace Hardware
{
    enum class Port : uint8_t
    {
        switchMidway = PIN_SWITCH_MIDWAY,
        switchEnd = PIN_SWITCH_END
    };

    extern EdgeDetection switchMidway;
    extern EdgeDetection switchEnd;

    bool getPort(Port port);
} // namespace Hardware


#endif // _CHICKENHOUSE_DOOR_MONITOR_HARDWARE_