
#include <driver/timer.h>

////////////////////////////////
//         Blinker            //
////////////////////////////////

class Blinker {
  
  timer_group_t group;
  timer_idx_t idx;
  int pin;

  int nBlinks;
  int onTime;
  int offTime;
  int delayTime;
  int count;

  static void isrTimer(void *arg); 

  public:

  Blinker(int pin, int timerNum=0);

//  Creates a generic blinking LED on specified PIN controlled
//  in background via interrupts generated by an ESP32 Alarm Timer.
//
//  pin:         Pin mumber to control.  Blinker will set pinMode to OUTPUT automatically 
//  timerNum:    ESP32 Alarm Timer to use. 0=Group0/Timer0, 1=Group0/Timer1, 2=Group1/Timer0, 3=Group1/Timer1
    
  void start(int period, float dutyCycle=0.5);
    
//    Starts simple ON/OFF blinking.
//
//    period:      ON/OFF blinking period, in milliseconds
//    dutyCycle:   Fraction of period that LED is ON (default=50%)

  void start(int period, float dutyCycle, int nBlinks, int delayTime);

//    Starts ON/OFF blinking pattern.
//
//    period:      ON/OFF blinking period, in milliseconds, used for blinking portion of pattern
//    dutyCycle:   Fraction of period that LED is ON (default=50%)
//    nBlinks:     Number of blinks in blinking portion of pattern
//    delayTime:   delay, in milliseconds, during which LED is off before restarting blinking pattern


  void stop();

//    Stops current blinking pattern.

  void on();

//    Stops current blinknig pattern and turns on LED

  void off();

//    Stops current blinknig pattern and turns off LED

};
