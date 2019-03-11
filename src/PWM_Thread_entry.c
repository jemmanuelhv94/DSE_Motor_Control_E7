#include "PWM_Thread.h"


timer_size_t u8DutyCycle;
ioport_level_t led_0_level = IOPORT_LEVEL_HIGH;
int P_MOD4 = 0;

/* PWM Thread entry function */
void PWM_Thread_entry(void)
{
    g_timer9.p_api->open(g_timer9.p_ctrl, g_timer9.p_cfg);
    g_timer9.p_api->start(g_timer9.p_ctrl);

    /* TODO: add your own code here */
    while (1)
    {
        tx_thread_sleep (1);
    }
}


void timer9_callback(timer_callback_args_t *p_args)
{
    g_timer9.p_api->dutyCycleSet(g_timer9.p_ctrl,u8DutyCycle,TIMER_PWM_UNIT_PERCENT,0);

    if(P_MOD4 == 1)
      {
        g_ioport.p_api->pinWrite(IOPORT_PORT_01_PIN_14, IOPORT_LEVEL_LOW);
      }
    else
      {
        g_ioport.p_api->pinWrite(IOPORT_PORT_01_PIN_14, IOPORT_LEVEL_HIGH);
      }
}
