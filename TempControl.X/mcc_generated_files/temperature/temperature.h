#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <stdint.h>
#include "../mcc.h"

extern void getTemperature(void);
uint8_t CalTemperture(adc_result_t NTC_Value);

extern adc_result_t adc_result;
extern uint8_t temperature;


#endif