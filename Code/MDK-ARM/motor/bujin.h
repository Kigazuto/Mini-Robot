#ifndef __DIAN_JI_H__
#define __DIAN_JI_H__

#include "main.h"
#include "gpio.h"
#include "my_lib.h"

#define up 1
#define down 0

extern int AutoReload_data;	//自动重装载值
extern int MaiChong;	//脉冲
extern int QuanShu;	//圈数

void dianji_init(void);
void dianji_set(void);
void dianji_kongzhi(int fangxiang,int sudu,int zhuoqi);	//方向，速度

#endif

