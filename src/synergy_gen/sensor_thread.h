/* generated thread header file - do not edit */
#ifndef SENSOR_THREAD_H_
#define SENSOR_THREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus
extern "C" void sensor_thread_entry(void);
#else
extern void sensor_thread_entry(void);
#endif
#include "r_agt.h"
#include "r_timer_api.h"
#ifdef __cplusplus
extern "C"
{
#endif
/** AGT Timer Instance */
extern const timer_instance_t g_timer0;
#ifndef clickEvent
void clickEvent(timer_callback_args_t *p_args);
#endif
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* SENSOR_THREAD_H_ */
