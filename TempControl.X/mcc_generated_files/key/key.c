/*
 * File:   key.c
 * Author:
 *
 * Created on 2019/11/25, 下午 04:15
 */

#include "key.h"
#include "../mcc.h"
#include <limits.h>
#include <stdint.h>

extern uint8_t displayMode;
extern uint8_t temperature_SET1;
extern uint8_t temperature_SET2;

uint8_t SW1_Status = KEY_STATE_RELEASE;
uint8_t SW2_Status = KEY_STATE_RELEASE;
uint8_t SW3_Status = KEY_STATE_RELEASE;

uint8_t fKeyRelease_SW1 = KEY_RELEASE; // 1:release 0:press
uint8_t fKeyRelease_SW2 = KEY_RELEASE; // 1:release 0:press
uint8_t fKeyRelease_SW3 = KEY_RELEASE; // 1:release 0:press
// uint32_t SW1_LongPressTime = LONG_MAX;
uint32_t SW2_LongPressTime = LONG_MAX;
uint32_t SW3_LongPressTime = LONG_MAX;
uint32_t longPressCurrentTime;

uint8_t fTooManyKeyPress = 0;
uint8_t fNoKeyPress = 0;
uint8_t fNoKeyPressOverTime = 0;

void keyDebounce(void) {
  static uint32_t SW1_PreviousTime;
  uint8_t SW1_CurrentState;
  static uint8_t SW1_PreviousState = KEY_RELEASE;

  static uint32_t SW2_PreviousTime;
  uint8_t SW2_CurrentState;
  static uint8_t SW2_PreviousState = KEY_RELEASE;

  static uint32_t SW3_PreviousTime;
  uint8_t SW3_CurrentState;
  static uint8_t SW3_PreviousState = KEY_RELEASE;

  uint32_t CurrentTime = getTime_ms();

  // 讀取目前按鍵狀態
  SW1_CurrentState = SW1_GetValue();
  SW2_CurrentState = SW2_GetValue();
  SW3_CurrentState = SW3_GetValue();

  // 按鍵1
  if (SW1_CurrentState == KEY_PRESS) {
    // 按下按鍵的情況
    if (SW1_PreviousState != SW1_CurrentState) {
      // 信號有變化 更新狀態和時間
      SW1_PreviousTime = CurrentTime;
      SW1_PreviousState = SW1_CurrentState;
    } else {
      // 持續按鍵 計算時間
      if (CurrentTime - SW1_PreviousTime > LONG_PRESS_THRESHOLD_TIME) {
        SW1_Status = KEY_STATE_LONG_PRESS;
      } else if (CurrentTime - SW1_PreviousTime > SHORT_PRESS_THRESHOLD_TIME) {
        SW1_Status = KEY_STATE_SHORT_PRESS;
      }
    }
  } else {
    // 放開按鍵的情況
    SW1_CurrentState = KEY_RELEASE;
    if (SW1_PreviousState != SW1_CurrentState) {
      // 信號有變化 更新狀態和時間
      SW1_PreviousTime = CurrentTime;
      SW1_PreviousState = SW1_CurrentState;
    } else {
      if (CurrentTime - SW1_PreviousTime > RELEASE_THRESHOLD_TIME) {
        SW1_Status = KEY_STATE_RELEASE;
        fKeyRelease_SW1 = KEY_RELEASE;
      }
    }
  }

  // 按鍵2
  if (SW2_CurrentState == KEY_PRESS) {
    // 按下按鍵的情況
    if (SW2_PreviousState != SW2_CurrentState) {
      // 信號有變化 更新狀態和時間
      SW2_PreviousTime = CurrentTime;
      SW2_PreviousState = SW2_CurrentState;
    } else {
      // 持續按鍵 計算時間
      if (CurrentTime - SW2_PreviousTime > LONG_PRESS_THRESHOLD_TIME) {
        SW2_Status = KEY_STATE_LONG_PRESS;
      } else if (CurrentTime - SW2_PreviousTime > SHORT_PRESS_THRESHOLD_TIME) {
        SW2_Status = KEY_STATE_SHORT_PRESS;
      }
    }
  } else {
    // 放開按鍵的情況
    SW2_CurrentState = KEY_RELEASE;
    if (SW2_PreviousState != SW2_CurrentState) {
      // 信號有變化 更新狀態和時間
      SW2_PreviousTime = CurrentTime;
      SW2_PreviousState = SW2_CurrentState;
    } else {
      if (CurrentTime - SW2_PreviousTime > RELEASE_THRESHOLD_TIME) {
        SW2_Status = KEY_STATE_RELEASE;
        fKeyRelease_SW2 = KEY_RELEASE;
      }
    }
  }

  // 按鍵3
  if (SW3_CurrentState == KEY_PRESS) {
    // 按下按鍵的情況
    if (SW3_PreviousState != SW3_CurrentState) {
      // 信號有變化 更新狀態和時間
      SW3_PreviousTime = CurrentTime;
      SW3_PreviousState = SW3_CurrentState;
    } else {
      // 持續按鍵 計算時間
      if (CurrentTime - SW3_PreviousTime > LONG_PRESS_THRESHOLD_TIME) {
        SW3_Status = KEY_STATE_LONG_PRESS;
      } else if (CurrentTime - SW3_PreviousTime > SHORT_PRESS_THRESHOLD_TIME) {
        SW3_Status = KEY_STATE_SHORT_PRESS;
      }
    }
  } else {
    // 放開按鍵的情況
    SW3_CurrentState = KEY_RELEASE;
    if (SW3_PreviousState != SW3_CurrentState) {
      // 信號有變化 更新狀態和時間
      SW3_PreviousTime = CurrentTime;
      SW3_PreviousState = SW3_CurrentState;
    } else {
      if (CurrentTime - SW3_PreviousTime > RELEASE_THRESHOLD_TIME) {
        SW3_Status = KEY_STATE_RELEASE;
        fKeyRelease_SW3 = KEY_RELEASE;
      }
    }
  }
}

