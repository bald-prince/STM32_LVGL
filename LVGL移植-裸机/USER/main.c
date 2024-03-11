#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "lcd.h"
#include "sdram.h"
#include "touch.h"
#include "lv_port_disp_template.h"
#include "timer.h"
#include "lvgl.h"
#include "lv_port_disp_template.h"
#include "lv_port_indev_template.h"
#include "lv_demo_stress.h"
#include "lv_demo_music.h"


int main(void)
{
	Cache_Enable();                 //��L1-Cache
  HAL_Init();				        //��ʼ��HAL��
  Stm32_Clock_Init(432,25,2,9);   //����ʱ��,216Mhz 
  delay_init(216);                //��ʱ��ʼ��
	uart_init(115200);		        //���ڳ�ʼ��
  LED_Init();                     //��ʼ��LED
  KEY_Init();                     //��ʼ������
  SDRAM_Init();                   //��ʼ��SDRAM
	TIM3_Init(10 - 1,10800 - 1);
	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();
	
	lv_demo_stress();
	//lv_demo_music();
	
//	lv_obj_t* switch_obj = lv_switch_create(lv_scr_act());
//	lv_obj_set_size(switch_obj,120,60);
//	lv_obj_align(switch_obj,LV_ALIGN_CENTER,0,0);
	
	while(1)
	{
		delay_ms(5);
		lv_timer_handler();
	}					  	       
}
