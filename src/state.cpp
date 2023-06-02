// =============================================================================
// chickehouse-door-monitor | State
// =============================================================================

#include "state.h"
#include "hardware.h"
#include "configurations.h"
#include "Timer.h"

Timer counter;

bool flag_midwayTriggered = false;

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
        if(Hardware::switchEnd.getActState())
        {
            state = States::st_closed;
            Serial.println("Starting Closed");
        }
        else
        {
            state = States::st_open;
            Serial.println("Starting Opened");
        }
    }

    void stateClosed()
    {
        if(Hardware::switchEnd.getEdgeNeg())
        {
            state = States::st_opening;
            Serial.println("Door opening");
            counter.start();
        }
    }

    void stateOpening()
    {
        if(Hardware::switchMidway.getEdgePos())
        {
            flag_midwayTriggered = true;
            Serial.println("midway Sensor triggered");
        }

        if(counter.elapsed(TIME_OPENING * 1000))
        {
            if(flag_midwayTriggered && !Hardware::switchEnd.getActState())
            {
                state = States::st_open;
                Serial.println("door opened");
            }
            else
            {
                state = States::st_closed;
                Serial.println("OPENING FAILED");
                //! SEND NOTIFICATION (NOT OPENED)
            }

            flag_midwayTriggered = false;
            counter.stop();
        }
    }

    void stateOpen()
    {
        if(Hardware::switchMidway.getEdgePos())
        {
            state = States::st_closing;
            Serial.println("Door closing");
            counter.start();
        }
    }

    void stateClosing()
    {
        if(counter.elapsed(TIME_CLOSING * 1000))
        {
            if(Hardware::switchEnd.getActState())
            {
                state = States::st_closed;
                Serial.println("door closed");
            }
            else
            {
                state = States::st_open;
                Serial.println("CLOSING FAILED");
                //! SEND NOTIFICATION (NOT CLOSED)
            }
        }
    }
} // namespace State

//------------------------------------------------------------------------------

