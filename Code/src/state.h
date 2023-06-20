// =============================================================================
// chickehouse-door-monitor | State
// =============================================================================

#include "hardware.h"

#ifndef CHICKENHOUSE_DOOR_MONITOR_STATE_
#define CHICKENHOUSE_DOOR_MONITOR_STATE_

#endif // CHICKENHOUSE_DOOR_MONITOR_STATE_

namespace State
{
    enum States : uint8_t
    {
        st_start,
        st_closed,
        st_opening,
        st_open,
        st_closing
    };

    /// @brief State driver function
    void stateDriver();

    /// @brief Handler for the Start state
    void stateStart();

    /// @brief Handler for the Closed state
    void stateClosed();

    /// @brief Handler for the Opening state
    void stateOpening();

    /// @brief Handler for the Open state
    void stateOpen();

    /// @brief Handler for the Closing state
    void stateClosing();
} // namespace State
