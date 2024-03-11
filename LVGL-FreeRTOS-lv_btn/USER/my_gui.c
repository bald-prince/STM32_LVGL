#include "my_gui.h"

#if (1 != LV_FONT_MONTSERRAT_10 || 1 != LV_FONT_MONTSERRAT_14 || 1 != LV_FONT_MONTSERRAT_20)
    #error Please Make Sure Enable LV_FONT_MONTSERRAT_10 & LV_FONT_MONTSERRAT_14 & LV_FONT_MONTSERRAT_20
#endif

static const lv_font_t* font = &lv_font_montserrat_14;				//��������

static lv_obj_t* btn_led;						//LED��ť
static lv_obj_t* label_led;


//��ȡ��Ļ�Ŀ�͸�
#define scr_act_width()			lv_obj_get_width(lv_scr_act())
#define scr_act_height()		lv_obj_get_height(lv_scr_act())

//���ư�ť�ص�
static void ledBtn_event_cb(lv_event_t* event)
{
	lv_obj_t* target = lv_event_get_target(event);			//��ȡ����Դ
	if(target == btn_led)
	{
		LED1_Toggle();
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 0)
			lv_label_set_text(label_led,"LED OFF");
		else
			lv_label_set_text(label_led,"LED ON");
	}
}

//LED������ʼ��
static void bth_led_init(void)
{
	btn_led = lv_btn_create(lv_scr_act());
	lv_obj_set_size(btn_led,scr_act_width() / 4,scr_act_height() / 6);
	lv_obj_align(btn_led,LV_ALIGN_CENTER,0,0);
	lv_obj_add_event_cb(btn_led,ledBtn_event_cb,LV_EVENT_CLICKED,NULL);

	label_led = lv_label_create(btn_led);
	lv_obj_set_style_text_font(label_led,font,LV_PART_MAIN);												//��������
	lv_label_set_text(label_led,"LED ON");																					//���ñ�ǩ�ı�
	lv_obj_set_align(label_led,LV_ALIGN_CENTER);																		//���ñ�ǩλ��
}

	
void my_gui(void)
{
	bth_led_init();
}
