/* generated thread header file - do not edit */
#ifndef TIMING_THREAD_H_
#define TIMING_THREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus
extern "C" void Timing_Thread_entry(void);
#else
extern void Timing_Thread_entry(void);
#endif
#include "r_gpt.h"
#include "r_timer_api.h"
#include "r_icu.h"
#include "r_external_irq_api.h"
#ifdef __cplusplus
extern "C"
{
#endif
/** Timer on GPT Instance. */
extern const timer_instance_t g_timer9;
#ifndef timer9_callback
void timer9_callback(timer_callback_args_t *p_args);
#endif
/* External IRQ on ICU Instance. */
extern const external_irq_instance_t g_external_irq4;
#ifndef Hall_Sensor_Callback
void Hall_Sensor_Callback(external_irq_callback_args_t *p_args);
#endif
/** Timer on GPT Instance. */
extern const timer_instance_t g_timer1;
#ifndef Timing_Callback
void Timing_Callback(timer_callback_args_t *p_args);
#endif
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* TIMING_THREAD_H_ */
