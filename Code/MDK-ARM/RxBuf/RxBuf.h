#ifndef __RXBUF_H__
#define __RXBUF_H__

#include "stdio.h"
#include "stdint.h"
#include "usart.h"

#define HUART huart3
#define RingBufferSize 57
#define TRUE 1
#define FALSE 0

typedef struct RingBufferStruct{
	int in;
	int out;
	char Buffer[RingBufferSize];
}stRingBuf; 

int IsRingBufFull(stRingBuf *ringBuf);
int IsRingBufEmpty(stRingBuf *ringBuf);
int WriteOneByte(stRingBuf *ringBuf,uint8_t data);
int ReadOneByte(stRingBuf *ringBuf,uint8_t *data);

void Analysis_RING(void);
extern uint8_t RxBuffer[14];
extern uint8_t RealRxBuffer[14];
extern uint8_t DMARxBuffer[14];
extern uint8_t flag_click;//Êó±ê°´¼ü
extern int8_t X_move;
extern int8_t Y_move;
extern int8_t scroll_move;
extern int8_t SUM_X_move;
extern int8_t SUM_Y_move;
extern int8_t SUM_scroll_move;
#endif
