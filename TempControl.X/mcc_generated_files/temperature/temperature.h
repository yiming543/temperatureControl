#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <stdint.h>
#include "../mcc.h"

extern void getTemperature(void);
uint8_t CalTemperture(adc_result_t NTC_Value);
uint16_t ADC2Temperature(const uint16_t result_TH);

extern adc_result_t adc_result;
extern uint8_t temperature;
extern uint8_t temperature1;
extern uint16_t u16Temperature;



#endif