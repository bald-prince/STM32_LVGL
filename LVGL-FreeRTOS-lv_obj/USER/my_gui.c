#include "my_gui.h"


static lv_coord_t scr_act_width,scr_act_height;				//���Ļ��ȡ��߶�
static lv_obj_t *parent_obj;													//������
static lv_obj_t *child_obj;														//�Ӷ���

static void obj_event_cb(lv_event_t *e)
{
	lv_obj_t* target = lv_event_get_target(e);			 //��ȡ�¼�����Դ
	if (target == parent_obj)                                                   //�жϴ���Դ���ǲ��Ǹ�����
		lv_obj_align(parent_obj, LV_ALIGN_CENTER, 0, 0);                        //�������ø������λ�ã����� 
  else if (target == child_obj)                                               //�жϴ���Դ���ǲ����Ӷ��� 
    lv_obj_align(child_obj, LV_ALIGN_RIGHT_MID, 100, 0);                    //���������Ӷ����λ�ã��Ҳ���У�����X��ƫ��100 
}

void my_gui(void)
{
	//��̬��ȡ��Ļ��С
	scr_act_width = lv_obj_get_width(lv_scr_act());
	scr_act_height = lv_obj_get_height(lv_scr_act());
	
	/* ������ */
  parent_obj = lv_obj_create(lv_scr_act());                                   /* ���������� */
  lv_obj_set_size(parent_obj, scr_act_width * 2/3, scr_act_height * 2/3);     /* ���ø�����Ĵ�С */
  lv_obj_align(parent_obj, LV_ALIGN_TOP_MID, 0, 0);                           /* ���ø������λ�ã��������� */
  lv_obj_set_style_bg_color(parent_obj, lv_color_hex(0x99ccff), 0);           /* ���ø�����ı���ɫ��ǳ��ɫ */
  lv_obj_add_event_cb(parent_obj, obj_event_cb, LV_EVENT_LONG_PRESSED, NULL); /* Ϊ����������¼����������� */

  /* �Ӷ��� */
  child_obj = lv_obj_create(parent_obj);                                      /* �����Ӷ��� */
  lv_obj_set_size(child_obj, scr_act_width / 3, scr_act_height / 3);          /* �����Ӷ���Ĵ�С */
  lv_obj_align(child_obj, LV_ALIGN_CENTER, 0, 0);                             /* �����Ӷ����λ�ã����� */
  lv_obj_set_style_bg_color(child_obj, lv_color_hex(0x003366), 0);            /* �����Ӷ���ı���ɫ������ɫ */
  lv_obj_add_event_cb(child_obj, obj_event_cb, LV_EVENT_CLICKED, NULL);       /* Ϊ�Ӷ�������¼��������ͷź󴥷� */	
}
