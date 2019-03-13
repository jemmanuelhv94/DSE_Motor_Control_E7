/* generated thread source file - do not edit */
#include "PWM_Thread.h"

TX_THREAD PWM_Thread;
void PWM_Thread_create(void);
static void PWM_Thread_func(ULONG thread_input);
static uint8_t PWM_Thread_stack[1024] BSP_PLACE_IN_SECTION_V2(".stack.PWM_Thread") BSP_ALIGN_VARIABLE_V2(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
#if (2) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_timer9) && !defined(SSP_SUPPRESS_ISR_GPT9)
SSP_VECTOR_DEFINE_CHAN(gpt_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 9);
#endif
#endif
static gpt_instance_ctrl_t g_timer9_ctrl;
static const timer_on_gpt_cfg_t g_timer9_extend =
{ .gtioca =
{ .output_enabled = true, .stop_level = GPT_PIN_LEVEL_LOW },
  .gtiocb =
  { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
  .shortest_pwm_signal = GPT_SHORTEST_LEVEL_OFF, };
static const timer_cfg_t g_timer9_cfg =
{ .mode = TIMER_MODE_PWM, .period = 10, .unit = TIMER_UNIT_PERIOD_MSEC, .duty_cycle = 50, .duty_cycle_unit =
          TIMER_PWM_UNIT_PERCENT,
  .channel = 9, .autostart = true, .p_callback = timer9_callback, .p_context = &g_timer9, .p_extend = &g_timer9_extend,
  .irq_ipl = (2), };
/* Instance structure to use this module. */
const timer_instance_t g_timer9 =
{ .p_ctrl = &g_timer9_ctrl, .p_cfg = &g_timer9_cfg, .p_api = &g_timer_on_gpt };
extern bool g_ssp_common_initialized;
extern uint32_t g_ssp_common_thread_count;
extern TX_SEMAPHORE g_ssp_common_initialized_semaphore;

void PWM_Thread_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_ssp_common_thread_count++;

    /* Initialize each kernel object. */

    UINT err;
    err = tx_thread_create (&PWM_Thread, (CHAR *) "PWM Thread", PWM_Thread_func, (ULONG) NULL, &PWM_Thread_stack, 1024,
                            5, 5, 1, TX_AUTO_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&PWM_Thread, 0);
    }
}

static void PWM_Thread_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    SSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    PWM_Thread_entry ();
}
