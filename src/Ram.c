/*
 * Ram.c
 *
 *  Created on: Mar 9, 2019
 *      Author: JHVMEXMM
 */
#include "Ram.h"
uint64_t u64time_captured_ns;
uint64_t u32TimeCaptured_us;
uint16_t u16HallCnt;
uint32_t u32Inst_RPM;
uint32_t u32I_RPM;
uint16_t u16EdgeCnt;
uint64_t u64capturems;

uint16_t i16InputVar;
uint32_t i32VarAccumulator;
uint16_t i16AverageVar;

uint64_t capture_overflow;
uint32_t capture_counter;

void SR_Init_Ram(void)
{
    u64time_captured_ns = 0;
    u32TimeCaptured_us = 0;
    u16HallCnt = 0;
    u32Inst_RPM = 0;
    u32I_RPM = 0;
    u16EdgeCnt = 0;
    u64capturems = 0;

    uint16_t i16InputVar = 0;
    uint32_t i32VarAccumulator = 0;
    uint16_t i16AverageVar = 0;

    capture_overflow = 0;
    capture_counter = 0;
}
