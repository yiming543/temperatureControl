/*
 * File:   key.c
 * Author:
 *
 * Created on 2019/11/25, 下午 04:15
 */

#include "key.h"
#include "../mcc.h"

extern unsigned char fKeyRelease_SW1;  //1:release 0:press
extern unsigned char fKeyRelease_SW2;  //1:release 0:press
extern unsigned char fKeyRelease_SW3;  //1:release 0:press

unsigned long getTime_ms(void) {
  return milliSeconds; // 返回經過的毫秒數
}

unsigned char SW1_Status = KEY_STATE_RELEASE;
unsigned char SW2_Status = KEY_STATE_RELEASE;
unsigned char SW3_Status = KEY_STATE_RELEASE;

void keyDebounce(void) {
  static unsigned long SW1_PreviousTime;
  unsigned char SW1_CurrentState;
  static unsigned char SW1_PreviousState = KEY_RELEASE;
  
  static unsigned long SW2_PreviousTime;
  unsigned char SW2_CurrentState;
  static unsigned char SW2_PreviousState = KEY_RELEASE;
  
  static unsigned long SW3_PreviousTime;
  unsigned char SW3_CurrentState;
  static unsigned char SW3_PreviousState = KEY_RELEASE;

  unsigned long CurrentTime = getTime_ms();

  //讀取目前按鍵狀態
  SW1_CurrentState = SW1_GetValue();
  SW2_CurrentState = SW2_GetValue();
  SW3_CurrentState = SW3_GetValue();


  
  // 按鍵1
  if (SW1_CurrentState == KEY_PRESS) {
    //按下按鍵的情況
    if (SW1_PreviousState != SW1_CurrentState) {
      //信號有變化 更新狀態和時間
      SW1_PreviousTime = CurrentTime;
      SW1_PreviousState = SW1_CurrentState;
    } else {
      //持續按鍵 計算時間
      if (CurrentTime - SW1_PreviousTime > LONG_PRESS_THRESHOLD_TIME) {
        SW1_Status = KEY_STATE_LONG_PRESS;
      } else if (CurrentTime - SW1_PreviousTime > SHORT_PRESS_THRESHOLD_TIME) {
        SW1_Status = KEY_STATE_SHORT_PRESS;
      }
    }
  } else {
    //放開按鍵的情況
    SW1_CurrentState = KEY_RELEASE;
    if (SW1_PreviousState != SW1_CurrentState) {
      //信號有變化 更新狀態和時間
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
    //按下按鍵的情況
    if (SW2_PreviousState != SW2_CurrentState) {
      //信號有變化 更新狀態和時間
      SW2_PreviousTime = CurrentTime;
      SW2_PreviousState = SW2_CurrentState;
    } else {
      //持續按鍵 計算時間
      if (CurrentTime - SW2_PreviousTime > LONG_PRESS_THRESHOLD_TIME) {
        SW2_Status = KEY_STATE_LONG_PRESS;
      } else if (CurrentTime - SW2_PreviousTime > SHORT_PRESS_THRESHOLD_TIME) {
        SW2_Status = KEY_STATE_SHORT_PRESS;
      }
    }
  } else {
    //放開按鍵的情況
    SW2_CurrentState = KEY_RELEASE;
    if (SW2_PreviousState != SW2_CurrentState) {
      //信號有變化 更新狀態和時間
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
    //按下按鍵的情況
    if (SW3_PreviousState != SW3_CurrentState) {
      //信號有變化 更新狀態和時間
      SW3_PreviousTime = CurrentTime;
      SW3_PreviousState = SW3_CurrentState;
    } else {
      //持續按鍵 計算時間
      if (CurrentTime - SW3_PreviousTime > LONG_PRESS_THRESHOLD_TIME) {
        SW3_Status = KEY_STATE_LONG_PRESS;
      } else if (CurrentTime - SW3_PreviousTime > SHORT_PRESS_THRESHOLD_TIME) {
        SW3_Status = KEY_STATE_SHORT_PRESS;
      }
    }
  } else {
    //放開按鍵的情況
    SW3_CurrentState = KEY_RELEASE;
    if (SW3_PreviousState != SW3_CurrentState) {
      //信號有變化 更新狀態和時間
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