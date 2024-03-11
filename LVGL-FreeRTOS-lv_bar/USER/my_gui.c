#include "my_gui.h"


/* ��ȡ��ǰ���Ļ�Ŀ�� */
#define scr_act_width() lv_obj_get_width(lv_scr_act())
#define scr_act_height() lv_obj_get_height(lv_scr_act())

static int16_t val = 0;                         /* ��ǰֵ */

static const lv_font_t *font;                   /* �������� */

static lv_obj_t *label_load;                    /* ���ر����ǩ */
static lv_obj_t *label_per;                     /* �ٷֱȱ�ǩ */
static lv_obj_t *bar;                           /* ������ */

/**
 * @brief  ��ʱ���ص�
 * @param  *timer ���ö�ʱ����ص�����
 * @return ��
 */
static void timer_cb(lv_timer_t *timer)
{
	if(val < 100)                                                           /* ��ǰֵС��100 */
  {
    val ++;
    lv_bar_set_value(bar, val, LV_ANIM_ON);                             /* ���õ�ǰֵ */
    lv_label_set_text_fmt(label_per, "%d %%", lv_bar_get_value(bar));   /* ��ȡ��ǰֵ��������ʾ */
  }
  else                                                                    /* ��ǰֵ���ڵ���100 */
  {
    lv_label_set_text(label_per, "finished!");                          /* ������� */
  }
}

/**
 * @brief  ������ʾ��ǩ
 * @param  ��
 * @return ��
 */
static void lv_example_label(void)
{
	/* ���ݻ��Ļ���ѡ������ */
  if (scr_act_width() <= 480)
    font = &lv_font_montserrat_14;
  else
    font = &lv_font_montserrat_20;
   
  /* ���ر����ǩ */
  label_load = lv_label_create(lv_scr_act());
  lv_label_set_text(label_load, "LOADING...");
  lv_obj_set_style_text_font(label_load, font, LV_STATE_DEFAULT);
  lv_obj_align(label_load, LV_ALIGN_CENTER, 0, -scr_act_height() / 10 );

  /* �ٷֱȱ�ǩ */
  label_per = lv_label_create(lv_scr_act());
  lv_label_set_text(label_per, "%0");
  lv_obj_set_style_text_font(label_per, font, LV_STATE_DEFAULT);
  lv_obj_align(label_per, LV_ALIGN_CENTER, 0, scr_act_height() / 10 );
}

/**
 * @brief  ���ؽ�����
 * @param  ��
 * @return ��
 */
static void lv_example_bar(void)
{
  bar = lv_bar_create(lv_scr_act());                            /* ���������� */
  lv_obj_set_align(bar, LV_ALIGN_CENTER);                       /* ����λ�� */
  lv_obj_set_size(bar, scr_act_width() * 3 / 5, 20);            /* ���ô�С */
  lv_obj_set_style_anim_time(bar, 100, LV_STATE_DEFAULT);       /* ���ö���ʱ�� */
  lv_timer_create(timer_cb, 100, NULL);                         /* ��ʼ����ʱ�� */
}

void my_gui(void)
{
  lv_example_label();                                           /* ������ʾ��ǩ */
  lv_example_bar();                                             /* ���ؽ����� */
}
