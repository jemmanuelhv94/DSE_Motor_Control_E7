/*
 * Ram.h
 *
 *  Created on: Mar 9, 2019
 *      Author: JHVMEXMM
 */

#ifndef RAM_H_
#define RAM_H_

#include "main_thread.h"

#define C_ONE_SECOND (uint16_t)(1000)
#define C_SECONDS_IN_A_MINUTE (uint8_t)(60)
#define MICRO_SECONDS_IN_A_MINUTE   60000000
#define C_TRANSITIONS_PER_REVOLUTION (uint8_t)(4)
#define TIMER_SECOND (1000000000U)
#define TIMER_MILLISECOND (1000000U)
#define TIMER_MICROSECOND (1000U)
#define BIT_32 (0x100000000U)

#define MAGNET_POLES        4
#define SCALED_FACTOR       1000

extern uint64_t u64time_captured_ns;
extern uint64_t u32TimeCaptured_us;
extern uint16_t u16HallCnt;
extern uint32_t u32Inst_RPM;
extern uint16_t u16EdgeCnt;
extern uint64_t u64capturems;
extern uint32_t u32I_RPM;

extern uint64_t capture_overflow;
extern uint32_t capture_counter;

extern void SR_Init_Ram(void);
#endif /* RAM_H_ */
