#include "Timing_Thread.h"

#define C_HEARTBEAT_PERIOD 500

bool b_Heartbeat_Val = true;
uint16_t u16TickCnt = 0;

/* Timing Thread entry function */
void Timing_Thread_entry(void)
{
    g_timer1.p_api->open(g_timer1.p_ctrl,g_timer1.p_cfg);
    g_timer1.p_api->start(g_timer1.p_ctrl);

    u16TickCnt = C_HEARTBEAT_PERIOD;

    /* TODO: add your own code here */
    while (1)
    {
        tx_thread_sleep (1);
    }
}

void Timing_Callback(timer_callback_args_t *p_args)
{

    if (u16TickCnt > 0)
    {
        u16TickCnt--;
    }

    if (u16TickCnt <= 0)
    {
        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_00, b_Heartbeat_Val);
        b_Heartbeat_Val = !b_Heartbeat_Val;
        u16TickCnt = C_HEARTBEAT_PERIOD;
    }
}


