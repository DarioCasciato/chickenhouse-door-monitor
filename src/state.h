// =============================================================================
// chickehouse-door-monitor | State
// =============================================================================

#include "hardware.h"

#ifndef CHICKENHOUSE_DOOR_MONITOR_STATE_
#define CHICKENHOUSE_DOOR_MONITOR_STATE_

#endif // CHICKENHOUSE_DOOR_MONITOR_STATE_

namespace State
{
    enum States
    {
        st_X,
        st_XX,
        st_XXX
    };

    /// @brief State driver function
    void stateDriver();

    /// @brief Handler for the X state
    void stateX();

    /// @brief Handler for the XX state
    void stateXX();

    /// @brief Handler for the XXX state
    void stateXXX();
} // namespace State
