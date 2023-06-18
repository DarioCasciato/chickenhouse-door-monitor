// =============================================================================
// chickehouse-door-monitor | Configurations
// =============================================================================

#ifndef _CHICKENHOUSE_DOOR_MONITOR_CONFIGURATIONS_
#define _CHICKENHOUSE_DOOR_MONITOR_CONFIGURATIONS_

//Temporary, current solution should work without doorSignal
//#define PIN_DOORSIGNAL          99

#define PIN_SWITCH_MIDWAY       3
#define PIN_SWITCH_END          2

#define TIME_OPENING            5
#define TIME_CLOSING            5

// Wi-Fi connection
extern const char* ssid;
extern const char* password;
extern const char* event_name;
extern const char* api_key;

#endif // _CHICKENHOUSE_DOOR_MONITOR_CONFIGURATIONS_