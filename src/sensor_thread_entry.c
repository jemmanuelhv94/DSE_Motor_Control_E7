#include "sensor_thread.h"
#include "sensor_api.h"
#include "Ram.h"

static int sensor_value;
void post_message();

sensor_payload_t * pDataPayload;
          sf_message_post_err_t errPost; //place for posting error codes to go
          sf_message_post_cfg_t post_cfg =
          {
            .priority = SF_MESSAGE_PRIORITY_NORMAL, //normal priority
            .p_callback = NULL //no callback needed
          };


/* Sensor Thread entry function */
void sensor_thread_entry(void)
{
    g_timer0.p_api->open(g_timer0.p_ctrl,g_timer0.p_cfg);
    g_timer0.p_api->start(g_timer0.p_ctrl);

    //Message init
          //sending sensordata init
          sf_message_header_t * pPostBuffer; //pointer for the buffer that must be acquired
          sf_message_acquire_cfg_t acquireCfg = {.buffer_keep =false}; //do not keep the buffer, other threads need it
          ssp_err_t errorBuff; //place for error codes from buffer acquisition to go
//          sf_message_post_err_t errPost; //place for posting error codes to go
//          sf_message_post_cfg_t post_cfg =
//          {
//            .priority = SF_MESSAGE_PRIORITY_NORMAL, //normal priority
//            .p_callback = NULL //no callback needed
//          };
         // sensor_payload_t * pDataPayload; //pointer to the receiving message payload
       /* TODO: add your own code here */
       while (1)
       {
           errorBuff = g_sf_message0.p_api->bufferAcquire(g_sf_message0.p_ctrl, &pPostBuffer, &acquireCfg, 0);
           if (errorBuff==SSP_SUCCESS)
           {
               pDataPayload = (sensor_payload_t *) pPostBuffer; //cast buffer to our payload
               pDataPayload->header.event_b.class = SF_MESSAGE_EVENT_CLASS_SENSOR; //set the event class
               pDataPayload->header.event_b.class_instance = 0; //set the class instance
               pDataPayload->header.event_b.code = SF_MESSAGE_EVENT_SENSOR; //set the message type
               pDataPayload->sensor_value=sensor_value++;
               g_sf_message0.p_api->post(g_sf_message0.p_ctrl, (sf_message_header_t *) pDataPayload,
                                         &post_cfg, &errPost, TX_WAIT_FOREVER); //post the message
           }
               tx_thread_sleep (200);
    }
}

void clickEvent(timer_callback_args_t *p_args)
{
    sensor_value++;
}

