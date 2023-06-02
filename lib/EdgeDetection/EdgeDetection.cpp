// =============================================================================
// chickehouse-door-monitor | EdgeDetection
// =============================================================================

#include "EdgeDetection.h"

EdgeDetection *EdgeDetection::edgeList[10] = {nullptr};
uint8_t EdgeDetection::edgeCount = 0;

// Constructor for Edge Detection
EdgeDetection::EdgeDetection(uint8_t *edgeValue)
{
    _edgeValue = edgeValue;

    edgeList[edgeCount] = this;
    edgeCount++;
}

void EdgeDetection::updateEdge()
{
    Edge.old = Edge.act;
    Edge.act = *_edgeValue;
    Edge.edge = Edge.act ^ Edge.old;
    Edge.edge_pos = Edge.edge & Edge.act;
    Edge.edge_neg = Edge.edge & Edge.old;
}

void EdgeDetection::updateEdges()
{
    for (uint8_t i = 0; i < edgeCount; i++)
    {
        edgeList[i]->updateEdge();
    }
}

// Get the old state of the button
uint8_t EdgeDetection::getOldState()
{
    return Edge.old;
}

// Get the current state of the button
uint8_t EdgeDetection::getActState()
{
    return Edge.act;
}

// Get the button edge state
uint8_t EdgeDetection::getEdge()
{
    return Edge.edge;
}

// Get the positive edge of the button
uint8_t EdgeDetection::getEdgePos()
{
    return Edge.edge_pos;
}

// Get the negative edge of the button
uint8_t EdgeDetection::getEdgeNeg()
{
    return Edge.edge_neg;
}
