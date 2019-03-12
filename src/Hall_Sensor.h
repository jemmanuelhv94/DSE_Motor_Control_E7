/*
 * Hall_Sensor.h
 *
 *  Created on: Mar 11, 2019
 *      Author: JHVMEXMM
 */
#include "main_thread.h"

#ifndef HALL_SENSOR_H_
#define HALL_SENSOR_H_

extern void SR_I16Filter(uint16_t *lpi16Data, uint32_t *lpi32ShiftAdd, uint16_t *lpi16Result);
extern void SR_InitFilter(uint16_t li16InputData);

#endif /* HALL_SENSOR_H_ */
