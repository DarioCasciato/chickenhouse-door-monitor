// =============================================================================
// chickehouse-door-monitor | Configurations
// =============================================================================

#ifndef _CHICKENHOUSE_DOOR_MONITOR_CONFIGURATIONS_
#define _CHICKENHOUSE_DOOR_MONITOR_CONFIGURATIONS_

#define PIN_SWITCH_MIDWAY       D5
#define PIN_SWITCH_END          D6

#define TIME_OPENING            5
#define TIME_CLOSING            5

// Wi-Fi connection
extern const char* ssid;
extern const char* password;
extern const char* event_name;
extern const char* request_notClosed;
extern const char* request_notOpened;

#endif // _CHICKENHOUSE_DOOR_MONITOR_CONFIGURATIONS_