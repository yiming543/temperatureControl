// #include "../mcc.h"
// #include <stdint.h>
#include "temperature.h"
#include <stdint.h>

const uint16_t TEMPERATURE_TAB[] = {
    // TSM1A103F34D3HZ  for 10bit
    752, 743, 734, 725, 716, 707, 698, 688, 679, 669, 659, 650, 640, 630, 620,
    611, 601, 591, 581, 571, 561, 551, 541, 532, 522, 512, 502, 493, 483, 474,
    464, 455, 446, 437, 428, 419, 410, 401, 393, 384, 376, 368, 360, 352, 344,
    336, 329, 321, 314, 307, 300, 293, 286, 280, 273, 267, 261, 255, 249, 243,
    237, 231, 226, 221, 215, 210, 205, 200, 196, 191, 186, 182, 178, 173, 169,
    165, 161, 157, 154, 150, 146, 143, 140, 136, 133, 130, 127, 124, 121, 118,
    115, 112, 110, 107, 105, 102, 100, 98,  95,  93,  91,
};

adc_result_t adc_result;


uint8_t temperature;  //unit:1 degree
uint8_t temperature1;
uint16_t u16Temperature; //unit:0.1 degree

void getTemperature(void) {
  adc_result = ADC_GetConversion(channel_AN0);
  temperature1 = CalTemperture(adc_result);
  u16Temperature = ADC2Temperature(adc_result);
  temperature = (uint8_t)(u16Temperature /10);
}

uint8_t CalTemperture(adc_result_t NTC_Value) {
  int temp;
  int NTC = NTC_Value & 0x3FF;

  temp = 511 - NTC;
  temp = 250 + temp;
  temp = temp / 10;
  //  temp = (250 - (511 - NTC)) / 10;

  if (temp > 99)
    temp = 99;

  if (temp < 0)
    temp = 0;

  return (temp & 0xff);
}

uint16_t ADC2Temperature(const uint16_t result_TH) {
  size_t array_size = sizeof(TEMPERATURE_TAB) / sizeof(TEMPERATURE_TAB[0]);
  uint16_t Temp_TH = 0;
  uint16_t difC = 5;

  if (result_TH >= TEMPERATURE_TAB[array_size - 2]) {
    for (uint16_t i = 0; i < array_size; i++) // TEMPERATURE_TAB
    {
      if (result_TH > TEMPERATURE_TAB[i]) {
        if (i == 0) {
          Temp_TH = 0;
        } else {
          // Temporary storage
          uint16_t j = (10 * (result_TH - TEMPERATURE_TAB[i])) /
                       (TEMPERATURE_TAB[i - 1] - TEMPERATURE_TAB[i]);

          Temp_TH = (i * 10) - j - difC;
        }
        break;
      }
    }
  } else {
    Temp_TH = 999;
  }

  return Temp_TH;
}