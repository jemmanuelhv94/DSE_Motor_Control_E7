/* generated messaging source file - do not edit */
#include "sf_message.h"
#ifndef SF_MESSAGE_CFG_QUEUE_SIZE
#define SF_MESSAGE_CFG_QUEUE_SIZE (16)
#endif
TX_QUEUE main_thread_message_queue;
static uint8_t queue_memory_main_thread_message_queue[SF_MESSAGE_CFG_QUEUE_SIZE];
TX_QUEUE sensor_thread_message_queue;
static uint8_t queue_memory_sensor_thread_message_queue[SF_MESSAGE_CFG_QUEUE_SIZE];
static sf_message_subscriber_t main_thread_message_queue_0_0 =
{ .p_queue = &main_thread_message_queue, .instance_range =
{ .start = 0, .end = 0 } };
static sf_message_subscriber_t sensor_thread_message_queue_0_1 =
{ .p_queue = &sensor_thread_message_queue, .instance_range =
{ .start = 0, .end = 1 } };
static sf_message_subscriber_t *gp_group_SF_MESSAGE_EVENT_CLASS_TOUCH[] =
{ &main_thread_message_queue_0_0, };
static sf_message_subscriber_list_t g_list_SF_MESSAGE_EVENT_CLASS_TOUCH =
{ .event_class = SF_MESSAGE_EVENT_CLASS_TOUCH, .number_of_nodes = 1, .pp_subscriber_group =
          gp_group_SF_MESSAGE_EVENT_CLASS_TOUCH };
static sf_message_subscriber_t *gp_group_SF_MESSAGE_EVENT_CLASS_SENSOR[] =
{ &sensor_thread_message_queue_0_1, &main_thread_message_queue_0_0, };
static sf_message_subscriber_list_t g_list_SF_MESSAGE_EVENT_CLASS_SENSOR =
{ .event_class = SF_MESSAGE_EVENT_CLASS_SENSOR, .number_of_nodes = 2, .pp_subscriber_group =
          gp_group_SF_MESSAGE_EVENT_CLASS_SENSOR };
sf_message_subscriber_list_t *p_subscriber_lists[] =
{ &g_list_SF_MESSAGE_EVENT_CLASS_TOUCH, &g_list_SF_MESSAGE_EVENT_CLASS_SENSOR, NULL };
void g_message_init(void);
void g_message_init(void)
{
    tx_queue_create (&main_thread_message_queue, (CHAR *) "Main Thread Message Queue", 1,
                     &queue_memory_main_thread_message_queue, sizeof(queue_memory_main_thread_message_queue));
    tx_queue_create (&sensor_thread_message_queue, (CHAR *) "Sensor Thread Message Queue", 1,
                     &queue_memory_sensor_thread_message_queue, sizeof(queue_memory_sensor_thread_message_queue));
}
