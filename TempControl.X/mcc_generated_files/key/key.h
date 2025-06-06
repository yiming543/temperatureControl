#ifndef KEY_H
#define KEY_H

//#include <climits>
extern unsigned long milliseconds;
extern unsigned char SW1_STATUS;

extern void key_debounce(void);
unsigned long get_time_ms(void);

#define SHORT_PRESS_THRESHOLD 50 // 短按閾值 (毫秒)
#define LONG_PRESS_THRESHOLD 1000  // 長按閾值 (毫秒)
#define RELEASE_THRESHOLD 50  // 放開閾值 (毫秒)

enum KeyState {
    KEY_STATE_RELEASE,
    KEY_STATE_SHORT_PRESS,
    KEY_STATE_LONG_PRESS
};

#define KEY_PRESS 0
#define KEY_RELEASE 1   


#endif // KEY_H