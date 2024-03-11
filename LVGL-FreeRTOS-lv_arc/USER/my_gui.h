#ifndef __MY_GUI_H
#define __MY_GUI_H
#include "lvgl.h"
#include "usart.h"

extern int value;
extern lv_obj_t *arc_left;              /* 左侧圆弧 */
extern lv_obj_t *arc_right;             /* 右侧圆弧 */
extern lv_obj_t *label_left;            /* 左侧百分比标签 */
extern lv_obj_t *label_right;           /* 右侧百分比标签 */

void my_gui(void);




#endif

