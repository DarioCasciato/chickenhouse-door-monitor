// =============================================================================
// chickehouse-door-monitor | EdgeDetection
// =============================================================================

#include <stdint.h>

#ifndef ARDUINO_OBJECTS_EDGE_DETECTION_
#define ARDUINO_OBJECTS_EDGE_DETECTION_

class EdgeDetection
{
private:
    uint8_t *_edgeValue;
    static EdgeDetection *edgeList[10];
    static uint8_t edgeCount;

    struct edge_t
    {
        uint8_t old;
        uint8_t act;
        uint8_t edge;
        uint8_t edge_pos;
        uint8_t edge_neg;
    } Edge;

public:
    /// @brief EdgeDetection constructor
    ///
    /// @param edgeValue Pointer to the variable representing the edge value
    EdgeDetection(uint8_t *edgeValue);

    /// @brief Update the edge detection for a specific instance
    void updateEdge();

    /// @brief Update the edge detection for all instances of EdgeDetection
    static void updateEdges();

    /// @brief Get the previous state value
    ///
    /// @return The previous state value
    uint8_t getOldState();

    /// @brief Get the current state value
    ///
    /// @return The current state value
    uint8_t getActState();

    /// @brief Get the edge value
    ///
    /// @return The edge value
    uint8_t getEdge();

    /// @brief Get the positive edge value
    ///
    /// @return The positive edge value
    uint8_t getEdgePos();

    /// @brief Get the negative edge value
    ///
    /// @return The negative edge value
    uint8_t getEdgeNeg();
};

#endif // ARDUINO_OBJECTS_EDGE_DETECTION_