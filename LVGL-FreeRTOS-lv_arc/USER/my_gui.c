#include "my_gui.h"


/* ��ȡ��ǰ���Ļ�Ŀ�� */
#define scr_act_width() 		lv_obj_get_width(lv_scr_act())
#define scr_act_height() 		lv_obj_get_height(lv_scr_act())

lv_obj_t *label_left = NULL;            /* ���ٷֱȱ�ǩ */
lv_obj_t *label_right= NULL;           /* �Ҳ�ٷֱȱ�ǩ */
lv_obj_t *arc_left = NULL;              /* ���Բ�� */
lv_obj_t *arc_right = NULL;             /* �Ҳ�Բ�� */

static const lv_font_t *font;           /* �������� */
static uint8_t arc_width;               /* Բ����� */

static int16_t val = 0;                         /* ��ǰֵ */

/**
 * @brief  Բ���¼��ص�
 * @param  *e ���¼���ز����ļ��ϣ��������˸��¼�����������
 * @return ��
 */
static void arc_event_cb(lv_event_t *e)
{
	lv_obj_t *target = lv_event_get_target(e);                                  /* ��ȡ����Դ */
  lv_event_code_t code = lv_event_get_code(e);                                /* ��ȡ�¼����� */

	if(code == LV_EVENT_VALUE_CHANGED)
  {
		lv_label_set_text_fmt(label_left, "%d%%", lv_arc_get_value(target));    /* ��ȡ��ǰֵ���������ٷֱȱ�ǩ */
    lv_label_set_text_fmt(label_right, "%d%%", lv_arc_get_value(target));   /* ��ȡ��ǰֵ�������Ҳ�ٷֱȱ�ǩ */
    lv_arc_set_value(arc_right, lv_arc_get_value(target));                  /* ��ȡ���Բ����ǰֵ�������Ҳ�Բ����ǰֵ */
  }
}

static void timer_cb(lv_timer_t *timer)
{
	if(val < 100)
	{
		val++;
		lv_arc_set_value(arc_right, val);
		lv_arc_set_value(arc_left, val);
		lv_label_set_text_fmt(label_left, "%d%%", lv_arc_get_value(arc_left));    /* ��ȡ��ǰֵ���������ٷֱȱ�ǩ */
    lv_label_set_text_fmt(label_right, "%d%%", lv_arc_get_value(arc_left));   /* ��ȡ��ǰֵ�������Ҳ�ٷֱȱ�ǩ */
	}
	else{
		val = 0;
	}
}


/**
 * @brief  ���Բ��
 * @param  ��
 * @return ��
 */
void lv_example_arc1(void)
{
	/* ���ݻ��Ļ���ѡ������ */
  if (scr_act_width() <= 480)
  {
    font = &lv_font_montserrat_14;
    arc_width = 10;
  }
  else
  {
    font = &lv_font_montserrat_30;
    arc_width = 20;
  }

  /* ���Բ�� */
  arc_left = lv_arc_create(lv_scr_act());                                     /* ����Բ�� */
  lv_obj_set_size(arc_left, scr_act_height() * 3/8, scr_act_height() * 3/8);  /* ���ô�С */
  lv_obj_align(arc_left, LV_ALIGN_CENTER, -scr_act_width()/5, 0);             /* ����λ�� */
  lv_arc_set_value(arc_left, 0);                                              /* ���õ�ǰֵ */
  lv_obj_set_style_arc_width(arc_left, arc_width, LV_PART_MAIN);              /* ���ñ�������� */
  lv_obj_set_style_arc_width(arc_left, arc_width, LV_PART_INDICATOR);         /* ����ǰ������� */
  lv_obj_add_event_cb(arc_left, arc_event_cb, LV_EVENT_VALUE_CHANGED, NULL);  /* ����¼� */

  /* ���ٷֱȱ�ǩ */
  label_left = lv_label_create(lv_scr_act());                                 /* �����ٷֱȱ�ǩ */
  lv_obj_align(label_left, LV_ALIGN_CENTER, -scr_act_width()/5, 0);           /* ����λ�� */
  lv_label_set_text(label_left, "0%");                                        /* �����ı� */
  lv_obj_set_style_text_font(label_left, font, LV_STATE_DEFAULT);             /* �������� */
	
	lv_timer_create(timer_cb,1000,NULL);
}

/**
 * @brief  �Ҳ�Բ��
 * @param  ��
 * @return ��
 */
void lv_example_arc2(void)
{
  /* �Ҳ�Բ�� */
  arc_right = lv_arc_create(lv_scr_act());                                    /* ����Բ�� */
  lv_obj_set_size(arc_right, scr_act_height() * 3/8, scr_act_height() * 3/8); /* ���ô�С */
  lv_obj_align(arc_right, LV_ALIGN_CENTER, scr_act_width()/5, 0);             /* ����λ�� */
  lv_arc_set_value(arc_right, 0);                                             /* ���õ�ǰֵ */
  lv_arc_set_bg_angles(arc_right, 0, 360);                                    /* ���ñ������Ƕ� */
  lv_arc_set_rotation(arc_right, 270);                                        /* ������ת�Ƕ� */
  lv_obj_remove_style(arc_right, NULL, LV_PART_KNOB);                         /* ȥ����ť */
  lv_obj_clear_flag(arc_right, LV_OBJ_FLAG_CLICKABLE);                        /* ȥ���ɵ������ */
  lv_obj_set_style_arc_width(arc_right, arc_width, LV_PART_MAIN);             /* ���ñ�������� */
  lv_obj_set_style_arc_width(arc_right, arc_width, LV_PART_INDICATOR);        /* ����ǰ������� */

  /* �Ҳ�ٷֱȱ�ǩ */
  label_right = lv_label_create(lv_scr_act());                                /* �����ٷֱȱ�ǩ */
  lv_obj_align(label_right, LV_ALIGN_CENTER, scr_act_width()/5, 0);           /* ����λ�� */
  lv_label_set_text(label_right, "0%");                                       /* �����ı� */
  lv_obj_set_style_text_font(label_right, font, LV_STATE_DEFAULT);            /* �������� */
}

int value = 0;
void my_gui(void)
{
	lv_example_arc1();       /* ���Բ�� */
  lv_example_arc2();       /* �Ҳ�Բ�� */
}
