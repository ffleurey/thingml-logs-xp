#include <stdint.h>
#include <Arduino.h>
/*****************************************************************************
 * Headers for type : ConsoleLogger
 *****************************************************************************/

// Definition of the instance struct:
struct ConsoleLogger_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_log;
// Variables for the current instance state
int Logger_State;
// Variables for the properties of the instance
bool Logger_HAS_SIGNED_BYTE_var;
bool Logger_ACTIVATE_ON_STARTUP_var;
bool ConsoleLogger_QUIET_var;

};
// Declaration of prototypes outgoing messages :
void Logger_OnEntry(int state, struct ConsoleLogger_Instance *_instance);
void ConsoleLogger_handle_log_log_on(struct ConsoleLogger_Instance *_instance);
void ConsoleLogger_handle_log_log(struct ConsoleLogger_Instance *_instance, uint8_t* payload, uint8_t size);
void ConsoleLogger_handle_log_log_off(struct ConsoleLogger_Instance *_instance);
// Declaration of callbacks for incoming messages:

// Definition of the states:
#define LOGGER_NULL_ON_STATE 0
#define LOGGER_STATE 1
#define LOGGER_NULL_STARTUP_STATE 2
#define LOGGER_NULL_OFF_STATE 3


/*****************************************************************************
 * Headers for type : HeadlessDisplay
 *****************************************************************************/

// Definition of the instance struct:
struct HeadlessDisplay_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_display;
// Variables for the current instance state
int HeadlessDisplay_State;
// Variables for the properties of the instance

};
// Declaration of prototypes outgoing messages :
void HeadlessDisplay_OnEntry(int state, struct HeadlessDisplay_Instance *_instance);
void HeadlessDisplay_handle_display_drawInteger(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale);
void HeadlessDisplay_handle_display_destroy(struct HeadlessDisplay_Instance *_instance);
void HeadlessDisplay_handle_display_setColor(struct HeadlessDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void HeadlessDisplay_handle_display_setBGColor(struct HeadlessDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void HeadlessDisplay_handle_display_drawThingML(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y);
void HeadlessDisplay_handle_display_update(struct HeadlessDisplay_Instance *_instance);
void HeadlessDisplay_handle_display_clear(struct HeadlessDisplay_Instance *_instance);
void HeadlessDisplay_handle_display_fillRect(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void HeadlessDisplay_handle_display_drawRect(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void HeadlessDisplay_handle_display_create(struct HeadlessDisplay_Instance *_instance, uint8_t xsize, uint8_t ysize);
// Declaration of callbacks for incoming messages:
void register_HeadlessDisplay_send_display_displayReady_listener(void (*_listener)(struct HeadlessDisplay_Instance *));
void register_external_HeadlessDisplay_send_display_displayReady_listener(void (*_listener)(struct HeadlessDisplay_Instance *));

// Definition of the states:
#define HEADLESSDISPLAY_NULL_MOCK_STATE 0
#define HEADLESSDISPLAY_NULL_INIT_STATE 1
#define HEADLESSDISPLAY_STATE 2


/*****************************************************************************
 * Headers for type : BasicIAController
 *****************************************************************************/

// Definition of the instance struct:
struct BasicIAController_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_controls;
uint16_t id_game;
// Variables for the current instance state
int BasicIAController_SC_State;
// Variables for the properties of the instance
int16_t BasicIAController_ctrlx_var;

};
// Declaration of prototypes outgoing messages :
void BasicIAController_SC_OnEntry(int state, struct BasicIAController_Instance *_instance);
void BasicIAController_handle_game_updateIA(struct BasicIAController_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady);
// Declaration of callbacks for incoming messages:
void register_BasicIAController_send_controls_position_listener(void (*_listener)(struct BasicIAController_Instance *, int16_t, int16_t));
void register_external_BasicIAController_send_controls_position_listener(void (*_listener)(struct BasicIAController_Instance *, int16_t, int16_t));

// Definition of the states:
#define BASICIACONTROLLER_SC_FOLLOWING_STATE 0
#define BASICIACONTROLLER_SC_STATE 1


/* Adds and instance to the runtime and returns its id */
uint16_t add_instance(void * instance_struct);
/* Returns the instance with id */
void * instance_by_id(uint16_t id);

/* Returns the number of byte currently in the fifo */
int fifo_byte_length();
/* Returns the number of bytes currently available in the fifo */
int fifo_byte_available();
/* Returns true if the fifo is empty */
int fifo_empty();
/* Return true if the fifo is full */
int fifo_full();
/* Enqueue 1 byte in the fifo if there is space
   returns 1 for sucess and 0 if the fifo was full */
int fifo_enqueue(byte b);
/* Enqueue 1 byte in the fifo without checking for available space
   The caller should have checked that there is enough space */
int _fifo_enqueue(byte b);
/* Dequeue 1 byte in the fifo.
   The caller should check that the fifo is not empty */
byte fifo_dequeue();
/*****************************************************************************
 * Headers for type : TimerArduino
 *****************************************************************************/


// BEGIN: Code from the c_header annotation TimerArduino
#define NB_SOFT_TIMERS 32

// END: Code from the c_header annotation TimerArduino

// Definition of the instance struct:
struct TimerArduino_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_timer;
// Variables for the current instance state
int TimerArduino_SoftTimer_State;
// Variables for the properties of the instance
uint16_t TimerArduino_NB_SOFT_TIMERS_var;

};
// Declaration of prototypes outgoing messages :
void TimerArduino_SoftTimer_OnEntry(int state, struct TimerArduino_Instance *_instance);
void TimerArduino_handle_timer_timer_start(struct TimerArduino_Instance *_instance, uint8_t id, uint16_t time);
void TimerArduino_handle_timer_timer_cancel(struct TimerArduino_Instance *_instance, uint8_t id);
// Declaration of callbacks for incoming messages:
void register_TimerArduino_send_timer_timer_timeout_listener(void (*_listener)(struct TimerArduino_Instance *, uint8_t));
void register_external_TimerArduino_send_timer_timer_timeout_listener(void (*_listener)(struct TimerArduino_Instance *, uint8_t));

// Definition of the states:
#define TIMERARDUINO_SOFTTIMER_STATE 0
#define TIMERARDUINO_SOFTTIMER_DEFAULT_STATE 1


/*****************************************************************************
 * Headers for type : BreakoutGameArduino
 *****************************************************************************/

// Definition of the instance struct:
struct BreakoutGameArduino_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_log;
uint16_t id_clock;
uint16_t id_display;
uint16_t id_controller;
uint16_t id_ia;
uint16_t id_game;
uint16_t id_req_game;
uint16_t id_pro_game;
// Variables for the current instance state
int BreakoutGame_SC_State;
// Variables for the properties of the instance
int16_t BreakoutGame_prevBX_var;
int16_t BreakoutGame_SCALE_var;
uint8_t * BreakoutGame_bgcolor_var;
uint16_t BreakoutGame_bgcolor_var_size;
uint32_t BreakoutGame_startTime_var;
int16_t BreakoutGame_pady_var;
int16_t BreakoutGame_padlen_var;
uint8_t BreakoutGame_SC_LAUNCH_countdown_var;
int16_t BreakoutGame_dy_var;
uint16_t BreakoutGame_period_var;
int16_t BreakoutGame_score_var;
int16_t BreakoutGame_BOTTOM_var;
int16_t BreakoutGame_br_var;
int16_t BreakoutGame_RIGHT_var;
int16_t BreakoutGame_TOP_var;
int16_t BreakoutGame_padx_var;
int16_t BreakoutGame_LEFT_var;
uint8_t BreakoutGame_level_var;
int16_t BreakoutGame_by_var;
int16_t BreakoutGame_prevPX_var;
int16_t BreakoutGame_prevBY_var;
uint8_t BreakoutGame_lives_var;
uint32_t BreakoutGame_stopTime_var;
uint8_t BreakoutGame_XDISPSIZE_var;
bool BreakoutGame_QUIET_var;
int16_t BreakoutGame_dx_var;
uint32_t BreakoutGameArduino_RAM_SIZE_var;
uint8_t * BreakoutGame_fgcolor_var;
uint16_t BreakoutGame_fgcolor_var_size;
int16_t BreakoutGame_YMAX_var;
int16_t BreakoutGame_XMAX_var;
uint8_t BreakoutGame_BRICK_ROWS_var;
uint8_t * BreakoutGame_bricks_var;
uint16_t BreakoutGame_bricks_var_size;
uint8_t BreakoutGame_YDISPSIZE_var;
int16_t BreakoutGame_bx_var;
uint8_t BreakoutGame_counter_var;
uint32_t BreakoutGame_lastTimestamp_var;
int16_t BreakoutGame_prevPY_var;
uint8_t BreakoutGame_BRICK_HEIGHT_var;
uint8_t WithBinaryLog_DEBUG_BIN_ID_var;

};
// Declaration of prototypes outgoing messages :
void BreakoutGame_SC_OnEntry(int state, struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_handle_pro_game_lostBall(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_handle_pro_game_nextLevel(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_handle_controller_position(struct BreakoutGameArduino_Instance *_instance, int16_t x, int16_t y);
void BreakoutGameArduino_handle_display_displayReady(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_handle_game_lostBall(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_handle_game_nextLevel(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_handle_clock_timer_timeout(struct BreakoutGameArduino_Instance *_instance, uint8_t id);
// Declaration of callbacks for incoming messages:
void register_BreakoutGameArduino_send_log_log_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t*, uint8_t));
void register_external_BreakoutGameArduino_send_log_log_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t*, uint8_t));
void register_BreakoutGameArduino_send_clock_timer_start_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint16_t));
void register_external_BreakoutGameArduino_send_clock_timer_start_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint16_t));
void register_BreakoutGameArduino_send_clock_timer_cancel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t));
void register_external_BreakoutGameArduino_send_clock_timer_cancel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t));
void register_BreakoutGameArduino_send_display_create_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t));
void register_external_BreakoutGameArduino_send_display_create_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t));
void register_BreakoutGameArduino_send_display_fillRect_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_external_BreakoutGameArduino_send_display_fillRect_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_BreakoutGameArduino_send_display_drawRect_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_external_BreakoutGameArduino_send_display_drawRect_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_BreakoutGameArduino_send_display_clear_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_external_BreakoutGameArduino_send_display_clear_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_BreakoutGameArduino_send_display_setColor_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t));
void register_external_BreakoutGameArduino_send_display_setColor_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t));
void register_BreakoutGameArduino_send_display_setBGColor_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t));
void register_external_BreakoutGameArduino_send_display_setBGColor_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t));
void register_BreakoutGameArduino_send_display_drawInteger_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t));
void register_external_BreakoutGameArduino_send_display_drawInteger_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t));
void register_BreakoutGameArduino_send_display_update_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_external_BreakoutGameArduino_send_display_update_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_BreakoutGameArduino_send_display_drawThingML_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t));
void register_external_BreakoutGameArduino_send_display_drawThingML_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t));
void register_BreakoutGameArduino_send_ia_updateIA_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, int16_t, int16_t, int16_t, int16_t));
void register_external_BreakoutGameArduino_send_ia_updateIA_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, int16_t, int16_t, int16_t, int16_t));
void register_BreakoutGameArduino_send_game_lostBall_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_external_BreakoutGameArduino_send_game_lostBall_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_BreakoutGameArduino_send_game_nextLevel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_external_BreakoutGameArduino_send_game_nextLevel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_BreakoutGameArduino_send_req_game_lostBall_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_external_BreakoutGameArduino_send_req_game_lostBall_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_BreakoutGameArduino_send_req_game_nextLevel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));
void register_external_BreakoutGameArduino_send_req_game_nextLevel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *));

// Definition of the states:
#define BREAKOUTGAME_SC_PLAY_STATE 0
#define BREAKOUTGAME_SC_STATE 1
#define BREAKOUTGAME_SC_LOSTBALL_STATE 2
#define BREAKOUTGAME_SC_GAMEOVER_STATE 3
#define BREAKOUTGAME_SC_LAUNCH_STATE 4
#define BREAKOUTGAME_SC_NEXTLEVEL_STATE 5
#define BREAKOUTGAME_SC_INIT_STATE 6


// Definition of Enumeration  LogType
#define LOGTYPE_FUNCTION_CALLED 0
#define LOGTYPE_PROPERTY_CHANGED 1
#define LOGTYPE_MESSAGE_LOST 2
#define LOGTYPE_MESSAGE_SENT 3
#define LOGTYPE_MESSAGE_HANDLED 4

// Definition of Enumeration  DigitalState
#define DIGITALSTATE_LOW 0
#define DIGITALSTATE_HIGH 1


/*****************************************************************************
 * Implementation for type : BreakoutGameArduino
 *****************************************************************************/


// BEGIN: Code from the c_global annotation BreakoutGameArduino
extern "C" char* sbrk(int incr);
// END: Code from the c_global annotation BreakoutGameArduino

