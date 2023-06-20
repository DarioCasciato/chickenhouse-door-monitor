// =============================================================================
// chickehouse-door-monitor | State
// =============================================================================

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "state.h"
#include "hardware.h"
#include "general.h"
#include "configurations.h"
#include "Timer.h"

Timer counter;

void sendNotification(const char* Event);
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

        default:    // catch invalid state (implement safety backup)
        goto exception;
            break;
        }

        return;

        exception:
            for(;;) {}
    }

    // decide in which state the door starts
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
        // Magnet distances from end switch
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

        // opening time elapsed
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
                sendNotification(request_notOpened);
            }

            flag_midwayTriggered = false;
            counter.stop();
        }
    }

    void stateOpen()
    {
        // Magnet triggers midway switch
        if(Hardware::switchMidway.getEdgePos())
        {
            state = States::st_closing;
            Serial.println("Door closing");
            counter.start();
        }
    }

    void stateClosing()
    {
        // closing time elapsed
        if(counter.elapsed(TIME_CLOSING * 1000))
        {
            // detect if end switch is active
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
                sendNotification(request_notClosed);
            }
        }
    }
} // namespace State

//------------------------------------------------------------------------------

// call webhook for IFTTT. push notification on phone is sent through IFTTT app.
void sendNotification(const char* Event)
{
    HTTPClient http;
    WiFiClient client;

    General::WiFiEstablish();

    // Send the HTTP POST request
    http.begin(client, Event);
    int httpResponseCode = http.POST("");

    // Check the response code
    if (httpResponseCode == HTTP_CODE_OK)
    {
        Serial.print("Notification sent: ");
        Serial.println(Event);
    } else
    {
        Serial.print("Error sending notification. Response code: ");
        Serial.println(httpResponseCode);
    }

    // Close the connection
    http.end();
}