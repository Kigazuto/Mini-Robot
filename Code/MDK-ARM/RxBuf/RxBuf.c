#include "RxBuf.h"
#include "stdio.h"
#include "string.h"


uint8_t RealRxBuffer[14];
uint8_t DMARxBuffer[14];
uint8_t RxBuffer[14];
uint8_t TxBuffer = 'c';
uint8_t flag_click;//Êó±ê°´¼ü
int8_t X_move;
int8_t Y_move;
int8_t scroll_move;
 int8_t SUM_X_move;
 int8_t SUM_Y_move;
 int8_t SUM_scroll_move;
int IsRingBufFull(stRingBuf *ringBuf)
{
	if((ringBuf->in + 1)%RingBufferSize == ringBuf->out)
	return TRUE;
	return FALSE;
}
int IsRingBufEmpty(stRingBuf *ringBuf)
{
	if(ringBuf->in == ringBuf->out) return TRUE;
	return FALSE;
}
int WriteOneByte(stRingBuf *ringBuf,uint8_t data)
{
	if(ringBuf == NULL) return FALSE;
	if(IsRingBufFull(ringBuf)) return FALSE;
	ringBuf->Buffer[ringBuf->in] = data;
	ringBuf->in = (++ringBuf->in)%RingBufferSize;
	return TRUE;
}
int ReadOneByte(stRingBuf *ringBuf,uint8_t *data)
{
	if(ringBuf == NULL) return FALSE;
	if(IsRingBufEmpty(ringBuf)) return FALSE;
	*data = ringBuf->Buffer[ringBuf->out];
	ringBuf->out = (++ringBuf->out)%RingBufferSize;
	return TRUE;
}
uint8_t Temp_Data[12] = {0};
void Analysis_RING(void)
{
	uint8_t tmp[4] = {0};
	uint8_t Flag_P;

	for(int i=0;i<14;i++)
	if(RxBuffer[i] == 0x57 && RxBuffer[(i+1)%14] == 0xAB && RxBuffer[(i+2)%14] == 0x88 && RxBuffer[(i+3)%14] == 0x0A && RxBuffer[(i+4)%14] == 0x21)  
		Flag_P = i;
	int j=0;
	while(j<12)
	{
		Temp_Data[j] = RxBuffer[(Flag_P + j + 1)%14];
		j++;
	}
	memcpy(RealRxBuffer,Temp_Data,14);
	
	memcpy(tmp,&RealRxBuffer[6],1);
    flag_click=*(uint8_t*)tmp;
	memcpy(tmp,&RealRxBuffer[7],2);
	X_move=*(int8_t*)tmp;
    SUM_X_move+=X_move;
	memcpy(tmp,&RealRxBuffer[9],2);
	Y_move=*(int8_t*)tmp;
    SUM_Y_move+=Y_move;
	memcpy(tmp,&RealRxBuffer[11],1);
	scroll_move=*(int8_t*)tmp;
    SUM_scroll_move+=scroll_move;


}


