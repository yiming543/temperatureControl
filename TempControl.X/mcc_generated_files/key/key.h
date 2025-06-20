#ifndef KEY_H
#define KEY_H

#include <stdint.h>
#include "../../TempControl.h"

extern unsigned long milliSeconds;
extern uint8_t SW1_Status;
extern uint8_t SW2_Status;
extern uint8_t SW3_Status;

extern uint8_t tempCnt;
extern uint8_t tempCnt1;

extern void getKeyStatus(void);
extern unsigned long getTime_ms(void);

void keyDebounce(void);
void chkeckPressKeyNumber(void);

#define SHORT_PRESS_THRESHOLD_TIME 50  // 短按閾值 (毫秒)
#define LONG_PRESS_THRESHOLD_TIME 1000 // 長按閾值 (毫秒)
#define LONG_PRESS_QUICK_TIME 100      // 長按時每隔250增加1 (毫秒)
#define RELEASE_THRESHOLD_TIME 50      // 放開閾值 (毫秒)
#define KEY_RELEASE_TIME 5000          // 5000ms(default) 多久沒按下按鍵? (毫秒)

#define TEMP_MAX 99 // 99度C
#define TEMP_MIN 1  // 1度C

enum KeyState {
  KEY_STATE_RELEASE,
  KEY_STATE_SHORT_PRESS,
  KEY_STATE_LONG_PRESS
};

#define KEY_PRESS 0
#define KEY_RELEASE 1

#endif // KEY_H