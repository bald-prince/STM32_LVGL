#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "lcd.h"
#include "sdram.h"
#include "touch.h"
#include "lvgl_demo.h"
#include "my_gui.h"


int main(void)
{
	Cache_Enable();                 //打开L1-Cache
  HAL_Init();				        //初始化HAL库
  Stm32_Clock_Init(432,25,2,9);   //设置时钟,216Mhz 
  delay_init(216);                //延时初始化
	uart_init(115200);		        //串口初始化
  LED_Init();                     //初始化LED
  KEY_Init();                     //初始化按键
  SDRAM_Init();                   //初始化SDRAM

	lvgl_demo();
	
	
//	lv_obj_t* switch_obj = lv_switch_create(lv_scr_act());
//	lv_obj_set_size(switch_obj,120,60);
//	lv_obj_align(switch_obj,LV_ALIGN_CENTER,0,0);
	
	while(1)
	{

	}					  	       
}
