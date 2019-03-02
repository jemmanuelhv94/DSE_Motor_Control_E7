#include "Timing_Thread.h"

bool b_Heartbeat_Val = true;
uint16_t u16TickCnt = 0;
uint16_t u16HallCnt = 0;
uint16_t u16RPM = 0;
uint16_t u16EdgeCnt = 0;

#define C_HEARTBEAT_PERIOD 500

timer_size_t u8DutyCycle;
ioport_level_t led_0_level = IOPORT_LEVEL_HIGH;
int P_MOD4 = 0;

/* Timing Thread entry function */
void Timing_Thread_entry(void)
{
    g_timer1.p_api->open(g_timer1.p_ctrl,g_timer1.p_cfg);
    g_timer1.p_api->start(g_timer1.p_ctrl);

    g_timer9.p_api->open(g_timer9.p_ctrl, g_timer9.p_cfg);
    g_timer9.p_api->start(g_timer9.p_ctrl);

    g_external_irq4.p_api->open(g_external_irq4.p_ctrl,g_external_irq4.p_cfg);

    u16TickCnt = C_HEARTBEAT_PERIOD;

    /* TODO: add your own code here */
    while (1)
    {
        tx_thread_sleep (1);
    }
}

void Timing_Callback(timer_callback_args_t *p_args)
{
    u16HallCnt++;

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

void Hall_Sensor_Callback(external_irq_callback_args_t *p_args)
{
    u16RPM = (1000/(u16HallCnt*4))*60;
    u16HallCnt = 0;
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
