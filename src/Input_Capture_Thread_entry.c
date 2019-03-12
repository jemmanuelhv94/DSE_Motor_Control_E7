#include "Input_Capture_Thread.h"
#include "Ram.h"


/* Input Capture Thread entry function */
void Input_Capture_Thread_entry(void)
{
    g_input_capture.p_api->open(g_input_capture.p_ctrl, g_input_capture.p_cfg);
    g_input_capture.p_api->enable(g_input_capture.p_ctrl);
    SR_Init_Ram();

    /* TODO: add your own code here */
    while (1)
    {
        tx_thread_sleep (1);
    }
}


void input_capture_callback(input_capture_callback_args_t *p_args)
{
    static uint32_t pclk_freq_hz = 0;

    switch(p_args->event)
    {
        case INPUT_CAPTURE_EVENT_MEASUREMENT:

            /* Get the value of the captured counter and overflows number */
            capture_counter = p_args->counter;

            /*
            * Currently there is a limitation for using API of lastCaptureGet, otherwise captured counter and overflows number can
            * be got from g_input_capture.p_api->lastCaptureGet. Please refer to the documentation for more information.
            */

            /* Get the frequency of PCLKD in Hz*/
            g_cgc_on_cgc.systemClockFreqGet(CGC_SYSTEM_CLOCKS_PCLKD, &pclk_freq_hz);

            /* Calculate time value of measurement (ns) */
            u64time_captured_ns = (uint64_t)(((capture_overflow * BIT_32) + (uint64_t)capture_counter) * TIMER_SECOND / (pclk_freq_hz));
            u64capturems = u64time_captured_ns;

            u32TimeCaptured_us = (uint32_t)(((float)u64time_captured_ns / (float)TIMER_MICROSECOND) + 0.5F);
            u32Inst_RPM = ((MICRO_SECONDS_IN_A_MINUTE)/ (u32TimeCaptured_us)) * (uint32_t) (SCALED_FACTOR);

            u32Inst_RPM = (uint32_t)(u32Inst_RPM)/(uint32_t)(MAGNET_POLES * SCALED_FACTOR);
            u32I_RPM = u32Inst_RPM;

            u64time_captured_ns = 0;
            capture_overflow = 0;
            break;

        case INPUT_CAPTURE_EVENT_OVERFLOW:

            /* Overflows counter add one */
            capture_overflow++;

            /*
            * Current there is a limitation for using parameter of p_args->overflows, otherwise overflows number can be got from p_args->overflows. Please refer to the documentation.
            */
            break;
        default:
            break;
    }

}
