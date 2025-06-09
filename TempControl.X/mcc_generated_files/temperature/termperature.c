#include "../mcc.h"
#include <stdint.h>
#include "temperature.h"


adc_result_t adc_result;
uint8_t temperature;
// extern adc_result_t adc_result;
// extern uint8_t temperature;

void getTemperature(void)
{
    adc_result = ADC_GetConversion(channel_AN0);
    temperature = CalTemperture(adc_result);
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