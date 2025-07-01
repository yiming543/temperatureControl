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

// 20250609 V0.3
// 第1版功能完成,待測試.
// 20250610 V0.4
// 溫度改用查表法 做到0.1度精度
// 漍度設定範圍 1~99度

//20250701 V0.4 CS:DAFE
//增加EEPROM_SAVE 模式,按SW1回到溫度顯度,會先將SET1,SET2存到EEPROM.
//沒按鍵時間到回到溫度模式則不會儲存.

// todo disp_7seg if else modify to switch case 20250605
// todo disp_7seg temp over 100 disp dot 20250605
#include "TempControl.h"
#include "mcc_generated_files/key/key.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/temperature/temperature.h"
#include <stdint.h>

void TMR0_timerHandler(void);

uint32_t milliSeconds = 0;
uint16_t t250ms = 0;
uint16_t t500ms = 0;
uint16_t t1000ms = 0;
uint8_t f1S = 0;

uint8_t tempCnt = 0;
uint8_t tempCnt1 = 0;

// adc_result_t adc_result;
// uint8_t temperature;
#define DEFAULT_SET1 30
#define DEFAULT_SET2 30
#define SET1_ADDR 0x00
#define SET2_ADDR 0x01

uint8_t temperature_SET1 = DEFAULT_SET1; // 高於這個溫度,Relay1動作
uint8_t temperature_SET2 = DEFAULT_SET2; // 低於這個溫度,Relay2動作

uint8_t displayMode = 0;
uint8_t fRelay1 = 0;
uint8_t fRelay2 = 0;

__EEPROM_DATA(DEFAULT_SET1, DEFAULT_SET2, 0xff, 0xff0, 0xff, 0xff, 0xff, 0xff);

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

  if (t1000ms > 1000) {
    t1000ms = 0;
    f1S = 1;
  }
}

void checkTemperature_SET1(void) {
  uint16_t temperatureCheckSet_HI =
      ((uint16_t)temperature_SET1 * 10); // + DELTA_TEMPERATURE;
  uint16_t temperatureCheckSet_LO =
      ((uint16_t)temperature_SET1 * 10) - DELTA_TEMPERATURE;

  if (u16Temperature > temperatureCheckSet_HI) {
    Relay1_SetHigh();
    fRelay1 = 1;
  } else if (u16Temperature < temperatureCheckSet_LO) {
    Relay1_SetLow();
    fRelay1 = 0;
  }
}
void checkTemperature_SET2(void) {
  uint16_t temperatureCheckSet_HI = (temperature_SET2 * 10) + DELTA_TEMPERATURE;
  uint16_t temperatureCheckSet_LO =
      (temperature_SET2 * 10); // - DELTA_TEMPERATURE;

  if (u16Temperature < temperatureCheckSet_LO) {
    Relay2_SetHigh();
    fRelay2 = 1;
  } else if (u16Temperature > temperatureCheckSet_HI) {
    Relay2_SetLow();
    fRelay2 = 0;
  }
}

/*
                         Main application
 */
void main(void) {
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
  temperature_SET1 = DATAEE_ReadByte(SET1_ADDR);
  temperature_SET2 = DATAEE_ReadByte(SET2_ADDR);

  while (1) {
    // 讀取溫度
    if (f1S == 1) {
      getTemperature();
    }
    // 讀取按鍵
    getKeyStatus();

    // 顥示溫度 或 設定溫度
    if (displayMode == DISPLAY_MODE_TEMPERATURE) {
      disp_sub(temperature, DISP_TEMP);
    } else if (displayMode == DISPLAY_MODE_TEMPERATURE_SET1) {
      disp_sub(temperature_SET1, DISP_SET1);
    } else if (displayMode == DISPLAY_MODE_TEMPERATURE_SET2) {
      disp_sub(temperature_SET2, DISP_SET2);
    } else if (displayMode == EEPROM_SAVE) {
      DATAEE_WriteByte(SET1_ADDR, temperature_SET1);
      DATAEE_WriteByte(SET2_ADDR, temperature_SET2);
      displayMode = DISPLAY_MODE_TEMPERATURE;
    }

    // 檢查溫度是否超出範圍
    checkTemperature_SET1();
    checkTemperature_SET2();

    // if (f1S == 1) {
    //   f1S = 0;
    //   // tempCnt1++;

    //   // printf("ADC=%d\n", adc_result);
    //   // printf("temperature1=%d\n", temperature1);
    //   // printf("temperature=%d\n", temperature);
    //   printf("u16Temperature=%d\n", u16Temperature);
    //   // printf("fRelay1=%d\n", fRelay1);
    //   // printf("fRelay2=%d\n", fRelay2);
    //   printf("SET1=%d\n", temperature_SET1);
    //   printf("SET2=%d\n", temperature_SET2);
    //   printf("\n"); //空一行

    // }
  }
}

/**
 End of File
*/