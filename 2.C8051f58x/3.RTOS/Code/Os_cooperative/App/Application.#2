#include "Application.h"
extern U32 G_systick;
extern U8 Current_task;
extern TCB_t User_task[MAX_TASK];

SEG_XDATA U8 G_button_state = RELEASE;
void Os_start(void){
	SFRPAGE = ACTIVE_PAGE;
	PCA0MD &= ~0x40;                    // Disable watchdog timer
    MCU_init();
    Timer2_Set_Callback_Ptr(Callback_timer2);
	Ext0_Set_Callback_Ptr(Callback_ext0);
	Create_task(0U,idle_task);
    Create_task(1U,task1_handler);
    Create_task(2U,task2_handler);
    Create_task(3U,task3_handler);
	while(1){
    Os_scheduler();
	User_task[Current_task].task_handler();  
	}
}

void idle_task(void){
	if(G_button_state == PRESS ){
	Tonggle(LED_GREEN);
	G_button_state = RELEASE ;
	}
}

void task1_handler(void){
		U8 save = SFRPAGE;
        SFRPAGE = ACTIVE2_PAGE;
        printf("task1_handler \n");
		SFRPAGE = save;
        Os_delay(1000);
}

void task2_handler(void){
		U8 save = SFRPAGE;
        SFRPAGE = ACTIVE2_PAGE;
        printf("task2_handler \n");
		SFRPAGE = save;
        Tonggle(LED_YELLOW);
        Os_delay(3000);
}

void task3_handler(void){
		U8 save = SFRPAGE;
        SFRPAGE = ACTIVE2_PAGE;
        printf("task3_handler \n");
		SFRPAGE = save;
        Os_delay(5000);
}

void Callback_timer2(void){
    
    Increase_G_systick();
    Unblock_task();
	Clear_Timer2_ISR_Flag();
}
void Callback_ext0(void){
	Polling();
	if(!Get_Button_state()){
		G_button_state = PRESS;
	}
}


