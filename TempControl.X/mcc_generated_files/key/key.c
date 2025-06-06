/*
 * File:   key.c
 * Author:
 *
 * Created on 2019/11/25, 下午 04:15
 */

#include "key.h"
#include "../mcc.h"

extern unsigned char flag_Key_release;  //1:release 0:press

unsigned long get_time_ms(void) {
  return milliseconds; // 返回經過的毫秒數
}

unsigned char SW1_STATUS = KEY_STATE_RELEASE;

void key_debounce(void) {
  static long previous_time;
  static unsigned char sw1_previous_state = KEY_RELEASE;
  unsigned char sw1_current_state;
  ;
  unsigned long current_time = get_time_ms();

  if (SW1_GetValue() == KEY_PRESS) {
    sw1_current_state = KEY_PRESS;
    if (sw1_previous_state != sw1_current_state) {
      previous_time = current_time;
      sw1_previous_state = sw1_current_state;
    } else {
      if (current_time - previous_time > LONG_PRESS_THRESHOLD) {
        SW1_STATUS = KEY_STATE_LONG_PRESS;
      } else if (current_time - previous_time > SHORT_PRESS_THRESHOLD) {
        SW1_STATUS = KEY_STATE_SHORT_PRESS;
      }
    }
  } else {
    sw1_current_state = KEY_RELEASE;
    if (sw1_previous_state != sw1_current_state) {
      previous_time = current_time;
      sw1_previous_state = sw1_current_state;
    } else {
      if (current_time - previous_time > RELEASE_THRESHOLD) {
        SW1_STATUS = KEY_STATE_RELEASE;
        flag_Key_release = KEY_RELEASE;
      }
    }
  }
}