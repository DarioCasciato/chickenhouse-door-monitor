// =============================================================================
// chickehouse-door-monitor | General
// =============================================================================

#ifndef _CHICKENHOUSE_DOOR_MONITOR_GENERAL_
#define _CHICKENHOUSE_DOOR_MONITOR_GENERAL_

#include <stdint.h>

namespace General
{
    // Pin value buffer
    extern uint8_t statusSwitchMidway;
    extern uint8_t statusSwitchEnd;

    void WiFiEstablish();
} // namespace General


#endif // _CHICKENHOUSE_DOOR_MONITOR_GENERAL_