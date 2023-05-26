// =============================================================================
// chickehouse-door-monitor | State
// =============================================================================

#include "state.h"

//------------------------------------------------------------------------------

namespace State
{
    States state = States::st_X;

    void stateDriver()
    {
        switch (State::state)
        {
        case State::st_X: stateX(); break;
        case State::st_XX: stateXX(); break;
        case State::st_XXX: stateXXX(); break;

        default:
        goto exception;
            break;
        }

        return;

        exception:
            for(;;) {}
    }

    void stateX()
    {

    }

    void stateXX()
    {

    }

    void stateXXX()
    {

    }
} // namespace State
