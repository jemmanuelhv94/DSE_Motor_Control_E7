/* generated thread source file - do not edit */
#include "sensor_thread.h"

TX_THREAD sensor_thread;
void sensor_thread_create(void);
static void sensor_thread_func(ULONG thread_input);
static uint8_t sensor_thread_stack[1024] BSP_PLACE_IN_SECTION_V2(".stack.sensor_thread") BSP_ALIGN_VARIABLE_V2(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
#if (3) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_timer0) && !defined(SSP_SUPPRESS_ISR_AGT0)
SSP_VECTOR_DEFINE_CHAN(agt_int_isr, AGT, INT, 0);
#endif
#endif
static agt_instance_ctrl_t g_timer0_ctrl;
static const timer_on_agt_cfg_t g_timer0_extend =
{ .count_source = AGT_CLOCK_PCLKB, .agto_output_enabled = false, .agtio_output_enabled = false,
  .output_inverted = false, .agtoa_output_enable = false, .agtob_output_enable = false, };
static const timer_cfg_t g_timer0_cfg =
{ .mode = TIMER_MODE_PERIODIC, .period = 1, .unit = TIMER_UNIT_PERIOD_SEC, .channel = 0, .autostart = true,
  .p_callback = clickEvent, .p_context = &g_timer0, .p_extend = &g_timer0_extend, .irq_ipl = (3), };
/* Instance structure to use this module. */
const timer_instance_t g_timer0 =
{ .p_ctrl = &g_timer0_ctrl, .p_cfg = &g_timer0_cfg, .p_api = &g_timer_on_agt };
extern bool g_ssp_common_initialized;
extern uint32_t g_ssp_common_thread_count;
extern TX_SEMAPHORE g_ssp_common_initialized_semaphore;

void sensor_thread_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_ssp_common_thread_count++;

    /* Initialize each kernel object. */

    UINT err;
    err = tx_thread_create (&sensor_thread, (CHAR *) "Sensor Thread", sensor_thread_func, (ULONG) NULL,
                            &sensor_thread_stack, 1024, 5, 5, 1, TX_AUTO_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&sensor_thread, 0);
    }
}

static void sensor_thread_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    SSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    sensor_thread_entry ();
}