void chkeckPressKeyNumber(void) {
  uint8_t keyCnt = 0;
  static uint32_t KeyPressTime = UINT32_MAX;
  uint32_t CurrentTime = getTime_ms();

  if ((SW1_Status == KEY_STATE_SHORT_PRESS) ||
      (SW1_Status == KEY_STATE_LONG_PRESS)) {
    keyCnt++;
    KeyPressTime = CurrentTime;
    fNoKeyPress = 0;
    fNoKeyPressOverTime = 0;
  }
  if ((SW2_Status == KEY_STATE_SHORT_PRESS) ||
      (SW2_Status == KEY_STATE_LONG_PRESS)) {
    keyCnt++;
    KeyPressTime = CurrentTime;
    fNoKeyPress = 0;
    fNoKeyPressOverTime = 0;
  }
  if ((SW3_Status == KEY_STATE_SHORT_PRESS) ||
      (SW3_Status == KEY_STATE_LONG_PRESS)) {
    keyCnt++;
    KeyPressTime = CurrentTime;
    fNoKeyPress = 0;
    fNoKeyPressOverTime = 0;
  }

  // 超過2個按鍵同時按下
  if (keyCnt > 1) {
    fTooManyKeyPress = 1;
  } else {
    fTooManyKeyPress = 0;
  }

  // 若沒有按鍵，超過時間顯示溫度
  if (keyCnt == 0) {
    fNoKeyPress = 1;
    if (CurrentTime - KeyPressTime > KEY_RELEASE_TIME) {
      fNoKeyPressOverTime = 1;
      KeyPressTime = CurrentTime;
    }
  } else {
    fNoKeyPress = 0;
    fNoKeyPressOverTime = 0;
  }
}

void getKeyStatus(void) {
  // 按鍵狀態
  uint8_t tempMode = displayMode;
  uint8_t tempCnt;
  if (displayMode == DISPLAY_MODE_TEMPERATURE_SET1) {
    tempCnt = temperature_SET1;
  } else if (displayMode == DISPLAY_MODE_TEMPERATURE_SET2) {
    tempCnt = temperature_SET2;
  }

  SW1_Status = KEY_STATE_RELEASE;
  SW2_Status = KEY_STATE_RELEASE;
  SW3_Status = KEY_STATE_RELEASE;
  keyDebounce();
  longPressCurrentTime = getTime_ms();
  chkeckPressKeyNumber();

  // 同時按2個按鍵,不動作
  if (fTooManyKeyPress == 0) {

    // SW1 Short Press
    if ((SW1_Status == KEY_STATE_SHORT_PRESS) &&
        (fKeyRelease_SW1 == KEY_RELEASE)) {
      tempMode++;
      if (tempMode > 2) {
        tempMode = 0;
      }
      fKeyRelease_SW1 = 0;
    }

    // SW2 Short Press
    if ((SW2_Status == KEY_STATE_SHORT_PRESS) &&
        (fKeyRelease_SW2 == KEY_RELEASE)) {
      if (tempCnt < TEMP_MAX) {
        tempCnt++;
      }
      fKeyRelease_SW2 = 0;
    }

    // SW2 Long Press
    if (SW2_Status == KEY_STATE_LONG_PRESS) {
      if (longPressCurrentTime - SW2_LongPressTime > LONG_PRESS_QUICK_TIME) {
        if (tempCnt < TEMP_MAX) {
          tempCnt++;
        }
        SW2_LongPressTime = longPressCurrentTime;
      }
    }

    if ((SW3_Status == KEY_STATE_SHORT_PRESS) &&
        (fKeyRelease_SW3 == KEY_RELEASE)) {
      if (tempCnt > TEMP_MIN) {
        tempCnt--;
      }
      fKeyRelease_SW3 = 0;
    }

    // SW3 Long Press
    if (SW3_Status == KEY_STATE_LONG_PRESS) {
      if (longPressCurrentTime - SW3_LongPressTime > LONG_PRESS_QUICK_TIME) {
        if (tempCnt > TEMP_MIN) {
          tempCnt--;
        }
        SW3_LongPressTime = longPressCurrentTime;
      }
    }

    if (fNoKeyPress == 1) {
      // 沒按鍵
      fNoKeyPress = 0;
      if (fNoKeyPressOverTime == 1) {
        // 沒按鍵超過時間 顯示溫度
        fNoKeyPressOverTime = 0;
        displayMode = DISPLAY_MODE_TEMPERATURE;
      }
    } else {
      // 有按鍵
      if (displayMode != tempMode) {
        // 按下SW1
        displayMode = tempMode;
      } else {
        // 按下SW2 或 SW3
        if (displayMode == DISPLAY_MODE_TEMPERATURE_SET1) {
          temperature_SET1 = tempCnt;
        } else if (displayMode == DISPLAY_MODE_TEMPERATURE_SET2) {
          temperature_SET2 = tempCnt;
        }
      }
    }
  }
}

uint32_t getTime_ms(void) {
  return milliSeconds; // 返回經過的毫秒數
}