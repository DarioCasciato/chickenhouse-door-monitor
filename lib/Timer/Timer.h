// =============================================================================
// chickehouse-door-monitor | Timer
// =============================================================================

#include <Arduino.h>

#ifndef ARDUINO_OBJECTS_TIMER_
#define ARDUINO_OBJECTS_TIMER_

class Timer
{
private:
    uint32_t _startTicks = 0;
    uint32_t _delta = 0;

public:
    /// @brief Start the timer
    void start();

    /// @brief Stop the timer
    void stop();

    /// @brief Check if the specified time has elapsed
    ///
    /// @param ms The time threshold in milliseconds
    /// @return True if the specified time has elapsed, false otherwise
    bool elapsed(uint32_t ms);

    /// @brief Get the remaining time until the specified threshold
    ///
    /// @param ms The time threshold in milliseconds
    /// @return The remaining time in milliseconds
    uint32_t remaining(uint32_t ms);

    /// @brief Get the elapsed time since the timer started
    ///
    /// @return The elapsed time in milliseconds
    uint32_t elapsedStart();
};

#endif // ARDUINO_OBJECTS_TIMER_