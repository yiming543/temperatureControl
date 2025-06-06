/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules
  selected in the GUI. Generation Information : Product Revision  :  PIC10 /
  PIC12 / PIC16 / PIC18 MCUs - 1.81.8 Device            :  PIC16F1936 Driver
  Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip software
   and any derivatives exclusively with Microchip products. It is your
   responsibility to comply with third party license terms applicable to your
   use of third party software (including open source software) that may
   accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS
    FOR A PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS
    SOFTWARE.
*/

// todo disp_7seg if else modify to switch case 20250605
// todo disp_7seg temp over 100 disp dot 20250605

#include "mcc_generated_files/key/key.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include <limits.h>
void TMR0_timerHandler(void);
void chkeckPressKeyNumber(void);
unsigned char CalTemperture(adc_result_t NTC_Value);

unsigned long milliSeconds = 0;
unsigned int t250ms = 0;
unsigned int t500ms = 0;
unsigned int t1000ms = 0;

unsigned char tempCnt = 0;
unsigned char fKeyRelease_SW1 = KEY_RELEASE; // 1:release 0:press
unsigned char fKeyRelease_SW2 = KEY_RELEASE; // 1:release 0:press
unsigned char fKeyRelease_SW3 = KEY_RELEASE; // 1:release 0:press
// unsigned long SW1_LongPressTime = LONG_MAX;
unsigned long SW2_LongPressTime = LONG_MAX;
unsigned long SW3_LongPressTime = LONG_MAX;
unsigned long longPressCurrentTime;

unsigned char fTooManyKeyPress = 0;
adc_result_t adc_result;
unsigned char temperture;

#define TEMP_MAX 99 // 99度C
#define TEMP_MIN 0  // 0度C

/*
                         Main application
 */
int main(void) {
  // initialize the device
  SYSTEM_Initialize();
  TMR0_SetInterruptHandler(TMR0_timerHandler);

  // Enable the Global Interrupts
  INTERRUPT_GlobalInterruptEnable();
  // Enable the Peripheral Interrupts
  INTERRUPT_PeripheralInterruptEnable();

  // When using interrupts, you need to set the Global and Peripheral Interrupt
  // Enable bits Use the following macros to:

  // Enable the Global Interrupts
  INTERRUPT_GlobalInterruptEnable();

  // Enable the Peripheral Interrupts
  INTERRUPT_PeripheralInterruptEnable();

  // Disable the Global Interrupts
  // INTERRUPT_GlobalInterruptDisable();

  // Disable the Peripheral Interrupts
  // INTERRUPT_PeripheralInterruptDisable();

  while (1) {
    // 讀取NTC溫度
    adc_result = ADC_GetConversion(channel_AN0);
    temperture = CalTemperture(adc_result);

    // 彈跳處理
    keyDebounce();
    longPressCurrentTime = getTime_ms();
    chkeckPressKeyNumber();

    // 同時按2個按鍵,不動作
    if (fTooManyKeyPress == 0) {

      // SW1 Short Press
      if ((SW1_Status == KEY_STATE_SHORT_PRESS) &&
          (fKeyRelease_SW1 == KEY_RELEASE)) {
        tempCnt++;
        fKeyRelease_SW1 = 0;
      }

      // SW2 Short Press
      if ((SW2_Status == KEY_STATE_SHORT_PRESS) &&
          (fKeyRelease_SW2 == KEY_RELEASE)) {
        tempCnt++;
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
        tempCnt--;
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
    }

    // 顯示溫度
    disp_sub(temperture, DISP_TEMP);
  }

  return 0;
}

void TMR0_timerHandler(void) {
  // add your TMR0 interrupt custom code
  // or set custom function using TMR0_SetInterruptHandler()
  milliSeconds++;
  t500ms++;
  t250ms++;
  t1000ms++;
  if (t250ms > 250) {
    t250ms = 0;
    // Relay1_Toggle();
  }

  if (t500ms > 500) {
    t500ms = 0;
    // Relay2_Toggle();
  }
}

void chkeckPressKeyNumber(void) {
  unsigned char keyCnt = 0;
  if ((SW1_Status == KEY_STATE_SHORT_PRESS) ||
      (SW1_Status == KEY_STATE_LONG_PRESS)) {
    keyCnt++;
  }
  if ((SW2_Status == KEY_STATE_SHORT_PRESS) ||
      (SW2_Status == KEY_STATE_LONG_PRESS)) {
    keyCnt++;
  }
  if ((SW3_Status == KEY_STATE_SHORT_PRESS) ||
      (SW3_Status == KEY_STATE_LONG_PRESS)) {
    keyCnt++;
  }
  if (keyCnt > 1) {
    fTooManyKeyPress = 1;
  } else {
    fTooManyKeyPress = 0;
  }
}

unsigned char CalTemperture(adc_result_t NTC_Value) {
  int temp;
  int NTC = NTC_Value & 0x3FF;

  temp= 511-NTC;
  temp= 250+temp;
  temp = temp/10;
//  temp = (250 - (511 - NTC)) / 10;

  if (temp > 99)
    temp = 99;

  if (temp < 0)
    temp = 0;

  return (temp & 0xff);
}

/**
 End of File
*/