#ifndef __MY_GUI_H
#define __MY_GUI_H
#include "lvgl.h"
#include "usart.h"

extern int value;
extern lv_obj_t *arc_left;              /* ���Բ�� */
extern lv_obj_t *arc_right;             /* �Ҳ�Բ�� */
extern lv_obj_t *label_left;            /* ���ٷֱȱ�ǩ */
extern lv_obj_t *label_right;           /* �Ҳ�ٷֱȱ�ǩ */

void my_gui(void);




#endif

