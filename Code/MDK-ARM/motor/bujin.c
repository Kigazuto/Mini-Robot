#include "bujin.h"
#include "tim.h"

void dianji_init(void)
{
}
void  dianji_kongzhi(int fangxiang,int sudu,int zhuoqi)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, fangxiang);
	__HAL_TIM_SetAutoreload(&htim3,sudu);		//设置速度快慢
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, (sudu/2));//设置脉冲  用不到
	QuanShu=zhuoqi;
}

