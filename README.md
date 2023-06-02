# Chickendoor Monitoring System

## Overview

The Chickendoor Monitoring System is a project aimed at monitoring the opening and closing of a chicken coop door. The system utilizes reed switches and magnets to detect the status of the door, providing information on whether it is open or closed. This README provides an overview of the system, its purpose, and its functionality.

## Purpose

The Chickendoor Monitoring System is designed to address the needs of individuals who own chicken coops and want to keep track of the door's status. The system offers a convenient way to monitor the door remotely, ensuring the safety and security of the chickens inside.

## Functionality

The system utilizes a reed switch and a magnet to detect whether the door is open or closed. When the door is closed, the magnet is positioned near the reed switch, causing it to close the circuit. This state is recognized as "Closed" by the system. Conversely, when the door is opened, the magnet moves away from the reed switch, breaking the circuit and indicating the "Open" state.

The Chickendoor Monitoring System employs a state machine to track and display the door's status. The state machine consists of two states:

1. **Closed State**: In this state, the system recognizes that the door is closed. It displays this status, indicating that the chickens are safely inside the coop.

2. **Open State**: When the system detects that the door is open, it transitions to this state. This status indicates that the door is currently open, allowing the chickens to roam freely outside the coop.

The state machine continuously monitors the reed switch and updates the door's status accordingly. Users can access this information through the system's interface, which provides real-time updates on the door's state.