// Declaration of prototypes:
//Prototypes: State Machine
void BreakoutGame_SC_OnExit(int state, struct BreakoutGameArduino_Instance *_instance);
//Prototypes: Message Sending
void BreakoutGameArduino_send_log_log(struct BreakoutGameArduino_Instance *_instance, uint8_t* payload, uint8_t size);
void BreakoutGameArduino_send_clock_timer_start(struct BreakoutGameArduino_Instance *_instance, uint8_t id, uint16_t time);
void BreakoutGameArduino_send_clock_timer_cancel(struct BreakoutGameArduino_Instance *_instance, uint8_t id);
void BreakoutGameArduino_send_display_create(struct BreakoutGameArduino_Instance *_instance, uint8_t xsize, uint8_t ysize);
void BreakoutGameArduino_send_display_fillRect(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void BreakoutGameArduino_send_display_drawRect(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void BreakoutGameArduino_send_display_clear(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_send_display_setColor(struct BreakoutGameArduino_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void BreakoutGameArduino_send_display_setBGColor(struct BreakoutGameArduino_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void BreakoutGameArduino_send_display_drawInteger(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale);
void BreakoutGameArduino_send_display_update(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_send_display_drawThingML(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y);
void BreakoutGameArduino_send_ia_updateIA(struct BreakoutGameArduino_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady);
void BreakoutGameArduino_send_game_lostBall(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_send_game_nextLevel(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_send_req_game_lostBall(struct BreakoutGameArduino_Instance *_instance);
void BreakoutGameArduino_send_req_game_nextLevel(struct BreakoutGameArduino_Instance *_instance);
//Prototypes: Function
void f_BreakoutGameArduino_log(struct BreakoutGameArduino_Instance *_instance, bool logMem);
void f_BreakoutGameArduino_initColors(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_resetBall(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_eraseBall(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_drawBall(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_erasePad(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_drawPad(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_drawCountDown(struct BreakoutGameArduino_Instance *_instance, int16_t c);
void f_BreakoutGameArduino_drawWalls(struct BreakoutGameArduino_Instance *_instance);
bool f_BreakoutGameArduino_bitIsSet(struct BreakoutGameArduino_Instance *_instance, uint8_t variable, uint8_t bit);
void f_BreakoutGameArduino_createBricks(struct BreakoutGameArduino_Instance *_instance);
uint8_t f_BreakoutGameArduino_bricksLeft(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_drawBrick(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y);
void f_BreakoutGameArduino_removeBrick(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y);
bool f_BreakoutGameArduino_collideBrick(struct BreakoutGameArduino_Instance *_instance, int16_t xpos, int16_t ypos);
void f_BreakoutGameArduino_drawLevel(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_incrementScore(struct BreakoutGameArduino_Instance *_instance, int8_t diff);
void f_BreakoutGameArduino_drawScore(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_drawLives(struct BreakoutGameArduino_Instance *_instance);
void f_BreakoutGameArduino_quit(struct BreakoutGameArduino_Instance *_instance);
uint32_t f_BreakoutGameArduino_timestamp(struct BreakoutGameArduino_Instance *_instance);
uint32_t f_BreakoutGameArduino_usedMemory(struct BreakoutGameArduino_Instance *_instance);
uint8_t f_BreakoutGameArduino_unsetBit(struct BreakoutGameArduino_Instance *_instance, uint8_t variable, uint8_t bit);
// Declaration of functions:
// Definition of function log
void f_BreakoutGameArduino_log(struct BreakoutGameArduino_Instance *_instance, bool logMem) {
if(_instance->BreakoutGame_counter_var == 0 || logMem) {
uint32_t ts;
if(_instance->BreakoutGame_lastTimestamp_var == 0) {
ts = 0;
_instance->BreakoutGame_lastTimestamp_var = f_BreakoutGameArduino_timestamp(_instance);

} else {
uint32_t t = f_BreakoutGameArduino_timestamp(_instance);
ts = t - _instance->BreakoutGame_lastTimestamp_var;
_instance->BreakoutGame_lastTimestamp_var = t;

}
if( !(_instance->BreakoutGame_QUIET_var)) {
Serial.print("ts:");
Serial.print(ts);
Serial.print(",lives:");
Serial.print(_instance->BreakoutGame_lives_var);
Serial.print(",score:");
Serial.print(_instance->BreakoutGame_score_var);
Serial.print(",level:");
Serial.print(_instance->BreakoutGame_level_var);
Serial.print(",bx:");
Serial.print(_instance->BreakoutGame_bx_var);
Serial.print(",by:");
Serial.print(_instance->BreakoutGame_by_var);
Serial.print(",padx:");
Serial.print(_instance->BreakoutGame_padx_var);
Serial.print("\n");
Serial.print("#usedMem:");
Serial.print(f_BreakoutGameArduino_usedMemory(_instance));
Serial.print("\n");

}

}
_instance->BreakoutGame_counter_var++;
if(_instance->BreakoutGame_counter_var == 33) {
_instance->BreakoutGame_counter_var = 0;

}
}
// Definition of function initColors
void f_BreakoutGameArduino_initColors(struct BreakoutGameArduino_Instance *_instance) {
_instance->BreakoutGame_bgcolor_var[0] = 53;
_instance->BreakoutGame_bgcolor_var[1] = 40;
_instance->BreakoutGame_bgcolor_var[2] = 120;
_instance->BreakoutGame_fgcolor_var[0] = 107;
_instance->BreakoutGame_fgcolor_var[1] = 94;
_instance->BreakoutGame_fgcolor_var[2] = 174;
uint8_t r_867 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_868 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_869 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setBGColor(_instance, r_867, g_868, b_869);
uint8_t setBGColorsent_log_870[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x08, r_867, g_868, b_869};
BreakoutGameArduino_send_log_log(_instance, setBGColorsent_log_870, 7);
uint8_t r_871 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_872 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_873 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_871, g_872, b_873);
uint8_t setColorsent_log_874[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_871, g_872, b_873};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_874, 7);
uint8_t initColors_log0[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x00};
BreakoutGameArduino_send_log_log(_instance, initColors_log0, 4);
}
// Definition of function resetBall
void f_BreakoutGameArduino_resetBall(struct BreakoutGameArduino_Instance *_instance) {
int16_t old_bx_4 = _instance->BreakoutGame_bx_var;
_instance->BreakoutGame_bx_var = _instance->BreakoutGame_padx_var - _instance->BreakoutGame_br_var / _instance->BreakoutGame_SCALE_var;
int16_t new_bx_4 = _instance->BreakoutGame_bx_var;
uint8_t bx_log_4[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, (((old_bx_4 >> 8) & 0xFF)), (((old_bx_4 >> 0) & 0xFF)), (((new_bx_4 >> 8) & 0xFF)), (((new_bx_4 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, bx_log_4, 7);
int16_t old_by_28 = _instance->BreakoutGame_by_var;
_instance->BreakoutGame_by_var = _instance->BreakoutGame_pady_var - _instance->BreakoutGame_br_var / _instance->BreakoutGame_SCALE_var;
int16_t new_by_28 = _instance->BreakoutGame_by_var;
uint8_t by_log_28[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, (((old_by_28 >> 8) & 0xFF)), (((old_by_28 >> 0) & 0xFF)), (((new_by_28 >> 8) & 0xFF)), (((new_by_28 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, by_log_28, 7);
int16_t old_dx_15 = _instance->BreakoutGame_dx_var;
_instance->BreakoutGame_dx_var = (_instance->BreakoutGame_padx_var + _instance->BreakoutGame_prevBX_var + _instance->BreakoutGame_prevBY_var) % 300 - 150;
int16_t new_dx_15 = _instance->BreakoutGame_dx_var;
uint8_t dx_log_15[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, (((old_dx_15 >> 8) & 0xFF)), (((old_dx_15 >> 0) & 0xFF)), (((new_dx_15 >> 8) & 0xFF)), (((new_dx_15 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, dx_log_15, 7);
if(_instance->BreakoutGame_dy_var > 0) {
int16_t old_dy_20 = _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
int16_t new_dy_20 = _instance->BreakoutGame_dy_var;
uint8_t dy_log_20[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0E, (((old_dy_20 >> 8) & 0xFF)), (((old_dy_20 >> 0) & 0xFF)), (((new_dy_20 >> 8) & 0xFF)), (((new_dy_20 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, dy_log_20, 7);

}
int16_t old_prevBX_10 = _instance->BreakoutGame_prevBX_var;
_instance->BreakoutGame_prevBX_var =  -1;
int16_t new_prevBX_10 = _instance->BreakoutGame_prevBX_var;
uint8_t prevBX_log_10[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x12, (((old_prevBX_10 >> 8) & 0xFF)), (((old_prevBX_10 >> 0) & 0xFF)), (((new_prevBX_10 >> 8) & 0xFF)), (((new_prevBX_10 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, prevBX_log_10, 7);
int16_t old_prevBY_0 = _instance->BreakoutGame_prevBY_var;
_instance->BreakoutGame_prevBY_var =  -1;
int16_t new_prevBY_0 = _instance->BreakoutGame_prevBY_var;
uint8_t prevBY_log_0[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x13, (((old_prevBY_0 >> 8) & 0xFF)), (((old_prevBY_0 >> 0) & 0xFF)), (((new_prevBY_0 >> 8) & 0xFF)), (((new_prevBY_0 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, prevBY_log_0, 7);
uint8_t resetBall_log1[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x00};
BreakoutGameArduino_send_log_log(_instance, resetBall_log1, 4);
}
// Definition of function eraseBall
void f_BreakoutGameArduino_eraseBall(struct BreakoutGameArduino_Instance *_instance) {
int16_t bs = (_instance->BreakoutGame_br_var * 2) / _instance->BreakoutGame_SCALE_var;
if(_instance->BreakoutGame_prevBX_var > 0) {
uint8_t r_875 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_876 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_877 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_875, g_876, b_877);
uint8_t setColorsent_log_878[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_875, g_876, b_877};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_878, 7);
uint8_t x_879 = _instance->BreakoutGame_prevBX_var;
uint8_t y_880 = _instance->BreakoutGame_prevBY_var;
uint8_t width_881 = bs;
uint8_t height_882 = bs;
BreakoutGameArduino_send_display_fillRect(_instance, x_879, y_880, width_881, height_882);
uint8_t fillRectsent_log_883[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_879, y_880, width_881, height_882};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_883, 8);

}
int16_t old_prevBX_11 = _instance->BreakoutGame_prevBX_var;
_instance->BreakoutGame_prevBX_var =  -1;
int16_t new_prevBX_11 = _instance->BreakoutGame_prevBX_var;
uint8_t prevBX_log_11[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x12, (((old_prevBX_11 >> 8) & 0xFF)), (((old_prevBX_11 >> 0) & 0xFF)), (((new_prevBX_11 >> 8) & 0xFF)), (((new_prevBX_11 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, prevBX_log_11, 7);
int16_t old_prevBY_1 = _instance->BreakoutGame_prevBY_var;
_instance->BreakoutGame_prevBY_var =  -1;
int16_t new_prevBY_1 = _instance->BreakoutGame_prevBY_var;
uint8_t prevBY_log_1[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x13, (((old_prevBY_1 >> 8) & 0xFF)), (((old_prevBY_1 >> 0) & 0xFF)), (((new_prevBY_1 >> 8) & 0xFF)), (((new_prevBY_1 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, prevBY_log_1, 7);
uint8_t eraseBall_log2[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x03, 0x00};
BreakoutGameArduino_send_log_log(_instance, eraseBall_log2, 4);
}
// Definition of function drawBall
void f_BreakoutGameArduino_drawBall(struct BreakoutGameArduino_Instance *_instance) {
int16_t bs = (_instance->BreakoutGame_br_var * 2) / _instance->BreakoutGame_SCALE_var;
f_BreakoutGameArduino_eraseBall(_instance);
int16_t old_prevBX_12 = _instance->BreakoutGame_prevBX_var;
_instance->BreakoutGame_prevBX_var = (_instance->BreakoutGame_bx_var - _instance->BreakoutGame_br_var) / _instance->BreakoutGame_SCALE_var;
int16_t new_prevBX_12 = _instance->BreakoutGame_prevBX_var;
uint8_t prevBX_log_12[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x12, (((old_prevBX_12 >> 8) & 0xFF)), (((old_prevBX_12 >> 0) & 0xFF)), (((new_prevBX_12 >> 8) & 0xFF)), (((new_prevBX_12 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, prevBX_log_12, 7);
int16_t old_prevBY_2 = _instance->BreakoutGame_prevBY_var;
_instance->BreakoutGame_prevBY_var = (_instance->BreakoutGame_by_var - _instance->BreakoutGame_br_var) / _instance->BreakoutGame_SCALE_var;
int16_t new_prevBY_2 = _instance->BreakoutGame_prevBY_var;
uint8_t prevBY_log_2[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x13, (((old_prevBY_2 >> 8) & 0xFF)), (((old_prevBY_2 >> 0) & 0xFF)), (((new_prevBY_2 >> 8) & 0xFF)), (((new_prevBY_2 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, prevBY_log_2, 7);
uint8_t r_884 = 183;
uint8_t g_885 = 199;
uint8_t b_886 = 111;
BreakoutGameArduino_send_display_setColor(_instance, r_884, g_885, b_886);
uint8_t setColorsent_log_887[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_884, g_885, b_886};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_887, 7);
uint8_t x_888 = _instance->BreakoutGame_prevBX_var;
uint8_t y_889 = _instance->BreakoutGame_prevBY_var;
uint8_t width_890 = bs;
uint8_t height_891 = bs;
BreakoutGameArduino_send_display_fillRect(_instance, x_888, y_889, width_890, height_891);
uint8_t fillRectsent_log_892[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_888, y_889, width_890, height_891};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_892, 8);
uint8_t drawBall_log3[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x04, 0x00};
BreakoutGameArduino_send_log_log(_instance, drawBall_log3, 4);
}
// Definition of function erasePad
void f_BreakoutGameArduino_erasePad(struct BreakoutGameArduino_Instance *_instance) {
int16_t ps = _instance->BreakoutGame_padlen_var / _instance->BreakoutGame_SCALE_var;
if(_instance->BreakoutGame_prevPX_var > 0) {
uint8_t r_893 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_894 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_895 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_893, g_894, b_895);
uint8_t setColorsent_log_896[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_893, g_894, b_895};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_896, 7);
uint8_t x_897 = _instance->BreakoutGame_prevPX_var;
uint8_t y_898 = _instance->BreakoutGame_prevPY_var;
uint8_t width_899 = ps;
uint8_t height_900 = 4;
BreakoutGameArduino_send_display_fillRect(_instance, x_897, y_898, width_899, height_900);
uint8_t fillRectsent_log_901[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_897, y_898, width_899, height_900};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_901, 8);

}
uint8_t erasePad_log4[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x00};
BreakoutGameArduino_send_log_log(_instance, erasePad_log4, 4);
}
// Definition of function drawPad
void f_BreakoutGameArduino_drawPad(struct BreakoutGameArduino_Instance *_instance) {
int16_t ps = _instance->BreakoutGame_padlen_var / _instance->BreakoutGame_SCALE_var;
f_BreakoutGameArduino_erasePad(_instance);
int16_t old_prevPX_25 = _instance->BreakoutGame_prevPX_var;
_instance->BreakoutGame_prevPX_var = (_instance->BreakoutGame_padx_var - (_instance->BreakoutGame_padlen_var / 2)) / _instance->BreakoutGame_SCALE_var;
int16_t new_prevPX_25 = _instance->BreakoutGame_prevPX_var;
uint8_t prevPX_log_25[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x17, (((old_prevPX_25 >> 8) & 0xFF)), (((old_prevPX_25 >> 0) & 0xFF)), (((new_prevPX_25 >> 8) & 0xFF)), (((new_prevPX_25 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, prevPX_log_25, 7);
int16_t old_prevPY_26 = _instance->BreakoutGame_prevPY_var;
_instance->BreakoutGame_prevPY_var = _instance->BreakoutGame_pady_var / _instance->BreakoutGame_SCALE_var;
int16_t new_prevPY_26 = _instance->BreakoutGame_prevPY_var;
uint8_t prevPY_log_26[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x18, (((old_prevPY_26 >> 8) & 0xFF)), (((old_prevPY_26 >> 0) & 0xFF)), (((new_prevPY_26 >> 8) & 0xFF)), (((new_prevPY_26 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, prevPY_log_26, 7);
uint8_t r_902 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_903 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_904 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_902, g_903, b_904);
uint8_t setColorsent_log_905[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_902, g_903, b_904};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_905, 7);
uint8_t x_906 = _instance->BreakoutGame_prevPX_var;
uint8_t y_907 = _instance->BreakoutGame_prevPY_var;
uint8_t width_908 = ps;
uint8_t height_909 = 4;
BreakoutGameArduino_send_display_fillRect(_instance, x_906, y_907, width_908, height_909);
uint8_t fillRectsent_log_910[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_906, y_907, width_908, height_909};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_910, 8);
uint8_t drawPad_log5[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x06, 0x00};
BreakoutGameArduino_send_log_log(_instance, drawPad_log5, 4);
}
// Definition of function drawCountDown
void f_BreakoutGameArduino_drawCountDown(struct BreakoutGameArduino_Instance *_instance, int16_t c) {
uint8_t r_911 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_912 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_913 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_911, g_912, b_913);
uint8_t setColorsent_log_914[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_911, g_912, b_913};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_914, 7);
if(c > 0) {
uint8_t r_915 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_916 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_917 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_915, g_916, b_917);
uint8_t setColorsent_log_918[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_915, g_916, b_917};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_918, 7);
uint8_t r_919 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_920 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_921 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setBGColor(_instance, r_919, g_920, b_921);
uint8_t setBGColorsent_log_922[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x08, r_919, g_920, b_921};
BreakoutGameArduino_send_log_log(_instance, setBGColorsent_log_922, 7);
uint8_t x_923 = 80 - 6;
uint8_t y_924 = 90;
int16_t v_925 = c;
uint8_t digits_926 = 1;
uint8_t scale_927 = 4;
BreakoutGameArduino_send_display_drawInteger(_instance, x_923, y_924, v_925, digits_926, scale_927);
uint8_t drawIntegersent_log_928[10] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0B, x_923, y_924, (((v_925 >> 8) & 0xFF)), (((v_925 >> 0) & 0xFF)), digits_926, scale_927};
BreakoutGameArduino_send_log_log(_instance, drawIntegersent_log_928, 10);

} else {
uint8_t r_929 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_930 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_931 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_929, g_930, b_931);
uint8_t setColorsent_log_932[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_929, g_930, b_931};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_932, 7);
uint8_t x_933 = 80 - 6;
uint8_t y_934 = 90;
uint8_t width_935 = 12;
uint8_t height_936 = 20;
BreakoutGameArduino_send_display_fillRect(_instance, x_933, y_934, width_935, height_936);
uint8_t fillRectsent_log_937[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_933, y_934, width_935, height_936};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_937, 8);

}
uint8_t drawCountDown_log6[6] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x07, 0x00, (((c >> 8) & 0xFF)), (((c >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, drawCountDown_log6, 6);
}
// Definition of function drawWalls
void f_BreakoutGameArduino_drawWalls(struct BreakoutGameArduino_Instance *_instance) {
uint8_t r_938 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_939 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_940 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_938, g_939, b_940);
uint8_t setColorsent_log_941[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_938, g_939, b_940};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_941, 7);
uint8_t left = (_instance->BreakoutGame_LEFT_var / _instance->BreakoutGame_SCALE_var);
uint8_t right = (_instance->BreakoutGame_RIGHT_var / _instance->BreakoutGame_SCALE_var);
uint8_t top = (_instance->BreakoutGame_TOP_var / _instance->BreakoutGame_SCALE_var);
uint8_t bottom = (_instance->BreakoutGame_BOTTOM_var / _instance->BreakoutGame_SCALE_var);
uint8_t xcenter = ((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / _instance->BreakoutGame_SCALE_var);
uint8_t ycenter = ((_instance->BreakoutGame_BOTTOM_var - _instance->BreakoutGame_TOP_var) / _instance->BreakoutGame_SCALE_var);
uint8_t x_942 = left - 1;
uint8_t y_943 = top - 1;
uint8_t width_944 = xcenter + 1;
uint8_t height_945 = 1;
BreakoutGameArduino_send_display_fillRect(_instance, x_942, y_943, width_944, height_945);
uint8_t fillRectsent_log_946[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_942, y_943, width_944, height_945};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_946, 8);
uint8_t x_947 = left - 1;
uint8_t y_948 = bottom;
uint8_t width_949 = xcenter + 1;
uint8_t height_950 = 1;
BreakoutGameArduino_send_display_fillRect(_instance, x_947, y_948, width_949, height_950);
uint8_t fillRectsent_log_951[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_947, y_948, width_949, height_950};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_951, 8);
uint8_t x_952 = left - 1;
uint8_t y_953 = top;
uint8_t width_954 = 1;
uint8_t height_955 = ycenter;
BreakoutGameArduino_send_display_fillRect(_instance, x_952, y_953, width_954, height_955);
uint8_t fillRectsent_log_956[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_952, y_953, width_954, height_955};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_956, 8);
uint8_t x_957 = right;
uint8_t y_958 = top;
uint8_t width_959 = 1;
uint8_t height_960 = ycenter;
BreakoutGameArduino_send_display_fillRect(_instance, x_957, y_958, width_959, height_960);
uint8_t fillRectsent_log_961[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_957, y_958, width_959, height_960};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_961, 8);
uint8_t drawWalls_log7[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x08, 0x00};
BreakoutGameArduino_send_log_log(_instance, drawWalls_log7, 4);
}
// Definition of function bitIsSet
bool f_BreakoutGameArduino_bitIsSet(struct BreakoutGameArduino_Instance *_instance, uint8_t variable, uint8_t bit) {
bool return_0 = (((1 << bit) & variable) != 0);
uint8_t bitIsSet_log8[7] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x09, 0x00, variable, bit, return_0};
BreakoutGameArduino_send_log_log(_instance, bitIsSet_log8, 7);
return return_0;
}
// Definition of function createBricks
void f_BreakoutGameArduino_createBricks(struct BreakoutGameArduino_Instance *_instance) {
uint8_t y = 0;
while(y < _instance->BreakoutGame_BRICK_ROWS_var) {
_instance->BreakoutGame_bricks_var[y] = 0xFF;
uint8_t x = 0;
while(x < 8) {
if(f_BreakoutGameArduino_bitIsSet(_instance, _instance->BreakoutGame_bricks_var[y], x)) {
f_BreakoutGameArduino_drawBrick(_instance, x, y);

}
x = x + 1;

}
y = y + 1;

}
uint8_t createBricks_log9[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0A, 0x00};
BreakoutGameArduino_send_log_log(_instance, createBricks_log9, 4);
}
// Definition of function bricksLeft
uint8_t f_BreakoutGameArduino_bricksLeft(struct BreakoutGameArduino_Instance *_instance) {
uint8_t result = 0;
uint8_t y = 0;
while(y < _instance->BreakoutGame_BRICK_ROWS_var) {
uint8_t x = 0;
while(x < 8) {
if(f_BreakoutGameArduino_bitIsSet(_instance, _instance->BreakoutGame_bricks_var[y], x)) {
result = result + 1;

}
x = x + 1;

}
y = y + 1;

}
uint8_t return_3 = result;
uint8_t bricksLeft_log10[5] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, 0x00, return_3};
BreakoutGameArduino_send_log_log(_instance, bricksLeft_log10, 5);
return return_3;
}
// Definition of function drawBrick
void f_BreakoutGameArduino_drawBrick(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y) {
uint8_t bx = ((_instance->BreakoutGame_LEFT_var + ((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) * x) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t by = ((_instance->BreakoutGame_TOP_var + 20 * _instance->BreakoutGame_SCALE_var + _instance->BreakoutGame_BRICK_HEIGHT_var * y * _instance->BreakoutGame_SCALE_var) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t w = (((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) / _instance->BreakoutGame_SCALE_var - 2);
uint8_t h = (_instance->BreakoutGame_BRICK_HEIGHT_var - 2);
uint8_t r_962 = 155;
uint8_t g_963 = 103;
uint8_t b_964 = 89;
BreakoutGameArduino_send_display_setColor(_instance, r_962, g_963, b_964);
uint8_t setColorsent_log_965[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_962, g_963, b_964};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_965, 7);
uint8_t x_966 = bx;
uint8_t y_967 = by;
uint8_t width_968 = w;
uint8_t height_969 = h;
BreakoutGameArduino_send_display_fillRect(_instance, x_966, y_967, width_968, height_969);
uint8_t fillRectsent_log_970[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_966, y_967, width_968, height_969};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_970, 8);
uint8_t r_971 = 100;
uint8_t g_972 = 56;
uint8_t b_973 = 43;
BreakoutGameArduino_send_display_setColor(_instance, r_971, g_972, b_973);
uint8_t setColorsent_log_974[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_971, g_972, b_973};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_974, 7);
uint8_t x_975 = bx;
uint8_t y_976 = by;
uint8_t width_977 = w;
uint8_t height_978 = h;
BreakoutGameArduino_send_display_drawRect(_instance, x_975, y_976, width_977, height_978);
uint8_t drawRectsent_log_979[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x09, x_975, y_976, width_977, height_978};
BreakoutGameArduino_send_log_log(_instance, drawRectsent_log_979, 8);
uint8_t drawBrick_log11[6] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, 0x00, x, y};
BreakoutGameArduino_send_log_log(_instance, drawBrick_log11, 6);
}
// Definition of function removeBrick
void f_BreakoutGameArduino_removeBrick(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y) {
uint8_t bx = ((_instance->BreakoutGame_LEFT_var + ((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) * x) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t by = ((_instance->BreakoutGame_TOP_var + 20 * _instance->BreakoutGame_SCALE_var + _instance->BreakoutGame_BRICK_HEIGHT_var * y * _instance->BreakoutGame_SCALE_var) / _instance->BreakoutGame_SCALE_var + 1);
uint8_t r_980 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_981 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_982 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_980, g_981, b_982);
uint8_t setColorsent_log_983[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_980, g_981, b_982};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_983, 7);
uint8_t x_984 = bx;
uint8_t y_985 = by;
uint8_t width_986 = (((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8) / _instance->BreakoutGame_SCALE_var - 2);
uint8_t height_987 = _instance->BreakoutGame_BRICK_HEIGHT_var - 2;
BreakoutGameArduino_send_display_fillRect(_instance, x_984, y_985, width_986, height_987);
uint8_t fillRectsent_log_988[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_984, y_985, width_986, height_987};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_988, 8);
_instance->BreakoutGame_bricks_var[y] = f_BreakoutGameArduino_unsetBit(_instance, _instance->BreakoutGame_bricks_var[y], x);
uint8_t removeBrick_log12[6] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, 0x00, x, y};
BreakoutGameArduino_send_log_log(_instance, removeBrick_log12, 6);
}
// Definition of function collideBrick
bool f_BreakoutGameArduino_collideBrick(struct BreakoutGameArduino_Instance *_instance, int16_t xpos, int16_t ypos) {
int16_t bry = (ypos - _instance->BreakoutGame_TOP_var - 20 * _instance->BreakoutGame_SCALE_var) / (_instance->BreakoutGame_BRICK_HEIGHT_var * _instance->BreakoutGame_SCALE_var);
bool result = 0;
if(bry >= 0 && bry < _instance->BreakoutGame_BRICK_ROWS_var) {
int16_t brx = (xpos - _instance->BreakoutGame_LEFT_var) / ((_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 8);
if(f_BreakoutGameArduino_bitIsSet(_instance, _instance->BreakoutGame_bricks_var[bry], brx)) {
f_BreakoutGameArduino_removeBrick(_instance, brx, bry);
result = 1;

}

}
bool return_3 = result;
uint8_t collideBrick_log13[9] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0E, 0x00, (((xpos >> 8) & 0xFF)), (((xpos >> 0) & 0xFF)), (((ypos >> 8) & 0xFF)), (((ypos >> 0) & 0xFF)), return_3};
BreakoutGameArduino_send_log_log(_instance, collideBrick_log13, 9);
return return_3;
}
// Definition of function drawLevel
void f_BreakoutGameArduino_drawLevel(struct BreakoutGameArduino_Instance *_instance) {
uint8_t r_989 = 158;
uint8_t g_990 = 209;
uint8_t b_991 = 130;
BreakoutGameArduino_send_display_setColor(_instance, r_989, g_990, b_991);
uint8_t setColorsent_log_992[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_989, g_990, b_991};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_992, 7);
uint8_t r_993 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_994 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_995 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setBGColor(_instance, r_993, g_994, b_995);
uint8_t setBGColorsent_log_996[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x08, r_993, g_994, b_995};
BreakoutGameArduino_send_log_log(_instance, setBGColorsent_log_996, 7);
uint8_t r_997 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_998 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_999 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_997, g_998, b_999);
uint8_t setColorsent_log_1000[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_997, g_998, b_999};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_1000, 7);
uint8_t x_1001 = 6;
uint8_t y_1002 = 2;
int16_t v_1003 = _instance->BreakoutGame_level_var;
uint8_t digits_1004 = 2;
uint8_t scale_1005 = 2;
BreakoutGameArduino_send_display_drawInteger(_instance, x_1001, y_1002, v_1003, digits_1004, scale_1005);
uint8_t drawIntegersent_log_1006[10] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0B, x_1001, y_1002, (((v_1003 >> 8) & 0xFF)), (((v_1003 >> 0) & 0xFF)), digits_1004, scale_1005};
BreakoutGameArduino_send_log_log(_instance, drawIntegersent_log_1006, 10);
uint8_t drawLevel_log14[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0F, 0x00};
BreakoutGameArduino_send_log_log(_instance, drawLevel_log14, 4);
}
// Definition of function incrementScore
void f_BreakoutGameArduino_incrementScore(struct BreakoutGameArduino_Instance *_instance, int8_t diff) {
int16_t old_score_8 = _instance->BreakoutGame_score_var;
_instance->BreakoutGame_score_var = _instance->BreakoutGame_score_var + diff;
int16_t new_score_8 = _instance->BreakoutGame_score_var;
uint8_t score_log_8[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x1C, (((old_score_8 >> 8) & 0xFF)), (((old_score_8 >> 0) & 0xFF)), (((new_score_8 >> 8) & 0xFF)), (((new_score_8 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, score_log_8, 7);
if(_instance->BreakoutGame_score_var < 0) {
int16_t old_score_9 = _instance->BreakoutGame_score_var;
_instance->BreakoutGame_score_var = 0;
int16_t new_score_9 = _instance->BreakoutGame_score_var;
uint8_t score_log_9[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x1C, (((old_score_9 >> 8) & 0xFF)), (((old_score_9 >> 0) & 0xFF)), (((new_score_9 >> 8) & 0xFF)), (((new_score_9 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, score_log_9, 7);

}
f_BreakoutGameArduino_drawScore(_instance);
uint8_t incrementScore_log15[5] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x10, 0x00, diff};
BreakoutGameArduino_send_log_log(_instance, incrementScore_log15, 5);
}
// Definition of function drawScore
void f_BreakoutGameArduino_drawScore(struct BreakoutGameArduino_Instance *_instance) {
uint8_t r_1007 = 158;
uint8_t g_1008 = 209;
uint8_t b_1009 = 130;
BreakoutGameArduino_send_display_setColor(_instance, r_1007, g_1008, b_1009);
uint8_t setColorsent_log_1010[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_1007, g_1008, b_1009};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_1010, 7);
uint8_t r_1011 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_1012 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_1013 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setBGColor(_instance, r_1011, g_1012, b_1013);
uint8_t setBGColorsent_log_1014[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x08, r_1011, g_1012, b_1013};
BreakoutGameArduino_send_log_log(_instance, setBGColorsent_log_1014, 7);
uint8_t x_1015 = 58;
uint8_t y_1016 = 2;
int16_t v_1017 = _instance->BreakoutGame_score_var;
uint8_t digits_1018 = 5;
uint8_t scale_1019 = 2;
BreakoutGameArduino_send_display_drawInteger(_instance, x_1015, y_1016, v_1017, digits_1018, scale_1019);
uint8_t drawIntegersent_log_1020[10] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0B, x_1015, y_1016, (((v_1017 >> 8) & 0xFF)), (((v_1017 >> 0) & 0xFF)), digits_1018, scale_1019};
BreakoutGameArduino_send_log_log(_instance, drawIntegersent_log_1020, 10);
uint8_t drawScore_log16[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x11, 0x00};
BreakoutGameArduino_send_log_log(_instance, drawScore_log16, 4);
}
// Definition of function drawLives
void f_BreakoutGameArduino_drawLives(struct BreakoutGameArduino_Instance *_instance) {
uint8_t r_1021 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_1022 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_1023 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_1021, g_1022, b_1023);
uint8_t setColorsent_log_1024[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_1021, g_1022, b_1023};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_1024, 7);
uint8_t x_1025 = 124;
uint8_t y_1026 = 4;
uint8_t width_1027 = 24 + 6;
uint8_t height_1028 = 6;
BreakoutGameArduino_send_display_fillRect(_instance, x_1025, y_1026, width_1027, height_1028);
uint8_t fillRectsent_log_1029[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_1025, y_1026, width_1027, height_1028};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_1029, 8);
uint8_t r_1030 = 183;
uint8_t g_1031 = 199;
uint8_t b_1032 = 111;
BreakoutGameArduino_send_display_setColor(_instance, r_1030, g_1031, b_1032);
uint8_t setColorsent_log_1033[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_1030, g_1031, b_1032};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_1033, 7);
uint8_t i = 0;
while(i < _instance->BreakoutGame_lives_var) {
uint8_t x_1034 = 124 + (2 - i) * 12;
uint8_t y_1035 = 4;
uint8_t width_1036 = 6;
uint8_t height_1037 = 6;
BreakoutGameArduino_send_display_fillRect(_instance, x_1034, y_1035, width_1036, height_1037);
uint8_t fillRectsent_log_1038[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_1034, y_1035, width_1036, height_1037};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_1038, 8);
i = i + 1;

}
uint8_t drawLives_log17[4] = {LOGTYPE_FUNCTION_CALLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x12, 0x00};
BreakoutGameArduino_send_log_log(_instance, drawLives_log17, 4);
}
// Definition of function quit
void f_BreakoutGameArduino_quit(struct BreakoutGameArduino_Instance *_instance) {
Serial.print(">done in ");
Serial.print(_instance->BreakoutGame_stopTime_var - _instance->BreakoutGame_startTime_var);
Serial.print("ms!");
Serial.print("\n");
Serial.print(">lives:");
Serial.print(_instance->BreakoutGame_lives_var);
Serial.print(",score:");
Serial.print(_instance->BreakoutGame_score_var);
Serial.print(",level:");
Serial.print(_instance->BreakoutGame_level_var);
Serial.print(",bx:");
Serial.print(_instance->BreakoutGame_bx_var);
Serial.print(",by:");
Serial.print(_instance->BreakoutGame_by_var);
Serial.print(",padx:");
Serial.print(_instance->BreakoutGame_padx_var);
Serial.print("\n");
Serial.print(">usedMem:");
Serial.print(f_BreakoutGameArduino_usedMemory(_instance));
Serial.print("\n");
}
// Definition of function timestamp
uint32_t f_BreakoutGameArduino_timestamp(struct BreakoutGameArduino_Instance *_instance) {
return millis();
}
// Definition of function usedMemory
uint32_t f_BreakoutGameArduino_usedMemory(struct BreakoutGameArduino_Instance *_instance) {
char top;
return _instance->BreakoutGameArduino_RAM_SIZE_var - (&top - reinterpret_cast<char*>(sbrk(0)));
}
// Definition of function unsetBit
uint8_t f_BreakoutGameArduino_unsetBit(struct BreakoutGameArduino_Instance *_instance, uint8_t variable, uint8_t bit) {
return (variable & ~(1 << bit));
}

// Sessions functionss:


// On Entry Actions:
void BreakoutGame_SC_OnEntry(int state, struct BreakoutGameArduino_Instance *_instance) {
switch(state) {
case BREAKOUTGAME_SC_STATE:{
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_INIT_STATE;
BreakoutGame_SC_OnEntry(_instance->BreakoutGame_SC_State, _instance);
break;
}
case BREAKOUTGAME_SC_PLAY_STATE:{
uint8_t id_1070 = 0;
uint16_t time_1071 = _instance->BreakoutGame_period_var;
BreakoutGameArduino_send_clock_timer_start(_instance, id_1070, time_1071);
uint8_t timer_startsent_log_1072[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x14, id_1070, (((time_1071 >> 8) & 0xFF)), (((time_1071 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, timer_startsent_log_1072, 7);
break;
}
case BREAKOUTGAME_SC_LOSTBALL_STATE:{
uint8_t id_1094 = 0;
uint16_t time_1095 = _instance->BreakoutGame_period_var;
BreakoutGameArduino_send_clock_timer_start(_instance, id_1094, time_1095);
uint8_t timer_startsent_log_1096[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x14, id_1094, (((time_1095 >> 8) & 0xFF)), (((time_1095 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, timer_startsent_log_1096, 7);
uint8_t old_lives_27 = _instance->BreakoutGame_lives_var;
_instance->BreakoutGame_lives_var = _instance->BreakoutGame_lives_var - 1;
uint8_t new_lives_27 = _instance->BreakoutGame_lives_var;
uint8_t lives_log_27[5] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x1D, old_lives_27, new_lives_27};
BreakoutGameArduino_send_log_log(_instance, lives_log_27, 5);
f_BreakoutGameArduino_eraseBall(_instance);
f_BreakoutGameArduino_erasePad(_instance);
f_BreakoutGameArduino_drawLives(_instance);
BreakoutGameArduino_send_display_update(_instance);
uint8_t updatesent_log_1097[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F};
BreakoutGameArduino_send_log_log(_instance, updatesent_log_1097, 4);
f_BreakoutGameArduino_log(_instance, 1);
break;
}
case BREAKOUTGAME_SC_GAMEOVER_STATE:{
f_BreakoutGameArduino_eraseBall(_instance);
f_BreakoutGameArduino_erasePad(_instance);
uint8_t r_1102 = 255;
uint8_t g_1103 = 255;
uint8_t b_1104 = 255;
BreakoutGameArduino_send_display_setColor(_instance, r_1102, g_1103, b_1104);
uint8_t setColorsent_log_1105[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_1102, g_1103, b_1104};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_1105, 7);
uint8_t x_1106 = 8;
uint8_t y_1107 = 30;
uint8_t width_1108 = 142;
uint8_t height_1109 = 76;
BreakoutGameArduino_send_display_fillRect(_instance, x_1106, y_1107, width_1108, height_1109);
uint8_t fillRectsent_log_1110[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_1106, y_1107, width_1108, height_1109};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_1110, 8);
uint8_t r_1111 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_1112 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_1113 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_1111, g_1112, b_1113);
uint8_t setColorsent_log_1114[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_1111, g_1112, b_1113};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_1114, 7);
uint8_t x_1115 = 9;
uint8_t y_1116 = 31;
uint8_t width_1117 = 140;
uint8_t height_1118 = 50;
BreakoutGameArduino_send_display_fillRect(_instance, x_1115, y_1116, width_1117, height_1118);
uint8_t fillRectsent_log_1119[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_1115, y_1116, width_1117, height_1118};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_1119, 8);
uint8_t r_1120 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_1121 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_1122 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setBGColor(_instance, r_1120, g_1121, b_1122);
uint8_t setBGColorsent_log_1123[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x08, r_1120, g_1121, b_1122};
BreakoutGameArduino_send_log_log(_instance, setBGColorsent_log_1123, 7);
uint8_t r_1124 = 158;
uint8_t g_1125 = 209;
uint8_t b_1126 = 130;
BreakoutGameArduino_send_display_setColor(_instance, r_1124, g_1125, b_1126);
uint8_t setColorsent_log_1127[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_1124, g_1125, b_1126};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_1127, 7);
uint8_t x_1128 = 23;
uint8_t y_1129 = 40;
int16_t v_1130 = _instance->BreakoutGame_score_var;
uint8_t digits_1131 = 5;
uint8_t scale_1132 = 6;
BreakoutGameArduino_send_display_drawInteger(_instance, x_1128, y_1129, v_1130, digits_1131, scale_1132);
uint8_t drawIntegersent_log_1133[10] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0B, x_1128, y_1129, (((v_1130 >> 8) & 0xFF)), (((v_1130 >> 0) & 0xFF)), digits_1131, scale_1132};
BreakoutGameArduino_send_log_log(_instance, drawIntegersent_log_1133, 10);
uint8_t x_1134 = 26;
uint8_t y_1135 = 87;
BreakoutGameArduino_send_display_drawThingML(_instance, x_1134, y_1135);
uint8_t drawThingMLsent_log_1136[6] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0C, x_1134, y_1135};
BreakoutGameArduino_send_log_log(_instance, drawThingMLsent_log_1136, 6);
BreakoutGameArduino_send_display_update(_instance);
uint8_t updatesent_log_1137[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F};
BreakoutGameArduino_send_log_log(_instance, updatesent_log_1137, 4);
f_BreakoutGameArduino_log(_instance, 1);
_instance->BreakoutGame_stopTime_var = f_BreakoutGameArduino_timestamp(_instance);
f_BreakoutGameArduino_quit(_instance);
_instance->active = false;
break;
}
case BREAKOUTGAME_SC_LAUNCH_STATE:{
uint8_t id_1061 = 0;
uint16_t time_1062 = _instance->BreakoutGame_period_var;
BreakoutGameArduino_send_clock_timer_start(_instance, id_1061, time_1062);
uint8_t timer_startsent_log_1063[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x14, id_1061, (((time_1062 >> 8) & 0xFF)), (((time_1062 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, timer_startsent_log_1063, 7);
uint8_t old_countdown_13 = _instance->BreakoutGame_SC_LAUNCH_countdown_var;
_instance->BreakoutGame_SC_LAUNCH_countdown_var = 3;
uint8_t new_countdown_13 = _instance->BreakoutGame_SC_LAUNCH_countdown_var;
uint8_t countdown_log_13[5] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x1F, old_countdown_13, new_countdown_13};
BreakoutGameArduino_send_log_log(_instance, countdown_log_13, 5);
f_BreakoutGameArduino_drawScore(_instance);
f_BreakoutGameArduino_drawLives(_instance);
BreakoutGameArduino_send_display_update(_instance);
uint8_t updatesent_log_1064[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F};
BreakoutGameArduino_send_log_log(_instance, updatesent_log_1064, 4);
break;
}
case BREAKOUTGAME_SC_NEXTLEVEL_STATE:{
uint8_t id_1098 = 0;
uint16_t time_1099 = _instance->BreakoutGame_period_var;
BreakoutGameArduino_send_clock_timer_start(_instance, id_1098, time_1099);
uint8_t timer_startsent_log_1100[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x14, id_1098, (((time_1099 >> 8) & 0xFF)), (((time_1099 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, timer_startsent_log_1100, 7);
uint8_t old_level_3 = _instance->BreakoutGame_level_var;
_instance->BreakoutGame_level_var = _instance->BreakoutGame_level_var + 1;
uint8_t new_level_3 = _instance->BreakoutGame_level_var;
uint8_t level_log_3[5] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x1E, old_level_3, new_level_3};
BreakoutGameArduino_send_log_log(_instance, level_log_3, 5);
f_BreakoutGameArduino_drawLevel(_instance);
f_BreakoutGameArduino_eraseBall(_instance);
f_BreakoutGameArduino_erasePad(_instance);
if((_instance->BreakoutGame_level_var % 2) == 0 && _instance->BreakoutGame_padlen_var > 5 * _instance->BreakoutGame_SCALE_var) {
int16_t old_padlen_32 = _instance->BreakoutGame_padlen_var;
_instance->BreakoutGame_padlen_var = _instance->BreakoutGame_padlen_var - (4 * _instance->BreakoutGame_SCALE_var);
int16_t new_padlen_32 = _instance->BreakoutGame_padlen_var;
uint8_t padlen_log_32[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x11, (((old_padlen_32 >> 8) & 0xFF)), (((old_padlen_32 >> 0) & 0xFF)), (((new_padlen_32 >> 8) & 0xFF)), (((new_padlen_32 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, padlen_log_32, 7);

}
if((_instance->BreakoutGame_level_var % 2) == 1) {
int16_t old_dy_24 = _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var = (_instance->BreakoutGame_dy_var * 3) / 2;
int16_t new_dy_24 = _instance->BreakoutGame_dy_var;
uint8_t dy_log_24[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0E, (((old_dy_24 >> 8) & 0xFF)), (((old_dy_24 >> 0) & 0xFF)), (((new_dy_24 >> 8) & 0xFF)), (((new_dy_24 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, dy_log_24, 7);

}
f_BreakoutGameArduino_drawLives(_instance);
f_BreakoutGameArduino_createBricks(_instance);
BreakoutGameArduino_send_display_update(_instance);
uint8_t updatesent_log_1101[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F};
BreakoutGameArduino_send_log_log(_instance, updatesent_log_1101, 4);
break;
}
case BREAKOUTGAME_SC_INIT_STATE:{
_instance->BreakoutGame_startTime_var = f_BreakoutGameArduino_timestamp(_instance);
uint8_t xsize_1039 = _instance->BreakoutGame_XDISPSIZE_var;
uint8_t ysize_1040 = _instance->BreakoutGame_YDISPSIZE_var;
BreakoutGameArduino_send_display_create(_instance, xsize_1039, ysize_1040);
uint8_t createsent_log_1041[6] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0D, xsize_1039, ysize_1040};
BreakoutGameArduino_send_log_log(_instance, createsent_log_1041, 6);
break;
}
default: break;
}
}

// On Exit Actions:
void BreakoutGame_SC_OnExit(int state, struct BreakoutGameArduino_Instance *_instance) {
switch(state) {
case BREAKOUTGAME_SC_STATE:{
BreakoutGame_SC_OnExit(_instance->BreakoutGame_SC_State, _instance);
break;}
case BREAKOUTGAME_SC_PLAY_STATE:{
break;}
case BREAKOUTGAME_SC_LOSTBALL_STATE:{
break;}
case BREAKOUTGAME_SC_GAMEOVER_STATE:{
break;}
case BREAKOUTGAME_SC_LAUNCH_STATE:{
break;}
case BREAKOUTGAME_SC_NEXTLEVEL_STATE:{
break;}
case BREAKOUTGAME_SC_INIT_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void BreakoutGameArduino_handle_pro_game_lostBall(struct BreakoutGameArduino_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_PLAY_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LOSTBALL_STATE;
uint8_t lostBallhandled_log_1148[6] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x07, 0x01, 0x03, 0x04};
BreakoutGameArduino_send_log_log(_instance, lostBallhandled_log_1148, 6);
uint8_t id_1090 = 0;
BreakoutGameArduino_send_clock_timer_cancel(_instance, id_1090);
uint8_t timer_cancelsent_log_1091[5] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x15, id_1090};
BreakoutGameArduino_send_log_log(_instance, timer_cancelsent_log_1091, 5);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
uint8_t lostBalllost_log_1154[4] = {LOGTYPE_MESSAGE_LOST, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x07, 0x01};
BreakoutGameArduino_send_log_log(_instance, lostBalllost_log_1154, 4);
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGameArduino_handle_pro_game_nextLevel(struct BreakoutGameArduino_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_PLAY_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_NEXTLEVEL_STATE;
uint8_t nextLevelhandled_log_1147[6] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x07, 0x02, 0x03, 0x05};
BreakoutGameArduino_send_log_log(_instance, nextLevelhandled_log_1147, 6);
uint8_t id_1092 = 0;
BreakoutGameArduino_send_clock_timer_cancel(_instance, id_1092);
uint8_t timer_cancelsent_log_1093[5] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x15, id_1092};
BreakoutGameArduino_send_log_log(_instance, timer_cancelsent_log_1093, 5);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_NEXTLEVEL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
uint8_t nextLevellost_log_1155[4] = {LOGTYPE_MESSAGE_LOST, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x07, 0x02};
BreakoutGameArduino_send_log_log(_instance, nextLevellost_log_1155, 4);
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGameArduino_handle_controller_position(struct BreakoutGameArduino_Instance *_instance, int16_t x, int16_t y) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
uint8_t positionhandled_log_1149[10] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x03, 0x12, 0x00, 0x00, (((x >> 8) & 0xFF)), (((x >> 0) & 0xFF)), (((y >> 8) & 0xFF)), (((y >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, positionhandled_log_1149, 10);
int32_t center = (_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var - _instance->BreakoutGame_padlen_var);
center = x * center;
center = center / 200;
int16_t old_padx_19 = _instance->BreakoutGame_padx_var;
_instance->BreakoutGame_padx_var = (_instance->BreakoutGame_LEFT_var + center + (_instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_LEFT_var) / 2);
int16_t new_padx_19 = _instance->BreakoutGame_padx_var;
uint8_t padx_log_19[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0F, (((old_padx_19 >> 8) & 0xFF)), (((old_padx_19 >> 0) & 0xFF)), (((new_padx_19 >> 8) & 0xFF)), (((new_padx_19 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, padx_log_19, 7);
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGameArduino_handle_display_displayReady(struct BreakoutGameArduino_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_INIT_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_INIT_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LAUNCH_STATE;
uint8_t displayReadyhandled_log_1138[6] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x10, 0x01, 0x02};
BreakoutGameArduino_send_log_log(_instance, displayReadyhandled_log_1138, 6);
BreakoutGameArduino_send_display_clear(_instance);
uint8_t clearsent_log_1042[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x06};
BreakoutGameArduino_send_log_log(_instance, clearsent_log_1042, 4);
f_BreakoutGameArduino_initColors(_instance);
uint8_t r_1043 = _instance->BreakoutGame_bgcolor_var[0];
uint8_t g_1044 = _instance->BreakoutGame_bgcolor_var[1];
uint8_t b_1045 = _instance->BreakoutGame_bgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_1043, g_1044, b_1045);
uint8_t setColorsent_log_1046[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_1043, g_1044, b_1045};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_1046, 7);
uint8_t x_1047 = 0;
uint8_t y_1048 = 0;
uint8_t width_1049 = _instance->BreakoutGame_XDISPSIZE_var;
uint8_t height_1050 = _instance->BreakoutGame_YDISPSIZE_var;
BreakoutGameArduino_send_display_fillRect(_instance, x_1047, y_1048, width_1049, height_1050);
uint8_t fillRectsent_log_1051[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_1047, y_1048, width_1049, height_1050};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_1051, 8);
uint8_t r_1052 = _instance->BreakoutGame_fgcolor_var[0];
uint8_t g_1053 = _instance->BreakoutGame_fgcolor_var[1];
uint8_t b_1054 = _instance->BreakoutGame_fgcolor_var[2];
BreakoutGameArduino_send_display_setColor(_instance, r_1052, g_1053, b_1054);
uint8_t setColorsent_log_1055[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x07, r_1052, g_1053, b_1054};
BreakoutGameArduino_send_log_log(_instance, setColorsent_log_1055, 7);
uint8_t x_1056 = 0;
uint8_t y_1057 = 0;
uint8_t width_1058 = _instance->BreakoutGame_XDISPSIZE_var;
uint8_t height_1059 = 14;
BreakoutGameArduino_send_display_fillRect(_instance, x_1056, y_1057, width_1058, height_1059);
uint8_t fillRectsent_log_1060[8] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0A, x_1056, y_1057, width_1058, height_1059};
BreakoutGameArduino_send_log_log(_instance, fillRectsent_log_1060, 8);
f_BreakoutGameArduino_drawWalls(_instance);
f_BreakoutGameArduino_createBricks(_instance);
f_BreakoutGameArduino_drawLevel(_instance);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LAUNCH_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
uint8_t displayReadylost_log_1151[4] = {LOGTYPE_MESSAGE_LOST, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x10};
BreakoutGameArduino_send_log_log(_instance, displayReadylost_log_1151, 4);
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGameArduino_handle_game_lostBall(struct BreakoutGameArduino_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_PLAY_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LOSTBALL_STATE;
uint8_t lostBallhandled_log_1140[6] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x01, 0x03, 0x04};
BreakoutGameArduino_send_log_log(_instance, lostBallhandled_log_1140, 6);
uint8_t id_1086 = 0;
BreakoutGameArduino_send_clock_timer_cancel(_instance, id_1086);
uint8_t timer_cancelsent_log_1087[5] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x15, id_1086};
BreakoutGameArduino_send_log_log(_instance, timer_cancelsent_log_1087, 5);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
uint8_t lostBalllost_log_1152[4] = {LOGTYPE_MESSAGE_LOST, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x01};
BreakoutGameArduino_send_log_log(_instance, lostBalllost_log_1152, 4);
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGameArduino_handle_game_nextLevel(struct BreakoutGameArduino_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && 1) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_PLAY_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_NEXTLEVEL_STATE;
uint8_t nextLevelhandled_log_1139[6] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x02, 0x03, 0x05};
BreakoutGameArduino_send_log_log(_instance, nextLevelhandled_log_1139, 6);
uint8_t id_1088 = 0;
BreakoutGameArduino_send_clock_timer_cancel(_instance, id_1088);
uint8_t timer_cancelsent_log_1089[5] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x15, id_1088};
BreakoutGameArduino_send_log_log(_instance, timer_cancelsent_log_1089, 5);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_NEXTLEVEL_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
uint8_t nextLevellost_log_1153[4] = {LOGTYPE_MESSAGE_LOST, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x02};
BreakoutGameArduino_send_log_log(_instance, nextLevellost_log_1153, 4);
BreakoutGame_SC_State_event_consumed = 1;
}
}
void BreakoutGameArduino_handle_clock_timer_timeout(struct BreakoutGameArduino_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region SC
uint8_t BreakoutGame_SC_State_event_consumed = 0;
if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_LAUNCH_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_SC_LAUNCH_countdown_var == 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_LAUNCH_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_PLAY_STATE;
uint8_t timer_timeouthandled_log_1145[7] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, 0x02, 0x03, id};
BreakoutGameArduino_send_log_log(_instance, timer_timeouthandled_log_1145, 7);
f_BreakoutGameArduino_drawCountDown(_instance, 0);
f_BreakoutGameArduino_resetBall(_instance);
BreakoutGameArduino_send_display_update(_instance);
uint8_t updatesent_log_1069[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F};
BreakoutGameArduino_send_log_log(_instance, updatesent_log_1069, 4);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_PLAY_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
else if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_SC_LAUNCH_countdown_var > 0) {
uint8_t timer_timeouthandled_log_1146[7] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, 0x02, 0x00, id};
BreakoutGameArduino_send_log_log(_instance, timer_timeouthandled_log_1146, 7);
uint8_t id_1065 = 0;
uint16_t time_1066 = _instance->BreakoutGame_period_var;
BreakoutGameArduino_send_clock_timer_start(_instance, id_1065, time_1066);
uint8_t timer_startsent_log_1067[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x14, id_1065, (((time_1066 >> 8) & 0xFF)), (((time_1066 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, timer_startsent_log_1067, 7);
f_BreakoutGameArduino_drawPad(_instance);
if((_instance->BreakoutGame_SC_LAUNCH_countdown_var % 30) == 0) {
f_BreakoutGameArduino_drawCountDown(_instance, _instance->BreakoutGame_SC_LAUNCH_countdown_var / 30);

}
uint8_t old_countdown_14 = _instance->BreakoutGame_SC_LAUNCH_countdown_var;
_instance->BreakoutGame_SC_LAUNCH_countdown_var = _instance->BreakoutGame_SC_LAUNCH_countdown_var - 1;
uint8_t new_countdown_14 = _instance->BreakoutGame_SC_LAUNCH_countdown_var;
uint8_t countdown_log_14[5] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x1F, old_countdown_14, new_countdown_14};
BreakoutGameArduino_send_log_log(_instance, countdown_log_14, 5);
BreakoutGameArduino_send_display_update(_instance);
uint8_t updatesent_log_1068[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F};
BreakoutGameArduino_send_log_log(_instance, updatesent_log_1068, 4);
BreakoutGame_SC_State_event_consumed = 1;
}
}
else if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_PLAY_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0) {
uint8_t timer_timeouthandled_log_1143[7] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, 0x03, 0x00, id};
BreakoutGameArduino_send_log_log(_instance, timer_timeouthandled_log_1143, 7);
int16_t old_bx_5 = _instance->BreakoutGame_bx_var;
_instance->BreakoutGame_bx_var = _instance->BreakoutGame_bx_var + _instance->BreakoutGame_dx_var;
int16_t new_bx_5 = _instance->BreakoutGame_bx_var;
uint8_t bx_log_5[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, (((old_bx_5 >> 8) & 0xFF)), (((old_bx_5 >> 0) & 0xFF)), (((new_bx_5 >> 8) & 0xFF)), (((new_bx_5 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, bx_log_5, 7);
int16_t old_by_29 = _instance->BreakoutGame_by_var;
_instance->BreakoutGame_by_var = _instance->BreakoutGame_by_var + _instance->BreakoutGame_dy_var;
int16_t new_by_29 = _instance->BreakoutGame_by_var;
uint8_t by_log_29[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, (((old_by_29 >> 8) & 0xFF)), (((old_by_29 >> 0) & 0xFF)), (((new_by_29 >> 8) & 0xFF)), (((new_by_29 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, by_log_29, 7);
int16_t wl = _instance->BreakoutGame_LEFT_var + _instance->BreakoutGame_br_var;
int16_t wr = _instance->BreakoutGame_RIGHT_var - _instance->BreakoutGame_br_var;
int16_t wt = _instance->BreakoutGame_TOP_var + _instance->BreakoutGame_br_var;
int16_t wb = _instance->BreakoutGame_BOTTOM_var - _instance->BreakoutGame_br_var;
if(_instance->BreakoutGame_bx_var < wl) {
int16_t old_dx_16 = _instance->BreakoutGame_dx_var;
_instance->BreakoutGame_dx_var =  -_instance->BreakoutGame_dx_var;
int16_t new_dx_16 = _instance->BreakoutGame_dx_var;
uint8_t dx_log_16[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, (((old_dx_16 >> 8) & 0xFF)), (((old_dx_16 >> 0) & 0xFF)), (((new_dx_16 >> 8) & 0xFF)), (((new_dx_16 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, dx_log_16, 7);
int16_t old_bx_6 = _instance->BreakoutGame_bx_var;
_instance->BreakoutGame_bx_var = 2 * wl - _instance->BreakoutGame_bx_var;
int16_t new_bx_6 = _instance->BreakoutGame_bx_var;
uint8_t bx_log_6[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, (((old_bx_6 >> 8) & 0xFF)), (((old_bx_6 >> 0) & 0xFF)), (((new_bx_6 >> 8) & 0xFF)), (((new_bx_6 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, bx_log_6, 7);
f_BreakoutGameArduino_incrementScore(_instance,  -1);

} else {
if(_instance->BreakoutGame_bx_var > wr) {
int16_t old_dx_17 = _instance->BreakoutGame_dx_var;
_instance->BreakoutGame_dx_var =  -_instance->BreakoutGame_dx_var;
int16_t new_dx_17 = _instance->BreakoutGame_dx_var;
uint8_t dx_log_17[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, (((old_dx_17 >> 8) & 0xFF)), (((old_dx_17 >> 0) & 0xFF)), (((new_dx_17 >> 8) & 0xFF)), (((new_dx_17 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, dx_log_17, 7);
int16_t old_bx_7 = _instance->BreakoutGame_bx_var;
_instance->BreakoutGame_bx_var = 2 * wr - _instance->BreakoutGame_bx_var;
int16_t new_bx_7 = _instance->BreakoutGame_bx_var;
uint8_t bx_log_7[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0B, (((old_bx_7 >> 8) & 0xFF)), (((old_bx_7 >> 0) & 0xFF)), (((new_bx_7 >> 8) & 0xFF)), (((new_bx_7 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, bx_log_7, 7);
f_BreakoutGameArduino_incrementScore(_instance,  -1);

}

}
if(_instance->BreakoutGame_by_var < wt) {
int16_t old_dy_21 = _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
int16_t new_dy_21 = _instance->BreakoutGame_dy_var;
uint8_t dy_log_21[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0E, (((old_dy_21 >> 8) & 0xFF)), (((old_dy_21 >> 0) & 0xFF)), (((new_dy_21 >> 8) & 0xFF)), (((new_dy_21 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, dy_log_21, 7);
int16_t old_by_30 = _instance->BreakoutGame_by_var;
_instance->BreakoutGame_by_var = 2 * wt - _instance->BreakoutGame_by_var;
int16_t new_by_30 = _instance->BreakoutGame_by_var;
uint8_t by_log_30[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, (((old_by_30 >> 8) & 0xFF)), (((old_by_30 >> 0) & 0xFF)), (((new_by_30 >> 8) & 0xFF)), (((new_by_30 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, by_log_30, 7);
f_BreakoutGameArduino_incrementScore(_instance,  -1);

} else {
if(_instance->BreakoutGame_by_var > wb) {
BreakoutGameArduino_send_game_lostBall(_instance);
uint8_t lostBallsent_log_1073[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x01};
BreakoutGameArduino_send_log_log(_instance, lostBallsent_log_1073, 4);
BreakoutGameArduino_send_req_game_lostBall(_instance);
uint8_t lostBallsent_log_1074[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x06, 0x01};
BreakoutGameArduino_send_log_log(_instance, lostBallsent_log_1074, 4);

}

}
if(_instance->BreakoutGame_dy_var > 0) {
if(_instance->BreakoutGame_by_var > _instance->BreakoutGame_pady_var - _instance->BreakoutGame_br_var && _instance->BreakoutGame_by_var < _instance->BreakoutGame_pady_var + _instance->BreakoutGame_br_var) {
if(_instance->BreakoutGame_bx_var > _instance->BreakoutGame_padx_var - _instance->BreakoutGame_padlen_var / 2 && _instance->BreakoutGame_bx_var < _instance->BreakoutGame_padx_var + _instance->BreakoutGame_padlen_var / 2) {
int16_t old_dy_22 = _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
int16_t new_dy_22 = _instance->BreakoutGame_dy_var;
uint8_t dy_log_22[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0E, (((old_dy_22 >> 8) & 0xFF)), (((old_dy_22 >> 0) & 0xFF)), (((new_dy_22 >> 8) & 0xFF)), (((new_dy_22 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, dy_log_22, 7);
int16_t old_by_31 = _instance->BreakoutGame_by_var;
_instance->BreakoutGame_by_var = 2 * (_instance->BreakoutGame_pady_var - _instance->BreakoutGame_br_var) - _instance->BreakoutGame_by_var;
int16_t new_by_31 = _instance->BreakoutGame_by_var;
uint8_t by_log_31[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0C, (((old_by_31 >> 8) & 0xFF)), (((old_by_31 >> 0) & 0xFF)), (((new_by_31 >> 8) & 0xFF)), (((new_by_31 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, by_log_31, 7);
int16_t old_dx_18 = _instance->BreakoutGame_dx_var;
_instance->BreakoutGame_dx_var = _instance->BreakoutGame_dx_var / 4 + (_instance->BreakoutGame_bx_var - _instance->BreakoutGame_padx_var) / 4;
int16_t new_dx_18 = _instance->BreakoutGame_dx_var;
uint8_t dx_log_18[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0D, (((old_dx_18 >> 8) & 0xFF)), (((old_dx_18 >> 0) & 0xFF)), (((new_dx_18 >> 8) & 0xFF)), (((new_dx_18 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, dx_log_18, 7);

}

}

}
bool collision = f_BreakoutGameArduino_collideBrick(_instance, _instance->BreakoutGame_bx_var - _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var - _instance->BreakoutGame_br_var) || f_BreakoutGameArduino_collideBrick(_instance, _instance->BreakoutGame_bx_var + _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var - _instance->BreakoutGame_br_var) || f_BreakoutGameArduino_collideBrick(_instance, _instance->BreakoutGame_bx_var + _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var + _instance->BreakoutGame_br_var) || f_BreakoutGameArduino_collideBrick(_instance, _instance->BreakoutGame_bx_var - _instance->BreakoutGame_br_var, _instance->BreakoutGame_by_var + _instance->BreakoutGame_br_var);
if(collision) {
int16_t old_dy_23 = _instance->BreakoutGame_dy_var;
_instance->BreakoutGame_dy_var =  -_instance->BreakoutGame_dy_var;
int16_t new_dy_23 = _instance->BreakoutGame_dy_var;
uint8_t dy_log_23[7] = {LOGTYPE_PROPERTY_CHANGED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x0E, (((old_dy_23 >> 8) & 0xFF)), (((old_dy_23 >> 0) & 0xFF)), (((new_dy_23 >> 8) & 0xFF)), (((new_dy_23 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, dy_log_23, 7);
f_BreakoutGameArduino_incrementScore(_instance, 10);
if(f_BreakoutGameArduino_bricksLeft(_instance) == 0) {
BreakoutGameArduino_send_game_nextLevel(_instance);
uint8_t nextLevelsent_log_1075[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x05, 0x02};
BreakoutGameArduino_send_log_log(_instance, nextLevelsent_log_1075, 4);
BreakoutGameArduino_send_req_game_nextLevel(_instance);
uint8_t nextLevelsent_log_1076[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x06, 0x02};
BreakoutGameArduino_send_log_log(_instance, nextLevelsent_log_1076, 4);

}

}
f_BreakoutGameArduino_drawBall(_instance);
f_BreakoutGameArduino_drawPad(_instance);
int16_t ballx_1077 = _instance->BreakoutGame_bx_var;
int16_t bally_1078 = _instance->BreakoutGame_by_var;
int16_t padx_1079 = _instance->BreakoutGame_padx_var;
int16_t pady_1080 = _instance->BreakoutGame_pady_var;
BreakoutGameArduino_send_ia_updateIA(_instance, ballx_1077, bally_1078, padx_1079, pady_1080);
uint8_t updateIAsent_log_1081[12] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x04, 0x13, (((ballx_1077 >> 8) & 0xFF)), (((ballx_1077 >> 0) & 0xFF)), (((bally_1078 >> 8) & 0xFF)), (((bally_1078 >> 0) & 0xFF)), (((padx_1079 >> 8) & 0xFF)), (((padx_1079 >> 0) & 0xFF)), (((pady_1080 >> 8) & 0xFF)), (((pady_1080 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, updateIAsent_log_1081, 12);
BreakoutGameArduino_send_display_update(_instance);
uint8_t updatesent_log_1082[4] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x02, 0x0F};
BreakoutGameArduino_send_log_log(_instance, updatesent_log_1082, 4);
f_BreakoutGameArduino_log(_instance, 0);
uint8_t id_1083 = 0;
uint16_t time_1084 = _instance->BreakoutGame_period_var;
BreakoutGameArduino_send_clock_timer_start(_instance, id_1083, time_1084);
uint8_t timer_startsent_log_1085[7] = {LOGTYPE_MESSAGE_SENT, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x14, id_1083, (((time_1084 >> 8) & 0xFF)), (((time_1084 >> 0) & 0xFF))};
BreakoutGameArduino_send_log_log(_instance, timer_startsent_log_1085, 7);
BreakoutGame_SC_State_event_consumed = 1;
}
}
else if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_LOSTBALL_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_lives_var > 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LAUNCH_STATE;
uint8_t timer_timeouthandled_log_1141[7] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, 0x04, 0x02, id};
BreakoutGameArduino_send_log_log(_instance, timer_timeouthandled_log_1141, 7);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LAUNCH_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
else if (BreakoutGame_SC_State_event_consumed == 0 && id == 0 && _instance->BreakoutGame_lives_var == 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_LOSTBALL_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_GAMEOVER_STATE;
uint8_t timer_timeouthandled_log_1142[7] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, 0x04, 0x06, id};
BreakoutGameArduino_send_log_log(_instance, timer_timeouthandled_log_1142, 7);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_GAMEOVER_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
else if (_instance->BreakoutGame_SC_State == BREAKOUTGAME_SC_NEXTLEVEL_STATE) {
if (BreakoutGame_SC_State_event_consumed == 0 && id == 0) {
BreakoutGame_SC_OnExit(BREAKOUTGAME_SC_NEXTLEVEL_STATE, _instance);
_instance->BreakoutGame_SC_State = BREAKOUTGAME_SC_LAUNCH_STATE;
uint8_t timer_timeouthandled_log_1144[7] = {LOGTYPE_MESSAGE_HANDLED, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, 0x05, 0x02, id};
BreakoutGameArduino_send_log_log(_instance, timer_timeouthandled_log_1144, 7);
BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_LAUNCH_STATE, _instance);
BreakoutGame_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
uint8_t timer_timeoutlost_log_1150[5] = {LOGTYPE_MESSAGE_LOST, _instance->WithBinaryLog_DEBUG_BIN_ID_var, 0x01, 0x16, id};
BreakoutGameArduino_send_log_log(_instance, timer_timeoutlost_log_1150, 5);
BreakoutGame_SC_State_event_consumed = 1;
}
}

// Observers for outgoing messages:
void (*external_BreakoutGameArduino_send_log_log_listener)(struct BreakoutGameArduino_Instance *, uint8_t*, uint8_t)= 0x0;
void (*BreakoutGameArduino_send_log_log_listener)(struct BreakoutGameArduino_Instance *, uint8_t*, uint8_t)= 0x0;
void register_external_BreakoutGameArduino_send_log_log_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t*, uint8_t)){
external_BreakoutGameArduino_send_log_log_listener = _listener;
}
void register_BreakoutGameArduino_send_log_log_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t*, uint8_t)){
BreakoutGameArduino_send_log_log_listener = _listener;
}
void BreakoutGameArduino_send_log_log(struct BreakoutGameArduino_Instance *_instance, uint8_t* payload, uint8_t size){
if (BreakoutGameArduino_send_log_log_listener != 0x0) BreakoutGameArduino_send_log_log_listener(_instance, payload, size);
if (external_BreakoutGameArduino_send_log_log_listener != 0x0) external_BreakoutGameArduino_send_log_log_listener(_instance, payload, size);
;
}
void (*external_BreakoutGameArduino_send_clock_timer_start_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint16_t)= 0x0;
void (*BreakoutGameArduino_send_clock_timer_start_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint16_t)= 0x0;
void register_external_BreakoutGameArduino_send_clock_timer_start_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint16_t)){
external_BreakoutGameArduino_send_clock_timer_start_listener = _listener;
}
void register_BreakoutGameArduino_send_clock_timer_start_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint16_t)){
BreakoutGameArduino_send_clock_timer_start_listener = _listener;
}
void BreakoutGameArduino_send_clock_timer_start(struct BreakoutGameArduino_Instance *_instance, uint8_t id, uint16_t time){
if (BreakoutGameArduino_send_clock_timer_start_listener != 0x0) BreakoutGameArduino_send_clock_timer_start_listener(_instance, id, time);
if (external_BreakoutGameArduino_send_clock_timer_start_listener != 0x0) external_BreakoutGameArduino_send_clock_timer_start_listener(_instance, id, time);
;
}
void (*external_BreakoutGameArduino_send_clock_timer_cancel_listener)(struct BreakoutGameArduino_Instance *, uint8_t)= 0x0;
void (*BreakoutGameArduino_send_clock_timer_cancel_listener)(struct BreakoutGameArduino_Instance *, uint8_t)= 0x0;
void register_external_BreakoutGameArduino_send_clock_timer_cancel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t)){
external_BreakoutGameArduino_send_clock_timer_cancel_listener = _listener;
}
void register_BreakoutGameArduino_send_clock_timer_cancel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t)){
BreakoutGameArduino_send_clock_timer_cancel_listener = _listener;
}
void BreakoutGameArduino_send_clock_timer_cancel(struct BreakoutGameArduino_Instance *_instance, uint8_t id){
if (BreakoutGameArduino_send_clock_timer_cancel_listener != 0x0) BreakoutGameArduino_send_clock_timer_cancel_listener(_instance, id);
if (external_BreakoutGameArduino_send_clock_timer_cancel_listener != 0x0) external_BreakoutGameArduino_send_clock_timer_cancel_listener(_instance, id);
;
}
void (*external_BreakoutGameArduino_send_display_create_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t)= 0x0;
void (*BreakoutGameArduino_send_display_create_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGameArduino_send_display_create_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t)){
external_BreakoutGameArduino_send_display_create_listener = _listener;
}
void register_BreakoutGameArduino_send_display_create_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t)){
BreakoutGameArduino_send_display_create_listener = _listener;
}
void BreakoutGameArduino_send_display_create(struct BreakoutGameArduino_Instance *_instance, uint8_t xsize, uint8_t ysize){
if (BreakoutGameArduino_send_display_create_listener != 0x0) BreakoutGameArduino_send_display_create_listener(_instance, xsize, ysize);
if (external_BreakoutGameArduino_send_display_create_listener != 0x0) external_BreakoutGameArduino_send_display_create_listener(_instance, xsize, ysize);
;
}
void (*external_BreakoutGameArduino_send_display_fillRect_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void (*BreakoutGameArduino_send_display_fillRect_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGameArduino_send_display_fillRect_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
external_BreakoutGameArduino_send_display_fillRect_listener = _listener;
}
void register_BreakoutGameArduino_send_display_fillRect_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
BreakoutGameArduino_send_display_fillRect_listener = _listener;
}
void BreakoutGameArduino_send_display_fillRect(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
if (BreakoutGameArduino_send_display_fillRect_listener != 0x0) BreakoutGameArduino_send_display_fillRect_listener(_instance, x, y, width, height);
if (external_BreakoutGameArduino_send_display_fillRect_listener != 0x0) external_BreakoutGameArduino_send_display_fillRect_listener(_instance, x, y, width, height);
;
}
void (*external_BreakoutGameArduino_send_display_drawRect_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void (*BreakoutGameArduino_send_display_drawRect_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGameArduino_send_display_drawRect_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
external_BreakoutGameArduino_send_display_drawRect_listener = _listener;
}
void register_BreakoutGameArduino_send_display_drawRect_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
BreakoutGameArduino_send_display_drawRect_listener = _listener;
}
void BreakoutGameArduino_send_display_drawRect(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
if (BreakoutGameArduino_send_display_drawRect_listener != 0x0) BreakoutGameArduino_send_display_drawRect_listener(_instance, x, y, width, height);
if (external_BreakoutGameArduino_send_display_drawRect_listener != 0x0) external_BreakoutGameArduino_send_display_drawRect_listener(_instance, x, y, width, height);
;
}
void (*external_BreakoutGameArduino_send_display_clear_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void (*BreakoutGameArduino_send_display_clear_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void register_external_BreakoutGameArduino_send_display_clear_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
external_BreakoutGameArduino_send_display_clear_listener = _listener;
}
void register_BreakoutGameArduino_send_display_clear_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
BreakoutGameArduino_send_display_clear_listener = _listener;
}
void BreakoutGameArduino_send_display_clear(struct BreakoutGameArduino_Instance *_instance){
if (BreakoutGameArduino_send_display_clear_listener != 0x0) BreakoutGameArduino_send_display_clear_listener(_instance);
if (external_BreakoutGameArduino_send_display_clear_listener != 0x0) external_BreakoutGameArduino_send_display_clear_listener(_instance);
;
}
void (*external_BreakoutGameArduino_send_display_setColor_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void (*BreakoutGameArduino_send_display_setColor_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGameArduino_send_display_setColor_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t)){
external_BreakoutGameArduino_send_display_setColor_listener = _listener;
}
void register_BreakoutGameArduino_send_display_setColor_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t)){
BreakoutGameArduino_send_display_setColor_listener = _listener;
}
void BreakoutGameArduino_send_display_setColor(struct BreakoutGameArduino_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
if (BreakoutGameArduino_send_display_setColor_listener != 0x0) BreakoutGameArduino_send_display_setColor_listener(_instance, r, g, b);
if (external_BreakoutGameArduino_send_display_setColor_listener != 0x0) external_BreakoutGameArduino_send_display_setColor_listener(_instance, r, g, b);
;
}
void (*external_BreakoutGameArduino_send_display_setBGColor_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void (*BreakoutGameArduino_send_display_setBGColor_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGameArduino_send_display_setBGColor_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t)){
external_BreakoutGameArduino_send_display_setBGColor_listener = _listener;
}
void register_BreakoutGameArduino_send_display_setBGColor_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, uint8_t)){
BreakoutGameArduino_send_display_setBGColor_listener = _listener;
}
void BreakoutGameArduino_send_display_setBGColor(struct BreakoutGameArduino_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
if (BreakoutGameArduino_send_display_setBGColor_listener != 0x0) BreakoutGameArduino_send_display_setBGColor_listener(_instance, r, g, b);
if (external_BreakoutGameArduino_send_display_setBGColor_listener != 0x0) external_BreakoutGameArduino_send_display_setBGColor_listener(_instance, r, g, b);
;
}
void (*external_BreakoutGameArduino_send_display_drawInteger_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)= 0x0;
void (*BreakoutGameArduino_send_display_drawInteger_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGameArduino_send_display_drawInteger_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)){
external_BreakoutGameArduino_send_display_drawInteger_listener = _listener;
}
void register_BreakoutGameArduino_send_display_drawInteger_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)){
BreakoutGameArduino_send_display_drawInteger_listener = _listener;
}
void BreakoutGameArduino_send_display_drawInteger(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale){
if (BreakoutGameArduino_send_display_drawInteger_listener != 0x0) BreakoutGameArduino_send_display_drawInteger_listener(_instance, x, y, v, digits, scale);
if (external_BreakoutGameArduino_send_display_drawInteger_listener != 0x0) external_BreakoutGameArduino_send_display_drawInteger_listener(_instance, x, y, v, digits, scale);
;
}
void (*external_BreakoutGameArduino_send_display_update_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void (*BreakoutGameArduino_send_display_update_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void register_external_BreakoutGameArduino_send_display_update_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
external_BreakoutGameArduino_send_display_update_listener = _listener;
}
void register_BreakoutGameArduino_send_display_update_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
BreakoutGameArduino_send_display_update_listener = _listener;
}
void BreakoutGameArduino_send_display_update(struct BreakoutGameArduino_Instance *_instance){
if (BreakoutGameArduino_send_display_update_listener != 0x0) BreakoutGameArduino_send_display_update_listener(_instance);
if (external_BreakoutGameArduino_send_display_update_listener != 0x0) external_BreakoutGameArduino_send_display_update_listener(_instance);
;
}
void (*external_BreakoutGameArduino_send_display_drawThingML_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t)= 0x0;
void (*BreakoutGameArduino_send_display_drawThingML_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_BreakoutGameArduino_send_display_drawThingML_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t)){
external_BreakoutGameArduino_send_display_drawThingML_listener = _listener;
}
void register_BreakoutGameArduino_send_display_drawThingML_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, uint8_t, uint8_t)){
BreakoutGameArduino_send_display_drawThingML_listener = _listener;
}
void BreakoutGameArduino_send_display_drawThingML(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y){
if (BreakoutGameArduino_send_display_drawThingML_listener != 0x0) BreakoutGameArduino_send_display_drawThingML_listener(_instance, x, y);
if (external_BreakoutGameArduino_send_display_drawThingML_listener != 0x0) external_BreakoutGameArduino_send_display_drawThingML_listener(_instance, x, y);
;
}
void (*external_BreakoutGameArduino_send_ia_updateIA_listener)(struct BreakoutGameArduino_Instance *, int16_t, int16_t, int16_t, int16_t)= 0x0;
void (*BreakoutGameArduino_send_ia_updateIA_listener)(struct BreakoutGameArduino_Instance *, int16_t, int16_t, int16_t, int16_t)= 0x0;
void register_external_BreakoutGameArduino_send_ia_updateIA_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, int16_t, int16_t, int16_t, int16_t)){
external_BreakoutGameArduino_send_ia_updateIA_listener = _listener;
}
void register_BreakoutGameArduino_send_ia_updateIA_listener(void (*_listener)(struct BreakoutGameArduino_Instance *, int16_t, int16_t, int16_t, int16_t)){
BreakoutGameArduino_send_ia_updateIA_listener = _listener;
}
void BreakoutGameArduino_send_ia_updateIA(struct BreakoutGameArduino_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady){
if (BreakoutGameArduino_send_ia_updateIA_listener != 0x0) BreakoutGameArduino_send_ia_updateIA_listener(_instance, ballx, bally, padx, pady);
if (external_BreakoutGameArduino_send_ia_updateIA_listener != 0x0) external_BreakoutGameArduino_send_ia_updateIA_listener(_instance, ballx, bally, padx, pady);
;
}
void (*external_BreakoutGameArduino_send_game_lostBall_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void (*BreakoutGameArduino_send_game_lostBall_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void register_external_BreakoutGameArduino_send_game_lostBall_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
external_BreakoutGameArduino_send_game_lostBall_listener = _listener;
}
void register_BreakoutGameArduino_send_game_lostBall_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
BreakoutGameArduino_send_game_lostBall_listener = _listener;
}
void BreakoutGameArduino_send_game_lostBall(struct BreakoutGameArduino_Instance *_instance){
if (BreakoutGameArduino_send_game_lostBall_listener != 0x0) BreakoutGameArduino_send_game_lostBall_listener(_instance);
if (external_BreakoutGameArduino_send_game_lostBall_listener != 0x0) external_BreakoutGameArduino_send_game_lostBall_listener(_instance);
;
}
void (*external_BreakoutGameArduino_send_game_nextLevel_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void (*BreakoutGameArduino_send_game_nextLevel_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void register_external_BreakoutGameArduino_send_game_nextLevel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
external_BreakoutGameArduino_send_game_nextLevel_listener = _listener;
}
void register_BreakoutGameArduino_send_game_nextLevel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
BreakoutGameArduino_send_game_nextLevel_listener = _listener;
}
void BreakoutGameArduino_send_game_nextLevel(struct BreakoutGameArduino_Instance *_instance){
if (BreakoutGameArduino_send_game_nextLevel_listener != 0x0) BreakoutGameArduino_send_game_nextLevel_listener(_instance);
if (external_BreakoutGameArduino_send_game_nextLevel_listener != 0x0) external_BreakoutGameArduino_send_game_nextLevel_listener(_instance);
;
}
void (*external_BreakoutGameArduino_send_req_game_lostBall_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void (*BreakoutGameArduino_send_req_game_lostBall_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void register_external_BreakoutGameArduino_send_req_game_lostBall_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
external_BreakoutGameArduino_send_req_game_lostBall_listener = _listener;
}
void register_BreakoutGameArduino_send_req_game_lostBall_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
BreakoutGameArduino_send_req_game_lostBall_listener = _listener;
}
void BreakoutGameArduino_send_req_game_lostBall(struct BreakoutGameArduino_Instance *_instance){
if (BreakoutGameArduino_send_req_game_lostBall_listener != 0x0) BreakoutGameArduino_send_req_game_lostBall_listener(_instance);
if (external_BreakoutGameArduino_send_req_game_lostBall_listener != 0x0) external_BreakoutGameArduino_send_req_game_lostBall_listener(_instance);
;
}
void (*external_BreakoutGameArduino_send_req_game_nextLevel_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void (*BreakoutGameArduino_send_req_game_nextLevel_listener)(struct BreakoutGameArduino_Instance *)= 0x0;
void register_external_BreakoutGameArduino_send_req_game_nextLevel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
external_BreakoutGameArduino_send_req_game_nextLevel_listener = _listener;
}
void register_BreakoutGameArduino_send_req_game_nextLevel_listener(void (*_listener)(struct BreakoutGameArduino_Instance *)){
BreakoutGameArduino_send_req_game_nextLevel_listener = _listener;
}
void BreakoutGameArduino_send_req_game_nextLevel(struct BreakoutGameArduino_Instance *_instance){
if (BreakoutGameArduino_send_req_game_nextLevel_listener != 0x0) BreakoutGameArduino_send_req_game_nextLevel_listener(_instance);
if (external_BreakoutGameArduino_send_req_game_nextLevel_listener != 0x0) external_BreakoutGameArduino_send_req_game_nextLevel_listener(_instance);
;
}



/*****************************************************************************
 * Implementation for type : BasicIAController
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void BasicIAController_SC_OnExit(int state, struct BasicIAController_Instance *_instance);
//Prototypes: Message Sending
void BasicIAController_send_controls_position(struct BasicIAController_Instance *_instance, int16_t x, int16_t y);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void BasicIAController_SC_OnEntry(int state, struct BasicIAController_Instance *_instance) {
switch(state) {
case BASICIACONTROLLER_SC_STATE:{
_instance->BasicIAController_SC_State = BASICIACONTROLLER_SC_FOLLOWING_STATE;
BasicIAController_SC_OnEntry(_instance->BasicIAController_SC_State, _instance);
break;
}
case BASICIACONTROLLER_SC_FOLLOWING_STATE:{
BasicIAController_send_controls_position(_instance, _instance->BasicIAController_ctrlx_var, 0);
break;
}
default: break;
}
}

// On Exit Actions:
void BasicIAController_SC_OnExit(int state, struct BasicIAController_Instance *_instance) {
switch(state) {
case BASICIACONTROLLER_SC_STATE:{
BasicIAController_SC_OnExit(_instance->BasicIAController_SC_State, _instance);
break;}
case BASICIACONTROLLER_SC_FOLLOWING_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void BasicIAController_handle_game_updateIA(struct BasicIAController_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady) {
if(!(_instance->active)) return;
//Region SC
uint8_t BasicIAController_SC_State_event_consumed = 0;
if (_instance->BasicIAController_SC_State == BASICIACONTROLLER_SC_FOLLOWING_STATE) {
if (BasicIAController_SC_State_event_consumed == 0 && 1) {
BasicIAController_SC_OnExit(BASICIACONTROLLER_SC_FOLLOWING_STATE, _instance);
_instance->BasicIAController_SC_State = BASICIACONTROLLER_SC_FOLLOWING_STATE;
if(ballx > padx + 400) {
_instance->BasicIAController_ctrlx_var = _instance->BasicIAController_ctrlx_var + 4;

} else {
if(ballx < padx - 400) {
_instance->BasicIAController_ctrlx_var = _instance->BasicIAController_ctrlx_var - 4;

}

}
if(_instance->BasicIAController_ctrlx_var <  -100) {
_instance->BasicIAController_ctrlx_var =  -100;

} else {
if(_instance->BasicIAController_ctrlx_var > 100) {
_instance->BasicIAController_ctrlx_var = 100;

}

}
BasicIAController_SC_OnEntry(BASICIACONTROLLER_SC_FOLLOWING_STATE, _instance);
BasicIAController_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}

// Observers for outgoing messages:
void (*external_BasicIAController_send_controls_position_listener)(struct BasicIAController_Instance *, int16_t, int16_t)= 0x0;
void (*BasicIAController_send_controls_position_listener)(struct BasicIAController_Instance *, int16_t, int16_t)= 0x0;
void register_external_BasicIAController_send_controls_position_listener(void (*_listener)(struct BasicIAController_Instance *, int16_t, int16_t)){
external_BasicIAController_send_controls_position_listener = _listener;
}
void register_BasicIAController_send_controls_position_listener(void (*_listener)(struct BasicIAController_Instance *, int16_t, int16_t)){
BasicIAController_send_controls_position_listener = _listener;
}
void BasicIAController_send_controls_position(struct BasicIAController_Instance *_instance, int16_t x, int16_t y){
if (BasicIAController_send_controls_position_listener != 0x0) BasicIAController_send_controls_position_listener(_instance, x, y);
if (external_BasicIAController_send_controls_position_listener != 0x0) external_BasicIAController_send_controls_position_listener(_instance, x, y);
;
}




#define MAX_INSTANCES 13
#define FIFO_SIZE 256

/*********************************
 * Instance IDs and lookup
 *********************************/

void * instances[MAX_INSTANCES];
uint16_t instances_count = 0;

void * instance_by_id(uint16_t id) {
  return instances[id];
}

uint16_t add_instance(void * instance_struct) {
  instances[instances_count] = instance_struct;
  return instances_count++;
}

/******************************************
 * Simple byte FIFO implementation
 ******************************************/

byte fifo[FIFO_SIZE];
int fifo_head = 0;
int fifo_tail = 0;

// Returns the number of byte currently in the fifo
int fifo_byte_length() {
  if (fifo_tail >= fifo_head)
    return fifo_tail - fifo_head;
  return fifo_tail + FIFO_SIZE - fifo_head;
}

// Returns the number of bytes currently available in the fifo
int fifo_byte_available() {
  return FIFO_SIZE - 1 - fifo_byte_length();
}

// Returns true if the fifo is empty
int fifo_empty() {
  return fifo_head == fifo_tail;
}

// Return true if the fifo is full
int fifo_full() {
  return fifo_head == ((fifo_tail + 1) % FIFO_SIZE);
}

// Enqueue 1 byte in the fifo if there is space
// returns 1 for sucess and 0 if the fifo was full
int fifo_enqueue(byte b) {
  int new_tail = (fifo_tail + 1) % FIFO_SIZE;
  if (new_tail == fifo_head) return 0; // the fifo is full
  fifo[fifo_tail] = b;
  fifo_tail = new_tail;
  return 1;
}

// Enqueue 1 byte in the fifo without checking for available space
// The caller should have checked that there is enough space
int _fifo_enqueue(byte b) {
  fifo[fifo_tail] = b;
  fifo_tail = (fifo_tail + 1) % FIFO_SIZE;
  return 0; // Dummy added by steffend
}

// Dequeue 1 byte in the fifo.
// The caller should check that the fifo is not empty
byte fifo_dequeue() {
  if (!fifo_empty()) {
    byte result = fifo[fifo_head];
    fifo_head = (fifo_head + 1) % FIFO_SIZE;
    return result;
  }
  return 0;
}

/*****************************************************************************
 * Implementation for type : TimerArduino
 *****************************************************************************/


// BEGIN: Code from the c_global annotation TimerArduino
uint32_t Timer_timeouts[NB_SOFT_TIMERS];
uint8_t  Timer_wraps[NB_SOFT_TIMERS];
uint32_t Timer_prev;
// END: Code from the c_global annotation TimerArduino

// Declaration of prototypes:
//Prototypes: State Machine
void TimerArduino_SoftTimer_OnExit(int state, struct TimerArduino_Instance *_instance);
//Prototypes: Message Sending
void TimerArduino_send_timer_timer_timeout(struct TimerArduino_Instance *_instance, uint8_t id);
//Prototypes: Function
uint32_t f_TimerArduino_time_ms(struct TimerArduino_Instance *_instance);
void f_TimerArduino_init_arrays(struct TimerArduino_Instance *_instance);
void f_TimerArduino_poll_soft_timers(struct TimerArduino_Instance *_instance);
void f_TimerArduino_startTimer(struct TimerArduino_Instance *_instance, uint8_t id, uint16_t delay);
void f_TimerArduino_cancel(struct TimerArduino_Instance *_instance, uint8_t id);
// Declaration of functions:
// Definition of function time_ms
uint32_t f_TimerArduino_time_ms(struct TimerArduino_Instance *_instance) {
return millis();
}
// Definition of function init_arrays
void f_TimerArduino_init_arrays(struct TimerArduino_Instance *_instance) {
uint8_t i;
	    for (i = 0; i < _instance->TimerArduino_NB_SOFT_TIMERS_var; i++) {
	        Timer_timeouts[i] = 0;
	        Timer_wraps[i] = 0;
	    }
	    Timer_prev = f_TimerArduino_time_ms(_instance);
}
// Definition of function poll_soft_timers
void f_TimerArduino_poll_soft_timers(struct TimerArduino_Instance *_instance) {
uint32_t current = f_TimerArduino_time_ms(_instance);
		uint8_t i;
		for (i = 0; i < _instance->TimerArduino_NB_SOFT_TIMERS_var; i++) {
		    if (Timer_timeouts[i] > 0) {
		        if (current >= Timer_prev) {
		            // Normal time progression
		            if (current > Timer_timeouts[i] && Timer_wraps[i] == 0) {
TimerArduino_send_timer_timer_timeout(_instance, i);
Timer_timeouts[i] = 0;
		                Timer_wraps[i] = 0;
		            }
		        } else {
		            // A wraparound has occurred
		            if (Timer_wraps[i] == 0) {
TimerArduino_send_timer_timer_timeout(_instance, i);
Timer_timeouts[i] = 0;
		            } else {
		                Timer_wraps[i] = 0;
		                if (current > Timer_timeouts[i]) {
TimerArduino_send_timer_timer_timeout(_instance, i);
Timer_timeouts[i] = 0;
		                }
		            }
		        }
		    }
		}
}
// Definition of function startTimer
void f_TimerArduino_startTimer(struct TimerArduino_Instance *_instance, uint8_t id, uint16_t delay) {

    	if (id < NB_SOFT_TIMERS) {
	        uint32_t current = f_TimerArduino_time_ms(_instance);
	        uint32_t timeout = current + delay;
	        if (timeout == 0) timeout = 1;
	
	        Timer_timeouts[id] = timeout;
	        Timer_wraps[id] = (timeout > current) ? 0 : 1;
	    }
    
}
// Definition of function cancel
void f_TimerArduino_cancel(struct TimerArduino_Instance *_instance, uint8_t id) {

        if (id < NB_SOFT_TIMERS) {
	        Timer_timeouts[id] = 0;
	        Timer_wraps[id] = 0;
	    }
      
}

// Sessions functionss:


// On Entry Actions:
void TimerArduino_SoftTimer_OnEntry(int state, struct TimerArduino_Instance *_instance) {
switch(state) {
case TIMERARDUINO_SOFTTIMER_STATE:{
_instance->TimerArduino_SoftTimer_State = TIMERARDUINO_SOFTTIMER_DEFAULT_STATE;
f_TimerArduino_init_arrays(_instance);
TimerArduino_SoftTimer_OnEntry(_instance->TimerArduino_SoftTimer_State, _instance);
break;
}
case TIMERARDUINO_SOFTTIMER_DEFAULT_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void TimerArduino_SoftTimer_OnExit(int state, struct TimerArduino_Instance *_instance) {
switch(state) {
case TIMERARDUINO_SOFTTIMER_STATE:{
TimerArduino_SoftTimer_OnExit(_instance->TimerArduino_SoftTimer_State, _instance);
break;}
case TIMERARDUINO_SOFTTIMER_DEFAULT_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void TimerArduino_handle_timer_timer_start(struct TimerArduino_Instance *_instance, uint8_t id, uint16_t time) {
if(!(_instance->active)) return;
//Region SoftTimer
uint8_t TimerArduino_SoftTimer_State_event_consumed = 0;
if (_instance->TimerArduino_SoftTimer_State == TIMERARDUINO_SOFTTIMER_DEFAULT_STATE) {
if (TimerArduino_SoftTimer_State_event_consumed == 0 && time > 0) {
f_TimerArduino_startTimer(_instance, id, time);
TimerArduino_SoftTimer_State_event_consumed = 1;
}
else if (TimerArduino_SoftTimer_State_event_consumed == 0 && time == 0) {
TimerArduino_send_timer_timer_timeout(_instance, id);
TimerArduino_SoftTimer_State_event_consumed = 1;
}
}
//End Region SoftTimer
//End dsregion SoftTimer
//Session list: 
}
void TimerArduino_handle_timer_timer_cancel(struct TimerArduino_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region SoftTimer
uint8_t TimerArduino_SoftTimer_State_event_consumed = 0;
if (_instance->TimerArduino_SoftTimer_State == TIMERARDUINO_SOFTTIMER_DEFAULT_STATE) {
if (TimerArduino_SoftTimer_State_event_consumed == 0 && 1) {
f_TimerArduino_cancel(_instance, id);
TimerArduino_SoftTimer_State_event_consumed = 1;
}
}
//End Region SoftTimer
//End dsregion SoftTimer
//Session list: 
}

// Observers for outgoing messages:
void (*external_TimerArduino_send_timer_timer_timeout_listener)(struct TimerArduino_Instance *, uint8_t)= 0x0;
void (*TimerArduino_send_timer_timer_timeout_listener)(struct TimerArduino_Instance *, uint8_t)= 0x0;
void register_external_TimerArduino_send_timer_timer_timeout_listener(void (*_listener)(struct TimerArduino_Instance *, uint8_t)){
external_TimerArduino_send_timer_timer_timeout_listener = _listener;
}
void register_TimerArduino_send_timer_timer_timeout_listener(void (*_listener)(struct TimerArduino_Instance *, uint8_t)){
TimerArduino_send_timer_timer_timeout_listener = _listener;
}
void TimerArduino_send_timer_timer_timeout(struct TimerArduino_Instance *_instance, uint8_t id){
if (TimerArduino_send_timer_timer_timeout_listener != 0x0) TimerArduino_send_timer_timer_timeout_listener(_instance, id);
if (external_TimerArduino_send_timer_timer_timeout_listener != 0x0) external_TimerArduino_send_timer_timer_timeout_listener(_instance, id);
;
}



/*****************************************************************************
 * Implementation for type : HeadlessDisplay
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void HeadlessDisplay_OnExit(int state, struct HeadlessDisplay_Instance *_instance);
//Prototypes: Message Sending
void HeadlessDisplay_send_display_displayReady(struct HeadlessDisplay_Instance *_instance);
//Prototypes: Function
void f_HeadlessDisplay_mock(struct HeadlessDisplay_Instance *_instance);
// Declaration of functions:
// Definition of function mock
void f_HeadlessDisplay_mock(struct HeadlessDisplay_Instance *_instance) {
}

// Sessions functionss:


// On Entry Actions:
void HeadlessDisplay_OnEntry(int state, struct HeadlessDisplay_Instance *_instance) {
switch(state) {
case HEADLESSDISPLAY_STATE:{
_instance->HeadlessDisplay_State = HEADLESSDISPLAY_NULL_INIT_STATE;
HeadlessDisplay_OnEntry(_instance->HeadlessDisplay_State, _instance);
break;
}
case HEADLESSDISPLAY_NULL_MOCK_STATE:{
break;
}
case HEADLESSDISPLAY_NULL_INIT_STATE:{
HeadlessDisplay_send_display_displayReady(_instance);
break;
}
default: break;
}
}

// On Exit Actions:
void HeadlessDisplay_OnExit(int state, struct HeadlessDisplay_Instance *_instance) {
switch(state) {
case HEADLESSDISPLAY_STATE:{
HeadlessDisplay_OnExit(_instance->HeadlessDisplay_State, _instance);
break;}
case HEADLESSDISPLAY_NULL_MOCK_STATE:{
break;}
case HEADLESSDISPLAY_NULL_INIT_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void HeadlessDisplay_handle_display_drawInteger(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void HeadlessDisplay_handle_display_destroy(struct HeadlessDisplay_Instance *_instance) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void HeadlessDisplay_handle_display_setColor(struct HeadlessDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void HeadlessDisplay_handle_display_setBGColor(struct HeadlessDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void HeadlessDisplay_handle_display_drawThingML(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void HeadlessDisplay_handle_display_update(struct HeadlessDisplay_Instance *_instance) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void HeadlessDisplay_handle_display_clear(struct HeadlessDisplay_Instance *_instance) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void HeadlessDisplay_handle_display_fillRect(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void HeadlessDisplay_handle_display_drawRect(struct HeadlessDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void HeadlessDisplay_handle_display_create(struct HeadlessDisplay_Instance *_instance, uint8_t xsize, uint8_t ysize) {
if(!(_instance->active)) return;
//Region null
uint8_t HeadlessDisplay_State_event_consumed = 0;
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_MOCK_STATE) {
if (HeadlessDisplay_State_event_consumed == 0 && 1) {
f_HeadlessDisplay_mock(_instance);
HeadlessDisplay_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
int HeadlessDisplay_handle_empty_event(struct HeadlessDisplay_Instance *_instance) {
 uint8_t empty_event_consumed = 0;
if(!(_instance->active)) return 0;
//Region null
if (_instance->HeadlessDisplay_State == HEADLESSDISPLAY_NULL_INIT_STATE) {
if (1) {
HeadlessDisplay_OnExit(HEADLESSDISPLAY_NULL_INIT_STATE, _instance);
_instance->HeadlessDisplay_State = HEADLESSDISPLAY_NULL_MOCK_STATE;
HeadlessDisplay_OnEntry(HEADLESSDISPLAY_NULL_MOCK_STATE, _instance);
return 1;
}
}
//begin dispatchEmptyToSession
//end dispatchEmptyToSession
return empty_event_consumed;
}

// Observers for outgoing messages:
void (*external_HeadlessDisplay_send_display_displayReady_listener)(struct HeadlessDisplay_Instance *)= 0x0;
void (*HeadlessDisplay_send_display_displayReady_listener)(struct HeadlessDisplay_Instance *)= 0x0;
void register_external_HeadlessDisplay_send_display_displayReady_listener(void (*_listener)(struct HeadlessDisplay_Instance *)){
external_HeadlessDisplay_send_display_displayReady_listener = _listener;
}
void register_HeadlessDisplay_send_display_displayReady_listener(void (*_listener)(struct HeadlessDisplay_Instance *)){
HeadlessDisplay_send_display_displayReady_listener = _listener;
}
void HeadlessDisplay_send_display_displayReady(struct HeadlessDisplay_Instance *_instance){
if (HeadlessDisplay_send_display_displayReady_listener != 0x0) HeadlessDisplay_send_display_displayReady_listener(_instance);
if (external_HeadlessDisplay_send_display_displayReady_listener != 0x0) external_HeadlessDisplay_send_display_displayReady_listener(_instance);
;
}



/*****************************************************************************
 * Implementation for type : ConsoleLogger
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void Logger_OnExit(int state, struct ConsoleLogger_Instance *_instance);
//Prototypes: Message Sending
//Prototypes: Function
void f_ConsoleLogger_do_log(struct ConsoleLogger_Instance *_instance, uint8_t* payload, uint8_t size);
// Declaration of functions:
// Definition of function do_log
void f_ConsoleLogger_do_log(struct ConsoleLogger_Instance *_instance, uint8_t* payload, uint8_t size) {
if( !(_instance->ConsoleLogger_QUIET_var)) {
uint8_t log_type = payload[0];
if(log_type == LOGTYPE_FUNCTION_CALLED) {
Serial.print("log: function_called  [");

} else {
if(log_type == LOGTYPE_PROPERTY_CHANGED) {
Serial.print("log: property_changed [");

} else {
if(log_type == LOGTYPE_MESSAGE_LOST) {
Serial.print("log: message_lost     [");

} else {
if(log_type == LOGTYPE_MESSAGE_SENT) {
Serial.print("log: message_sent     [");

} else {
if(log_type == LOGTYPE_MESSAGE_HANDLED) {
Serial.print("log: message_handled  [");

} else {
Serial.print("log: unknown          [");

}

}

}

}

}

}
uint8_t i = 0;
while(i < size) {
uint8_t v = payload[i];
if(_instance->Logger_HAS_SIGNED_BYTE_var) {
Serial.print((v & 0xFF));

} else {
Serial.print(v);

}
if( !(_instance->ConsoleLogger_QUIET_var)) {
Serial.print(",");

}
i++;

}
if( !(_instance->ConsoleLogger_QUIET_var)) {
Serial.print("]");
Serial.print("\n");

} else {
Serial.print("");
Serial.print("\n");

}
}

// Sessions functionss:


// On Entry Actions:
void Logger_OnEntry(int state, struct ConsoleLogger_Instance *_instance) {
switch(state) {
case LOGGER_STATE:{
_instance->Logger_State = LOGGER_NULL_STARTUP_STATE;
Logger_OnEntry(_instance->Logger_State, _instance);
break;
}
case LOGGER_NULL_ON_STATE:{
break;
}
case LOGGER_NULL_STARTUP_STATE:{
break;
}
case LOGGER_NULL_OFF_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void Logger_OnExit(int state, struct ConsoleLogger_Instance *_instance) {
switch(state) {
case LOGGER_STATE:{
Logger_OnExit(_instance->Logger_State, _instance);
break;}
case LOGGER_NULL_ON_STATE:{
break;}
case LOGGER_NULL_STARTUP_STATE:{
break;}
case LOGGER_NULL_OFF_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void ConsoleLogger_handle_log_log_on(struct ConsoleLogger_Instance *_instance) {
if(!(_instance->active)) return;
//Region null
uint8_t Logger_State_event_consumed = 0;
if (_instance->Logger_State == LOGGER_NULL_OFF_STATE) {
if (Logger_State_event_consumed == 0 && 1) {
Logger_OnExit(LOGGER_NULL_OFF_STATE, _instance);
_instance->Logger_State = LOGGER_NULL_ON_STATE;
Logger_OnEntry(LOGGER_NULL_ON_STATE, _instance);
Logger_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void ConsoleLogger_handle_log_log(struct ConsoleLogger_Instance *_instance, uint8_t* payload, uint8_t size) {
if(!(_instance->active)) return;
//Region null
uint8_t Logger_State_event_consumed = 0;
if (_instance->Logger_State == LOGGER_NULL_ON_STATE) {
if (Logger_State_event_consumed == 0 && 1) {
f_ConsoleLogger_do_log(_instance, payload, size);
Logger_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
void ConsoleLogger_handle_log_log_off(struct ConsoleLogger_Instance *_instance) {
if(!(_instance->active)) return;
//Region null
uint8_t Logger_State_event_consumed = 0;
if (_instance->Logger_State == LOGGER_NULL_ON_STATE) {
if (Logger_State_event_consumed == 0 && 1) {
Logger_OnExit(LOGGER_NULL_ON_STATE, _instance);
_instance->Logger_State = LOGGER_NULL_OFF_STATE;
Logger_OnEntry(LOGGER_NULL_OFF_STATE, _instance);
Logger_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}
int ConsoleLogger_handle_empty_event(struct ConsoleLogger_Instance *_instance) {
 uint8_t empty_event_consumed = 0;
if(!(_instance->active)) return 0;
//Region null
if (_instance->Logger_State == LOGGER_NULL_STARTUP_STATE) {
if (_instance->Logger_ACTIVATE_ON_STARTUP_var) {
Logger_OnExit(LOGGER_NULL_STARTUP_STATE, _instance);
_instance->Logger_State = LOGGER_NULL_ON_STATE;
Logger_OnEntry(LOGGER_NULL_ON_STATE, _instance);
return 1;
}
else if ( !(_instance->Logger_ACTIVATE_ON_STARTUP_var)) {
Logger_OnExit(LOGGER_NULL_STARTUP_STATE, _instance);
_instance->Logger_State = LOGGER_NULL_OFF_STATE;
Logger_OnEntry(LOGGER_NULL_OFF_STATE, _instance);
return 1;
}
}
//begin dispatchEmptyToSession
//end dispatchEmptyToSession
return empty_event_consumed;
}

// Observers for outgoing messages:






/*****************************************************************************
 * Definitions for configuration : test
 *****************************************************************************/

uint8_t array_game_BreakoutGame_bgcolor_var[3];
uint8_t array_game_BreakoutGame_fgcolor_var[3];
uint8_t array_game_BreakoutGame_bricks_var[5];
//Declaration of instance variables
//Instance game
// Variables for the properties of the instance
struct BreakoutGameArduino_Instance game_var;
// Variables for the sessions of the instance
//Instance disp
// Variables for the properties of the instance
struct HeadlessDisplay_Instance disp_var;
// Variables for the sessions of the instance
//Instance timer
// Variables for the properties of the instance
struct TimerArduino_Instance timer_var;
// Variables for the sessions of the instance
//Instance log
// Variables for the properties of the instance
struct ConsoleLogger_Instance log_var;
// Variables for the sessions of the instance
//Instance ctrl
// Variables for the properties of the instance
struct BasicIAController_Instance ctrl_var;
// Variables for the sessions of the instance


// Enqueue of messages BreakoutGameArduino::clock::timer_start
void enqueue_BreakoutGameArduino_send_clock_timer_start(struct BreakoutGameArduino_Instance *_instance, uint8_t id, uint16_t time){
if ( fifo_byte_available() > 7 ) {

_fifo_enqueue( (1 >> 8) & 0xFF );
_fifo_enqueue( 1 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_clock >> 8) & 0xFF );
_fifo_enqueue( _instance->id_clock & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );

// parameter time
union u_time_t {
uint16_t p;
byte bytebuffer[2];
} u_time;
u_time.p = time;
_fifo_enqueue(u_time.bytebuffer[0] & 0xFF );
_fifo_enqueue(u_time.bytebuffer[1] & 0xFF );
}
}
// Enqueue of messages BreakoutGameArduino::clock::timer_cancel
void enqueue_BreakoutGameArduino_send_clock_timer_cancel(struct BreakoutGameArduino_Instance *_instance, uint8_t id){
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_clock >> 8) & 0xFF );
_fifo_enqueue( _instance->id_clock & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages BreakoutGameArduino::ia::updateIA
void enqueue_BreakoutGameArduino_send_ia_updateIA(struct BreakoutGameArduino_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady){
if ( fifo_byte_available() > 12 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_ia >> 8) & 0xFF );
_fifo_enqueue( _instance->id_ia & 0xFF );

// parameter ballx
union u_ballx_t {
int16_t p;
byte bytebuffer[2];
} u_ballx;
u_ballx.p = ballx;
_fifo_enqueue(u_ballx.bytebuffer[0] & 0xFF );
_fifo_enqueue(u_ballx.bytebuffer[1] & 0xFF );

// parameter bally
union u_bally_t {
int16_t p;
byte bytebuffer[2];
} u_bally;
u_bally.p = bally;
_fifo_enqueue(u_bally.bytebuffer[0] & 0xFF );
_fifo_enqueue(u_bally.bytebuffer[1] & 0xFF );

// parameter padx
union u_padx_t {
int16_t p;
byte bytebuffer[2];
} u_padx;
u_padx.p = padx;
_fifo_enqueue(u_padx.bytebuffer[0] & 0xFF );
_fifo_enqueue(u_padx.bytebuffer[1] & 0xFF );

// parameter pady
union u_pady_t {
int16_t p;
byte bytebuffer[2];
} u_pady;
u_pady.p = pady;
_fifo_enqueue(u_pady.bytebuffer[0] & 0xFF );
_fifo_enqueue(u_pady.bytebuffer[1] & 0xFF );
}
}
// Enqueue of messages BreakoutGameArduino::game::lostBall
void enqueue_BreakoutGameArduino_send_game_lostBall(struct BreakoutGameArduino_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (4 >> 8) & 0xFF );
_fifo_enqueue( 4 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_game >> 8) & 0xFF );
_fifo_enqueue( _instance->id_game & 0xFF );
}
}
// Enqueue of messages BreakoutGameArduino::game::nextLevel
void enqueue_BreakoutGameArduino_send_game_nextLevel(struct BreakoutGameArduino_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (5 >> 8) & 0xFF );
_fifo_enqueue( 5 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_game >> 8) & 0xFF );
_fifo_enqueue( _instance->id_game & 0xFF );
}
}
// Enqueue of messages BreakoutGameArduino::req_game::lostBall
void enqueue_BreakoutGameArduino_send_req_game_lostBall(struct BreakoutGameArduino_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (4 >> 8) & 0xFF );
_fifo_enqueue( 4 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_req_game >> 8) & 0xFF );
_fifo_enqueue( _instance->id_req_game & 0xFF );
}
}
// Enqueue of messages BreakoutGameArduino::req_game::nextLevel
void enqueue_BreakoutGameArduino_send_req_game_nextLevel(struct BreakoutGameArduino_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (5 >> 8) & 0xFF );
_fifo_enqueue( 5 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_req_game >> 8) & 0xFF );
_fifo_enqueue( _instance->id_req_game & 0xFF );
}
}
// Enqueue of messages HeadlessDisplay::display::displayReady
void enqueue_HeadlessDisplay_send_display_displayReady(struct HeadlessDisplay_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (6 >> 8) & 0xFF );
_fifo_enqueue( 6 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_display >> 8) & 0xFF );
_fifo_enqueue( _instance->id_display & 0xFF );
}
}
// Enqueue of messages TimerArduino::timer::timer_timeout
void enqueue_TimerArduino_send_timer_timer_timeout(struct TimerArduino_Instance *_instance, uint8_t id){
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_timer >> 8) & 0xFF );
_fifo_enqueue( _instance->id_timer & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages BasicIAController::controls::position
void enqueue_BasicIAController_send_controls_position(struct BasicIAController_Instance *_instance, int16_t x, int16_t y){
if ( fifo_byte_available() > 8 ) {

_fifo_enqueue( (8 >> 8) & 0xFF );
_fifo_enqueue( 8 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_controls >> 8) & 0xFF );
_fifo_enqueue( _instance->id_controls & 0xFF );

// parameter x
union u_x_t {
int16_t p;
byte bytebuffer[2];
} u_x;
u_x.p = x;
_fifo_enqueue(u_x.bytebuffer[0] & 0xFF );
_fifo_enqueue(u_x.bytebuffer[1] & 0xFF );

// parameter y
union u_y_t {
int16_t p;
byte bytebuffer[2];
} u_y;
u_y.p = y;
_fifo_enqueue(u_y.bytebuffer[0] & 0xFF );
_fifo_enqueue(u_y.bytebuffer[1] & 0xFF );
}
}


//New dispatcher for messages
void dispatch_log_on(uint16_t sender) {
if (sender == game_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_timer_timeout(uint16_t sender, uint8_t param_id) {
if (sender == timer_var.id_timer) {
BreakoutGameArduino_handle_clock_timer_timeout(&game_var, param_id);

}
if (sender == game_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_setBGColor(uint16_t sender, uint8_t param_r, uint8_t param_g, uint8_t param_b) {
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_setBGColor(&disp_var, param_r, param_g, param_b);

}
if (sender == game_var.id_game) {

}

}

void sync_dispatch_BreakoutGameArduino_send_display_setBGColor(struct BreakoutGameArduino_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
dispatch_setBGColor(_instance->id_display, r, g, b);
}

//New dispatcher for messages
void dispatch_log(uint16_t sender, uint8_t* param_payload, uint8_t param_size) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_log) {
ConsoleLogger_handle_log_log(&log_var, param_payload, param_size);

}

}

void sync_dispatch_BreakoutGameArduino_send_log_log(struct BreakoutGameArduino_Instance *_instance, uint8_t* payload, uint8_t size){
dispatch_log(_instance->id_log, payload, size);
}

//New dispatcher for messages
void dispatch_velocity(uint16_t sender, int16_t param_dx, int16_t param_dy) {
if (sender == game_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_nextLevel(uint16_t sender) {
if (sender == game_var.id_req_game) {
BreakoutGameArduino_handle_pro_game_nextLevel(&game_var);

}
if (sender == game_var.id_game) {
BreakoutGameArduino_handle_game_nextLevel(&game_var);

}

}


//New dispatcher for messages
void dispatch_lostBall(uint16_t sender) {
if (sender == game_var.id_req_game) {
BreakoutGameArduino_handle_pro_game_lostBall(&game_var);

}
if (sender == game_var.id_game) {
BreakoutGameArduino_handle_game_lostBall(&game_var);

}

}


//New dispatcher for messages
void dispatch_drawInteger(uint16_t sender, uint8_t param_x, uint8_t param_y, int16_t param_v, uint8_t param_digits, uint8_t param_scale) {
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_drawInteger(&disp_var, param_x, param_y, param_v, param_digits, param_scale);

}
if (sender == game_var.id_game) {

}

}

void sync_dispatch_BreakoutGameArduino_send_display_drawInteger(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale){
dispatch_drawInteger(_instance->id_display, x, y, v, digits, scale);
}

//New dispatcher for messages
void dispatch_position(uint16_t sender, int16_t param_x, int16_t param_y) {
if (sender == game_var.id_game) {

}
if (sender == ctrl_var.id_controls) {
BreakoutGameArduino_handle_controller_position(&game_var, param_x, param_y);

}

}


//New dispatcher for messages
void dispatch_updateIA(uint16_t sender, int16_t param_ballx, int16_t param_bally, int16_t param_padx, int16_t param_pady) {
if (sender == game_var.id_ia) {
BasicIAController_handle_game_updateIA(&ctrl_var, param_ballx, param_bally, param_padx, param_pady);

}
if (sender == game_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_destroy(uint16_t sender) {
if (sender == game_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_displayReady(uint16_t sender) {
if (sender == disp_var.id_display) {
BreakoutGameArduino_handle_display_displayReady(&game_var);

}
if (sender == game_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_setColor(uint16_t sender, uint8_t param_r, uint8_t param_g, uint8_t param_b) {
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_setColor(&disp_var, param_r, param_g, param_b);

}
if (sender == game_var.id_game) {

}

}

void sync_dispatch_BreakoutGameArduino_send_display_setColor(struct BreakoutGameArduino_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
dispatch_setColor(_instance->id_display, r, g, b);
}

//New dispatcher for messages
void dispatch_drawThingML(uint16_t sender, uint8_t param_x, uint8_t param_y) {
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_drawThingML(&disp_var, param_x, param_y);

}
if (sender == game_var.id_game) {

}

}

void sync_dispatch_BreakoutGameArduino_send_display_drawThingML(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y){
dispatch_drawThingML(_instance->id_display, x, y);
}

//New dispatcher for messages
void dispatch_clear(uint16_t sender) {
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_clear(&disp_var);

}
if (sender == game_var.id_game) {

}

}

void sync_dispatch_BreakoutGameArduino_send_display_clear(struct BreakoutGameArduino_Instance *_instance){
dispatch_clear(_instance->id_display);
}

//New dispatcher for messages
void dispatch_update(uint16_t sender) {
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_update(&disp_var);

}
if (sender == game_var.id_game) {

}

}

void sync_dispatch_BreakoutGameArduino_send_display_update(struct BreakoutGameArduino_Instance *_instance){
dispatch_update(_instance->id_display);
}

//New dispatcher for messages
void dispatch_fillRect(uint16_t sender, uint8_t param_x, uint8_t param_y, uint8_t param_width, uint8_t param_height) {
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_fillRect(&disp_var, param_x, param_y, param_width, param_height);

}
if (sender == game_var.id_game) {

}

}

void sync_dispatch_BreakoutGameArduino_send_display_fillRect(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
dispatch_fillRect(_instance->id_display, x, y, width, height);
}

//New dispatcher for messages
void dispatch_timer_start(uint16_t sender, uint8_t param_id, uint16_t param_time) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_clock) {
TimerArduino_handle_timer_timer_start(&timer_var, param_id, param_time);

}

}


//New dispatcher for messages
void dispatch_drawRect(uint16_t sender, uint8_t param_x, uint8_t param_y, uint8_t param_width, uint8_t param_height) {
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_drawRect(&disp_var, param_x, param_y, param_width, param_height);

}
if (sender == game_var.id_game) {

}

}

void sync_dispatch_BreakoutGameArduino_send_display_drawRect(struct BreakoutGameArduino_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
dispatch_drawRect(_instance->id_display, x, y, width, height);
}

//New dispatcher for messages
void dispatch_log_off(uint16_t sender) {
if (sender == game_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_timer_cancel(uint16_t sender, uint8_t param_id) {
if (sender == game_var.id_game) {

}
if (sender == game_var.id_clock) {
TimerArduino_handle_timer_timer_cancel(&timer_var, param_id);

}

}


//New dispatcher for messages
void dispatch_create(uint16_t sender, uint8_t param_xsize, uint8_t param_ysize) {
if (sender == game_var.id_display) {
HeadlessDisplay_handle_display_create(&disp_var, param_xsize, param_ysize);

}
if (sender == game_var.id_game) {

}

}

void sync_dispatch_BreakoutGameArduino_send_display_create(struct BreakoutGameArduino_Instance *_instance, uint8_t xsize, uint8_t ysize){
dispatch_create(_instance->id_display, xsize, ysize);
}

int processMessageQueue() {
if (fifo_empty()) return 0; // return 0 if there is nothing to do

uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 4:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_lostBall = 2;
dispatch_lostBall((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 3:{
byte mbuf[12 - 2];
while (mbufi < (12 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_updateIA = 2;
union u_updateIA_ballx_t {
int16_t p;
byte bytebuffer[2];
} u_updateIA_ballx;
u_updateIA_ballx.bytebuffer[0] = mbuf[mbufi_updateIA + 0];
u_updateIA_ballx.bytebuffer[1] = mbuf[mbufi_updateIA + 1];
mbufi_updateIA += 2;
union u_updateIA_bally_t {
int16_t p;
byte bytebuffer[2];
} u_updateIA_bally;
u_updateIA_bally.bytebuffer[0] = mbuf[mbufi_updateIA + 0];
u_updateIA_bally.bytebuffer[1] = mbuf[mbufi_updateIA + 1];
mbufi_updateIA += 2;
union u_updateIA_padx_t {
int16_t p;
byte bytebuffer[2];
} u_updateIA_padx;
u_updateIA_padx.bytebuffer[0] = mbuf[mbufi_updateIA + 0];
u_updateIA_padx.bytebuffer[1] = mbuf[mbufi_updateIA + 1];
mbufi_updateIA += 2;
union u_updateIA_pady_t {
int16_t p;
byte bytebuffer[2];
} u_updateIA_pady;
u_updateIA_pady.bytebuffer[0] = mbuf[mbufi_updateIA + 0];
u_updateIA_pady.bytebuffer[1] = mbuf[mbufi_updateIA + 1];
mbufi_updateIA += 2;
dispatch_updateIA((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_updateIA_ballx.p /* ballx */ ,
 u_updateIA_bally.p /* bally */ ,
 u_updateIA_padx.p /* padx */ ,
 u_updateIA_pady.p /* pady */ );
break;
}
case 7:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_timer_timeout = 2;
union u_timer_timeout_id_t {
uint8_t p;
byte bytebuffer[1];
} u_timer_timeout_id;
u_timer_timeout_id.bytebuffer[0] = mbuf[mbufi_timer_timeout + 0];
mbufi_timer_timeout += 1;
dispatch_timer_timeout((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_timer_timeout_id.p /* id */ );
break;
}
case 8:{
byte mbuf[8 - 2];
while (mbufi < (8 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_position = 2;
union u_position_x_t {
int16_t p;
byte bytebuffer[2];
} u_position_x;
u_position_x.bytebuffer[0] = mbuf[mbufi_position + 0];
u_position_x.bytebuffer[1] = mbuf[mbufi_position + 1];
mbufi_position += 2;
union u_position_y_t {
int16_t p;
byte bytebuffer[2];
} u_position_y;
u_position_y.bytebuffer[0] = mbuf[mbufi_position + 0];
u_position_y.bytebuffer[1] = mbuf[mbufi_position + 1];
mbufi_position += 2;
dispatch_position((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_position_x.p /* x */ ,
 u_position_y.p /* y */ );
break;
}
case 6:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_displayReady = 2;
dispatch_displayReady((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 5:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_nextLevel = 2;
dispatch_nextLevel((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 1:{
byte mbuf[7 - 2];
while (mbufi < (7 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_timer_start = 2;
union u_timer_start_id_t {
uint8_t p;
byte bytebuffer[1];
} u_timer_start_id;
u_timer_start_id.bytebuffer[0] = mbuf[mbufi_timer_start + 0];
mbufi_timer_start += 1;
union u_timer_start_time_t {
uint16_t p;
byte bytebuffer[2];
} u_timer_start_time;
u_timer_start_time.bytebuffer[0] = mbuf[mbufi_timer_start + 0];
u_timer_start_time.bytebuffer[1] = mbuf[mbufi_timer_start + 1];
mbufi_timer_start += 2;
dispatch_timer_start((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_timer_start_id.p /* id */ ,
 u_timer_start_time.p /* time */ );
break;
}
case 2:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_timer_cancel = 2;
union u_timer_cancel_id_t {
uint8_t p;
byte bytebuffer[1];
} u_timer_cancel_id;
u_timer_cancel_id.bytebuffer[0] = mbuf[mbufi_timer_cancel + 0];
mbufi_timer_cancel += 1;
dispatch_timer_cancel((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_timer_cancel_id.p /* id */ );
break;
}
}
return 1;
}


//external Message enqueue

void initialize_configuration_test() {
// Initialize connectors
register_BreakoutGameArduino_send_log_log_listener(&sync_dispatch_BreakoutGameArduino_send_log_log);
register_BreakoutGameArduino_send_clock_timer_start_listener(&enqueue_BreakoutGameArduino_send_clock_timer_start);
register_BreakoutGameArduino_send_clock_timer_cancel_listener(&enqueue_BreakoutGameArduino_send_clock_timer_cancel);
register_BreakoutGameArduino_send_display_drawInteger_listener(&sync_dispatch_BreakoutGameArduino_send_display_drawInteger);
register_BreakoutGameArduino_send_display_setColor_listener(&sync_dispatch_BreakoutGameArduino_send_display_setColor);
register_BreakoutGameArduino_send_display_setBGColor_listener(&sync_dispatch_BreakoutGameArduino_send_display_setBGColor);
register_BreakoutGameArduino_send_display_drawThingML_listener(&sync_dispatch_BreakoutGameArduino_send_display_drawThingML);
register_BreakoutGameArduino_send_display_clear_listener(&sync_dispatch_BreakoutGameArduino_send_display_clear);
register_BreakoutGameArduino_send_display_update_listener(&sync_dispatch_BreakoutGameArduino_send_display_update);
register_BreakoutGameArduino_send_display_fillRect_listener(&sync_dispatch_BreakoutGameArduino_send_display_fillRect);
register_BreakoutGameArduino_send_display_drawRect_listener(&sync_dispatch_BreakoutGameArduino_send_display_drawRect);
register_BreakoutGameArduino_send_display_create_listener(&sync_dispatch_BreakoutGameArduino_send_display_create);
register_BreakoutGameArduino_send_ia_updateIA_listener(&enqueue_BreakoutGameArduino_send_ia_updateIA);
register_BreakoutGameArduino_send_req_game_lostBall_listener(&enqueue_BreakoutGameArduino_send_req_game_lostBall);
register_BreakoutGameArduino_send_req_game_nextLevel_listener(&enqueue_BreakoutGameArduino_send_req_game_nextLevel);
register_HeadlessDisplay_send_display_displayReady_listener(&enqueue_HeadlessDisplay_send_display_displayReady);
register_TimerArduino_send_timer_timer_timeout_listener(&enqueue_TimerArduino_send_timer_timer_timeout);
register_BasicIAController_send_controls_position_listener(&enqueue_BasicIAController_send_controls_position);


// Network Initialization
// End Network Initialization

// Init the ID, state variables and properties for instance timer
timer_var.active = true;
timer_var.id_timer = add_instance( (void*) &timer_var);
timer_var.TimerArduino_SoftTimer_State = TIMERARDUINO_SOFTTIMER_DEFAULT_STATE;
timer_var.TimerArduino_NB_SOFT_TIMERS_var = NB_SOFT_TIMERS;

TimerArduino_SoftTimer_OnEntry(TIMERARDUINO_SOFTTIMER_STATE, &timer_var);
// Init the ID, state variables and properties for instance log
log_var.active = true;
log_var.id_log = add_instance( (void*) &log_var);
log_var.Logger_State = LOGGER_NULL_STARTUP_STATE;
log_var.Logger_HAS_SIGNED_BYTE_var = 0;
log_var.Logger_ACTIVATE_ON_STARTUP_var = 0;
log_var.ConsoleLogger_QUIET_var = 1;

Logger_OnEntry(LOGGER_STATE, &log_var);
// Init the ID, state variables and properties for instance disp
disp_var.active = true;
disp_var.id_display = add_instance( (void*) &disp_var);
disp_var.HeadlessDisplay_State = HEADLESSDISPLAY_NULL_INIT_STATE;

HeadlessDisplay_OnEntry(HEADLESSDISPLAY_STATE, &disp_var);
// Init the ID, state variables and properties for instance ctrl
ctrl_var.active = true;
ctrl_var.id_controls = add_instance( (void*) &ctrl_var);
ctrl_var.id_game = add_instance( (void*) &ctrl_var);
ctrl_var.BasicIAController_SC_State = BASICIACONTROLLER_SC_FOLLOWING_STATE;
ctrl_var.BasicIAController_ctrlx_var = 0;

BasicIAController_SC_OnEntry(BASICIACONTROLLER_SC_STATE, &ctrl_var);
// Init the ID, state variables and properties for instance game
game_var.active = true;
game_var.id_log = add_instance( (void*) &game_var);
game_var.id_clock = add_instance( (void*) &game_var);
game_var.id_display = add_instance( (void*) &game_var);
game_var.id_controller = add_instance( (void*) &game_var);
game_var.id_ia = add_instance( (void*) &game_var);
game_var.id_game = add_instance( (void*) &game_var);
game_var.id_req_game = add_instance( (void*) &game_var);
game_var.id_pro_game = add_instance( (void*) &game_var);
game_var.BreakoutGame_SC_State = BREAKOUTGAME_SC_INIT_STATE;
game_var.BreakoutGame_prevBX_var =  -1;
game_var.BreakoutGame_SCALE_var = 64;
game_var.BreakoutGame_pady_var = 128 * 64 - 6 * 64;
game_var.BreakoutGame_padlen_var = 25 * 64;
game_var.BreakoutGame_dy_var =  -160 * 64 / 65;
game_var.BreakoutGame_period_var = 3;
game_var.BreakoutGame_score_var = 0;
game_var.BreakoutGame_BOTTOM_var = 128 * 64 + 8 * 64;
game_var.BreakoutGame_br_var = 3 * 64;
game_var.BreakoutGame_RIGHT_var = 160 * 64 - 1 * 64;
game_var.BreakoutGame_TOP_var = 14 * 64;
game_var.BreakoutGame_padx_var = 128 * 64 / 2;
game_var.BreakoutGame_LEFT_var = 1 * 64;
game_var.BreakoutGame_level_var = 1;
game_var.BreakoutGame_by_var = 128 * 64;
game_var.BreakoutGame_prevPX_var =  -1;
game_var.BreakoutGame_prevBY_var =  -1;
game_var.BreakoutGame_lives_var = 3;
game_var.BreakoutGame_XDISPSIZE_var = 160;
game_var.BreakoutGame_QUIET_var = 1;
game_var.BreakoutGame_dx_var = 160 * 64 / 98;
game_var.BreakoutGameArduino_RAM_SIZE_var = 98304;
game_var.BreakoutGame_YMAX_var = 128 * 64;
game_var.BreakoutGame_XMAX_var = 160 * 64;
game_var.BreakoutGame_BRICK_ROWS_var = 5;
game_var.BreakoutGame_YDISPSIZE_var = 128;
game_var.BreakoutGame_bx_var = 160 * 64 / 2;
game_var.BreakoutGame_counter_var = 0;
game_var.BreakoutGame_lastTimestamp_var = 0;
game_var.BreakoutGame_prevPY_var =  -1;
game_var.BreakoutGame_BRICK_HEIGHT_var = 9;
game_var.WithBinaryLog_DEBUG_BIN_ID_var = 0;
game_var.BreakoutGame_bgcolor_var = array_game_BreakoutGame_bgcolor_var;
game_var.BreakoutGame_bgcolor_var_size = 3;
game_var.BreakoutGame_fgcolor_var = array_game_BreakoutGame_fgcolor_var;
game_var.BreakoutGame_fgcolor_var_size = 3;
game_var.BreakoutGame_bricks_var = array_game_BreakoutGame_bricks_var;
game_var.BreakoutGame_bricks_var_size = 5;

BreakoutGame_SC_OnEntry(BREAKOUTGAME_SC_STATE, &game_var);
}




void setup() {
Serial.begin(250000);
initialize_configuration_test();

}

void loop() {

// Network Listener// End Network Listener

int emptyEventConsumed = 1;
while (emptyEventConsumed != 0) {
emptyEventConsumed = 0;
emptyEventConsumed += HeadlessDisplay_handle_empty_event(&disp_var);
emptyEventConsumed += ConsoleLogger_handle_empty_event(&log_var);
}
f_TimerArduino_poll_soft_timers(&timer_var);

    processMessageQueue();
}
