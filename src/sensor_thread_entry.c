#include "sensor_thread.h"
#include "sensor_api.h"
#include "sensor_thread.h"
#include "Ram.h"

    static int sensor_value;
    void post_message();
/* Sensor Thread entry function */
void sensor_thread_entry(void)
{
    g_input_capture.p_api->open(g_input_capture.p_ctrl, g_input_capture.p_cfg);
    g_input_capture.p_api->enable(g_input_capture.p_ctrl);
    SR_Init_Ram();


    //Message init
          //sending sensordata init
          sf_message_header_t * pPostBuffer; //pointer for the buffer that must be acquired
          sf_message_acquire_cfg_t acquireCfg = {.buffer_keep =false}; //do not keep the buffer, other threads need it
          ssp_err_t errorBuff; //place for error codes from buffer acquisition to go
          sf_message_post_err_t errPost; //place for posting error codes to go
          sf_message_post_cfg_t post_cfg =
          {
            .priority = SF_MESSAGE_PRIORITY_NORMAL, //normal priority
            .p_callback = NULL //no callback needed
          };
          sensor_payload_t * pDataPayload; //pointer to the receiving message payload
       /* TODO: add your own code here */
       while (1)
       {
           errorBuff = g_sf_message0.p_api->bufferAcquire(g_sf_message0.p_ctrl, &pPostBuffer, &acquireCfg, TX_WAIT_FOREVER);
           if (errorBuff==SSP_SUCCESS)
           {
               pDataPayload = (sensor_payload_t *) pPostBuffer; //cast buffer to our payload
               pDataPayload->header.event_b.class = SF_MESSAGE_EVENT_CLASS_SENSOR; //set the event class
               pDataPayload->header.event_b.class_instance = 0; //set the class instance
               pDataPayload->header.event_b.code = SF_MESSAGE_EVENT_SENSOR; //set the message type
               pDataPayload->sensor_value=u32I_RPM;
               g_sf_message0.p_api->post(g_sf_message0.p_ctrl, (sf_message_header_t *) pDataPayload,
                                         &post_cfg, &errPost, TX_WAIT_FOREVER); //post the message
                  }
           tx_thread_sleep (20);
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


