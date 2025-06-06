#ifndef KEY_H
#define KEY_H

// #include <climits>
extern unsigned long milliSeconds;
extern unsigned char SW1_Status;
extern unsigned char SW2_Status;
extern unsigned char SW3_Status;

extern void keyDebounce(void);
extern unsigned long getTime_ms(void);

#define SHORT_PRESS_THRESHOLD_TIME 50  // 短按閾值 (毫秒)
#define LONG_PRESS_THRESHOLD_TIME 1000 // 長按閾值 (毫秒)
#define LONG_PRESS_QUICK_TIME 100      // 長按時每隔250增加1 (毫秒)
#define RELEASE_THRESHOLD_TIME 50      // 放開閾值 (毫秒)

enum KeyState {
  KEY_STATE_RELEASE,
  KEY_STATE_SHORT_PRESS,
  KEY_STATE_LONG_PRESS
};

#define KEY_PRESS 0
#define KEY_RELEASE 1

#endif // KEY_H