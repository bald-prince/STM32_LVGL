#ifndef _LED_H
#define _LED_H
#include "sys.h"

//LED¶Ë¿Ú¶¨Òå
#define LED0(n)		(n?HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET))
#define LED0_TOGGLE()    do{ HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1); }while(0) 
#define LED1(n)		(n?HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET))
#define LED1_Toggle() do{ HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0); }while(0) 

void LED_Init(void);
#endif
