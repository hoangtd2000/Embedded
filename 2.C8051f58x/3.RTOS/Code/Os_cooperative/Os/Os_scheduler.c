#include "Os_scheduler.h"
#include "Os_task.h"
extern U8 Current_task;
extern TCB_t User_task[MAX_TASK];

void Os_scheduler(void)
{
    SEG_XDATA U8 i, next_task;
    EA = 1;   // Enable global interrupt
    for (i = 1; i < MAX_TASK; i++) {
        next_task = (Current_task + i) % MAX_TASK;
        if((User_task[Current_task].current_state == TASK_READY_STATE) && (Current_task != 0)){
            return;
        }
        if (User_task[next_task].current_state == TASK_READY_STATE) {
            Current_task = next_task;
            return;
        }
    }
    Current_task = 0;
}

