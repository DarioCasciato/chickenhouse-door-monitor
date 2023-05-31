// =============================================================================
// chickehouse-door-monitor | State
// =============================================================================

#include "state.h"
#include "Timer.h"

Timer counter;

//------------------------------------------------------------------------------

namespace State
{
    States state = States::st_start;

    void stateDriver()
    {
        switch (State::state)
        {
        case State::st_start: stateStart(); break;
        case State::st_closed: stateClosed(); break;
        case State::st_opening: stateOpening(); break;
        case State::st_open: stateOpen(); break;
        case State::st_closing: stateClosing(); break;

        default:
        goto exception;
            break;
        }

        return;

        exception:
            for(;;) {}
    }

    void stateStart()
    {

    }

    void stateClosed()
    {

    }

    void stateOpening()
    {

    }

    void stateOpen()
    {

    }

    void stateClosing()
    {

    }
} // namespace State

//------------------------------------------------------------------------------

