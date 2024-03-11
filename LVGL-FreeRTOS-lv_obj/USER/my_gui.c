#include "my_gui.h"


static lv_coord_t scr_act_width,scr_act_height;				//活动屏幕宽度、高度
static lv_obj_t *parent_obj;													//父对象
static lv_obj_t *child_obj;														//子对象

static void obj_event_cb(lv_event_t *e)
{
	lv_obj_t* target = lv_event_get_target(e);			 //获取事件触发源
	if (target == parent_obj)                                                   //判断触发源：是不是父对象？
		lv_obj_align(parent_obj, LV_ALIGN_CENTER, 0, 0);                        //重新设置父对象的位置：居中 
  else if (target == child_obj)                                               //判断触发源：是不是子对象？ 
    lv_obj_align(child_obj, LV_ALIGN_RIGHT_MID, 100, 0);                    //重新设置子对象的位置：右侧居中，再向X轴偏移100 
}

void my_gui(void)
{
	//动态获取屏幕大小
	scr_act_width = lv_obj_get_width(lv_scr_act());
	scr_act_height = lv_obj_get_height(lv_scr_act());
	
	/* 父对象 */
  parent_obj = lv_obj_create(lv_scr_act());                                   /* 创建父对象 */
  lv_obj_set_size(parent_obj, scr_act_width * 2/3, scr_act_height * 2/3);     /* 设置父对象的大小 */
  lv_obj_align(parent_obj, LV_ALIGN_TOP_MID, 0, 0);                           /* 设置父对象的位置：顶部居中 */
  lv_obj_set_style_bg_color(parent_obj, lv_color_hex(0x99ccff), 0);           /* 设置父对象的背景色：浅蓝色 */
  lv_obj_add_event_cb(parent_obj, obj_event_cb, LV_EVENT_LONG_PRESSED, NULL); /* 为父对象添加事件：长按触发 */

  /* 子对象 */
  child_obj = lv_obj_create(parent_obj);                                      /* 创建子对象 */
  lv_obj_set_size(child_obj, scr_act_width / 3, scr_act_height / 3);          /* 设置子对象的大小 */
  lv_obj_align(child_obj, LV_ALIGN_CENTER, 0, 0);                             /* 设置子对象的位置：居中 */
  lv_obj_set_style_bg_color(child_obj, lv_color_hex(0x003366), 0);            /* 设置子对象的背景色：深蓝色 */
  lv_obj_add_event_cb(child_obj, obj_event_cb, LV_EVENT_CLICKED, NULL);       /* 为子对象添加事件：按下释放后触发 */	
}
