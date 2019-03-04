#include "control_thread.h"

/* Control Thread entry function */
void control_thread_entry(void)
{
    /* TODO: add your own code here */
    while (1)
    {
        tx_thread_sleep (1);
    }
}
