#include "control_thread.h"
#include "control_api.h"
#include "speed_api.h"

    static int speed_value=0;
    static bool activate_flag=false;


/* Control Thread entry function */
void control_thread_entry(void)
{

    sf_message_header_t * pSensorDataHeader; //pointer to the message header
   control_payload_t * pSensorDataPayload; //pointer to the message payload
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
          speed_payload_t * pDataPayload; //pointer to the receiving message payload
       /* TODO: add your own code here */
       while (1)
       {

           g_sf_message0.p_api->pend(g_sf_message0.p_ctrl, &control_thread_message_queue,
                                       &pSensorDataHeader, TX_NO_WAIT); //if a message has been posted to the queue, store its address in pSensorDataHeader

                  if (pSensorDataHeader->event_b.class_code == SF_MESSAGE_EVENT_CLASS_CONTROL) //if the message is the right kind
                  {
                      pSensorDataPayload = (control_payload_t *) pSensorDataHeader; //cast the received message to the custom type
                      //store the sensor information in some buffers, this part is application dependent
                      if (pSensorDataPayload->header.event_b.code == SF_MESSAGE_EVENT_NEW_DATA) //if the message event is the right kind
                      {
                          activate_flag=pSensorDataPayload->activate;
                          speed_value=pSensorDataPayload->set_point;
                          g_sf_message0.p_api->bufferRelease(g_sf_message0.p_ctrl, pSensorDataHeader, SF_MESSAGE_RELEASE_OPTION_NONE);
                      }
                  }
if(activate_flag==false)
{
    speed_value=0;
}


           errorBuff = g_sf_message0.p_api->bufferAcquire(g_sf_message0.p_ctrl, &pPostBuffer, &acquireCfg, TX_NO_WAIT);
           if (errorBuff==SSP_SUCCESS)
           {
               pDataPayload = (speed_payload_t *) pPostBuffer; //cast buffer to our payload
               pDataPayload->header.event_b.class = SF_MESSAGE_EVENT_CLASS_SPEED; //set the event class
               pDataPayload->header.event_b.class_instance = 1; //set the class instance
               pDataPayload->header.event_b.code = SF_MESSAGE_EVENT_NEW_DATA; //set the message type
               pDataPayload->speed_value=speed_value++;
               g_sf_message0.p_api->post(g_sf_message0.p_ctrl, (sf_message_header_t *) pDataPayload,
                                         &post_cfg, &errPost, TX_NO_WAIT); //post the message
                  }
           tx_thread_sleep (5);
    }
}
