#include "control_thread.h"
#include "control_api.h"
#include "speed_api.h"
#include "control_thread_entry.h"

/* Control Thread entry function */
void control_thread_entry(void)
{
    g_timer9.p_api->open (g_timer9.p_ctrl, g_timer9.p_cfg);
    g_timer9.p_api->start (g_timer9.p_ctrl);

    /* TODO: add your own code here */
    while (1)
    {

        read_message_control();
        if (activate_flag == false)
        {
            speed_value = 0;
            u8DutyCycle = 100;
        }
        else{
        }
        write_message_control();
        tx_thread_sleep (2);
    }
}

void timer9_callback(timer_callback_args_t *p_args)
{
    g_timer9.p_api->dutyCycleSet (g_timer9.p_ctrl, u8DutyCycle, TIMER_PWM_UNIT_PERCENT, 0);

    if (activate_flag == true)
    {
        g_ioport.p_api->pinWrite (IOPORT_PORT_01_PIN_14, IOPORT_LEVEL_LOW);
    }
    else
    {
        g_ioport.p_api->pinWrite (IOPORT_PORT_01_PIN_14, IOPORT_LEVEL_HIGH);
    }
}

//int PIDcontrol(int Kp, int Ki, int set_point, int rpm)
//{
//
//    float P = 0, I = 0, D = 0;
//
//    int Uc, error_acum, error;
//    int Kz;
//    error=set_point-rpm;
//    unsigned long T;
//
//    // T = millis() - ultimo_T;
//
//    Kz = 1 / 1000.00;
//    error_acum += error;
//
//    P = Kp * error;
//    I = Ki * ((error_acum + error) / Kz);
//
//    Uc = P + I + D;
//    return (Uc);
//}

void write_message_control(){
    errorBuffControl = g_sf_message0.p_api->bufferAcquire (g_sf_message0.p_ctrl, &pPostBufferControl,
                                                           &acquireCfgControl, TX_NO_WAIT);
    if (errorBuffControl == SSP_SUCCESS)
    {
        pDataPayloadControl = (speed_payload_t *) pPostBufferControl; //cast buffer to our payload
        pDataPayloadControl->header.event_b.class = SF_MESSAGE_EVENT_CLASS_SPEED; //set the event class
        pDataPayloadControl->header.event_b.class_instance = 1; //set the class instance
        pDataPayloadControl->header.event_b.code = SF_MESSAGE_EVENT_NEW_DATA; //set the message type
        pDataPayloadControl->speed_value = u8DutyCycle;
        g_sf_message0.p_api->post (g_sf_message0.p_ctrl, (sf_message_header_t *) pDataPayloadControl,
                                   &post_cfgControl, &errPostControl, TX_NO_WAIT); //post the message
    }
}

void read_message_control(){
    g_sf_message0.p_api->pend (g_sf_message0.p_ctrl, &control_thread_message_queue, &pSensorDataHeader, TX_NO_WAIT); //if a message has been posted to the queue, store its address in pSensorDataHeader

    if (pSensorDataHeader->event_b.class_code == SF_MESSAGE_EVENT_CLASS_CONTROL) //if the message is the right kind
    {
        pSensorDataPayload = (control_payload_t *) pSensorDataHeader; //cast the received message to the custom type
        //store the sensor information in some buffers, this part is application dependent
        if (pSensorDataPayload->header.event_b.code == SF_MESSAGE_EVENT_NEW_DATA) //if the message event is the right kind
        {
            activate_flag = pSensorDataPayload->activate;
            speed_value = pSensorDataPayload->set_point;
            u8DutyCycle = pSensorDataPayload->set_point;
            feedback_value=pSensorDataPayload->feedback;
            g_sf_message0.p_api->bufferRelease (g_sf_message0.p_ctrl, pSensorDataHeader,
                                                SF_MESSAGE_RELEASE_OPTION_NONE);
        }
    }
}
