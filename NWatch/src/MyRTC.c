#include "MyRTC.h"

/**
 * @brief RTC初始化
 * @return [无]
 */
void MyRTC_Init(void){
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP, ENABLE);

    PWR_BackupAccessCmd(ENABLE);
    if (BKP_ReadBackupRegister(BKP_DR1) != 0xA5A5)
    {
        RCC_LSEConfig(RCC_LSE_ON);
        while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) != SET);
        
        RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
        RCC_RTCCLKCmd(ENABLE);

        RTC_WaitForSynchro();
        RTC_WaitForLastTask();

        RTC_SetPrescaler(32768 - 1);
        RTC_WaitForLastTask();

        time_t time_cnt = 1672588795;
        MyRTC_SetTime(*localtime(&time_cnt));
        RTC_WaitForLastTask();

        BKP_WriteBackupRegister(BKP_DR1, 0xa5a5);
    } else{
        RTC_WaitForSynchro();
        RTC_WaitForLastTask();
    }

}

/**
 * @brief RTC设置时间
 * @param time [tm] 传入tm结构体,设置本地时间.默认为东八区
 * @return [无]
 */
void MyRTC_SetTime(struct tm time){
    time_t time_cnt;
    time_cnt = mktime(&time)-8*60*60;
    RTC_SetCounter(time_cnt);
    RTC_WaitForLastTask();
}

/**
 * @brief 读取当前时间
 * @return [sturct tm *] 返回当前时间,类型为tm的指针
 */
struct tm * MyRTC_ReadTime(void){
    time_t time_cnt;
    time_cnt = RTC_GetCounter()+8*60*60;

    return localtime(&time_cnt);
}