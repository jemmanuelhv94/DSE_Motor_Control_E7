#include "Heartbeat_Thread.h"

bool b_Heartbeat_Val = true;

/* Heartbeat Thread entry function */
void Heartbeat_Thread_entry(void)
{
    g_timer1.p_api->open(g_timer1.p_ctrl,g_timer1.p_cfg);
    g_timer1.p_api->start(g_timer1.p_ctrl);

    /* TODO: add your own code here */
    while (1)
    {
        tx_thread_sleep (1);
    }
}

void Heartbeat_Callback(timer_callback_args_t *p_args)
{
    g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_00, b_Heartbeat_Val);
    b_Heartbeat_Val = !b_Heartbeat_Val;
}
