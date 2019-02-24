/* generated thread header file - do not edit */
#ifndef HEARTBEAT_THREAD_H_
#define HEARTBEAT_THREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus
extern "C" void Heartbeat_Thread_entry(void);
#else
extern void Heartbeat_Thread_entry(void);
#endif
#include "r_gpt.h"
#include "r_timer_api.h"
#ifdef __cplusplus
extern "C"
{
#endif
/** Timer on GPT Instance. */
extern const timer_instance_t g_timer1;
#ifndef Heartbeat_Callback
void Heartbeat_Callback(timer_callback_args_t *p_args);
#endif
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* HEARTBEAT_THREAD_H_ */
