#include "lv_mainstart.h"

//��ȡ��Ļ�Ŀ�͸�
#define scr_act_width()		lv_obj_get_width(lv_scr_act())
#define scr_act_height()		lv_obj_get_height(lv_scr_act())

static lv_obj_t* btn_led;						//LED��ť
static lv_obj_t* btn_beep;						//BEEP��ť
static lv_obj_t* label_led;
static lv_obj_t* label_beep;
static const lv_font_t* font = &lv_font_montserrat_14;				//��������
static bool led_state = false;
static bool beep_state = false;

//���ư�ť�ص�
static void ledBtn_event_cb(lv_event_t* event)
{
	lv_obj_t* target = lv_event_get_target(event);			//��ȡ����Դ
	if(target == btn_led)
    {
        led_state = ~led_state;
        if(led_state)
            lv_label_set_text(label_led,"LED ON");
        else
            lv_label_set_text(label_led,"LED OFF");
    }
	else if(target == btn_beep)
    {
        beep_state = ~beep_state;
        if(beep_state)
            lv_label_set_text(label_beep,"BEEP ON");
        else
            lv_label_set_text(label_beep,"BEEP OFF");
    }
	else
    {
        lv_label_set_text(label_beep,"BEEP OFF")
        lv_label_set_text(label_led,"LED OFF");
    }
}

//LED������ʼ��
static void bth_led_init(void)
{
	btn_led = lv_btn_create(lv_scr_act());
	lv_obj_set_size(btn_led,scr_act_width() / 4,scr_act_height() / 6);
	lv_obj_align(btn_led,LV_ALIGN_CENTER,-150,0);
	lv_obj_add_event_cb(btn_led,ledBtn_event_cb,LV_EVENT_CLICKED,NULL);

	label_led = lv_label_create(btn_led);
	lv_obj_set_style_text_font(label_led,font,LV_PART_MAIN);												//��������
	lv_label_set_text(label_led,"LED OFF");																					//���ñ�ǩ�ı�
	lv_obj_set_align(label_led,LV_ALIGN_CENTER);																		//���ñ�ǩλ��
}

//BEEP������ʼ��
static void bth_beep_init(void)
{
	btn_beep = lv_btn_create(lv_scr_act());
	lv_obj_set_size(btn_beep,scr_act_width() / 4,scr_act_height() / 6);
	lv_obj_align(btn_beep,LV_ALIGN_CENTER,+150,0);
	lv_obj_add_event_cb(btn_beep,ledBtn_event_cb,LV_EVENT_CLICKED,NULL);

	label_beep = lv_label_create(btn_beep);
	lv_obj_set_style_text_font(label_beep,font,LV_PART_MAIN);												//��������
	lv_label_set_text(label_beep,"BEEP OFF");																					//���ñ�ǩ�ı�
	lv_obj_set_align(label_beep,LV_ALIGN_CENTER);																		//���ñ�ǩλ��
}


void my_gui(void)
{
    bth_led_init();
    bth_beep_init();
}

