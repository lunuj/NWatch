#ifndef __MYRTC_H__
#define __MYRTC_H__
#include "stm32f10x.h"
#include <time.h>

void MyRTC_Init(void);

void MyRTC_SetTime(struct tm time);

struct tm *MyRTC_ReadTime(void);

#endif // __MYRTC_H__

