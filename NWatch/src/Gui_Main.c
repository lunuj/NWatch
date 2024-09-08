#include "Gui_Main.h"
struct tm time_dates; // 定义日期时间数据类型
int up                 = 1;
u8 time_old[12]        = {127,127,127,127,127,127,127,127,127,127,127,127};
u8 time_new[12]        = {127,127,127,127,127,127,127,127,127,127,127,127};
XBM_Num_Type XBM_Num[] = {
    {12, 16, XBM_NUM_XS},
    {16, 16, XBM_NUM_S},
    {16, 32, XBM_NUM_M},
    {18, 32, XBM_NUM_L},
};

void Gui_Main_Init()
{
    time_dates.tm_year = 2023 - 1900 ; // 将数组的时间赋值给日期时间结构体
    time_dates.tm_mon  = 12 - 1;
    time_dates.tm_mday = 26;
    time_dates.tm_hour = 22;
    time_dates.tm_min  = 17;
    time_dates.tm_sec  = 49;
    MyRTC_Init();
    MyRTC_SetTime(time_dates);
}

void Gui_Main_Draw_num(int x, int y, int num, XBM_Num_Type num_type)
{
    for (int i = 0; i < num_type.height / 8; i++) {
        for (int j = 0; j < num_type.width; j++) {
            u8 a                    = num_type.pic[num][i * num_type.width + j];
            Grame[i + y / 8][j + x] = a;
        }
    }
}

void Gui_Main_Draw_nums(int x, int y, int num, XBM_Num_Type num_type)
{
    if (num < 0) {
        // 显示负号
        num = (-1) * num;
    }

    int count = Get_Num_10_N(num);
    while (count != 1) {
        int a = (num * 10 / count) % 10;
        Gui_Main_Draw_num(x, y, a, num_type);
        count /= 10;
        x += num_type.width;
    }
}

int Get_Num_10_N(int num)
{
    int x = 1;
    if (num < 0) {
        num = (-1) * num;
    } else if (num == 0) {
        return 0;
    }
    while (num != 0) {
        num /= 10;
        x *= 10;
    }
    return x;
}

void Gui_Main_Draw_Char(int x, int y, char c)
{
    for (int i = 0; i < 16 / 8; i++) {
        for (int j = 0; j < 8; j++) {
            u8 a                    = XBM_Char[c - ' '][i * 8 + j];
            Grame[i + y / 8][j + x] = a;
        }
    }
}

void Gui_Main_Draw_Char_Spe(int x, int y, const u8 *pic, int width, int height)
{
    for (int i = 0; i < height / 8; i++) {
        for (int j = 0; j < width; j++) {
            u8 a                    = pic[i * width + j];
            Grame[i + y / 8][j + x] = a;
        }
    }
}

void Gui_Main_Draw_String(int x, int y, char *c)
{
    int i = 0;
    while (c[i] != '\0') {
        Gui_Main_Draw_Char(x, y, c[i]);
        x += 8;
        i++;
    }
}

void Gui_Main_Draw_Data()
{
    struct tm *time_date = MyRTC_ReadTime();
    time_new[6] = (time_date->tm_year) % 100 / 10;
    time_new[7] = (time_date->tm_year) % 10;
    time_new[8] = (time_date->tm_mon) % 100 / 10;
    time_new[9] = (time_date->tm_mon) % 10  + 1;
    time_new[10] = (time_date->tm_mday) % 100 / 10;
    time_new[11] = (time_date->tm_mday) % 10;
    for (int i = 11; i >= 6; i--) {
        if (time_old[i] != time_new[i]) {
            Gui_Main_Num_Change(time_new[i], 12 * (i-6) + ((i-6) / 2) * 4, 0, XBM_Num[0], 2);
            time_old[i] = time_new[i];
        }
    }
    Gui_Main_Draw_Char_Spe(24,0, XBM_Char_Spe_16[1],4,16);
    Gui_Main_Draw_Char_Spe(52,0, XBM_Char_Spe_16[1],4,16);
    Gui_DrawGrame();
    
}

void Gui_Main_Draw_Clock()
{
    u8 a                 = 0;
    struct tm *time_date = MyRTC_ReadTime();
    time_new[0]          = (time_date->tm_hour) % 100 / 10;
    time_new[1]          = (time_date->tm_hour) % 10;
    time_new[2]          = (time_date->tm_min) % 100 / 10;
    time_new[3]          = (time_date->tm_min) % 10;
    time_new[4]          = (time_date->tm_sec) % 100 / 10;
    time_new[5]          = (time_date->tm_sec) % 10;
    for (int i = 5; i >= 0; i--) {
        if (time_old[i] != time_new[i]) {
            Gui_Main_Num_Change(time_new[i], 18 * i + (i / 2) * 10, 16, XBM_Num[3], 2);
            if (i == 0) {
                Gui_Main_Draw_Data();
            }
            time_old[i] = time_new[i];
            a           = 1;
        }
    }
    if (a == 1) {
        up *= (-1);
        if (up == 1) {
            Gui_Main_Draw_Char_Spe(36, 16, XBM_Char_Spe_10[0], 10, 32);
            Gui_Main_Draw_Char_Spe(82, 16, XBM_Char_Spe_10[0], 10, 32);
            Gui_DrawGrame();
        } else {
            Gui_Main_Draw_Char_Spe(36, 16, XBM_Char_Spe_10[4], 10, 32);
            Gui_Main_Draw_Char_Spe(82, 16, XBM_Char_Spe_10[4], 10, 32);
            Gui_DrawGrame();
        }
    }

    // Gui_Main_Draw_Char_Spe(48,48,XBM_Char_Spe_8[0],4,8);
    // Gui_Main_Draw_Char_Spe(39,24, XBM_Char_Spe_16[0],4,16);
    // Gui_Main_Draw_Char_Spe(39+10+36,24, XBM_Char_Spe_16[0],4,16);

}

void Gui_Main_Num_Change(int num, int x, int y, XBM_Num_Type num_type, int speed)
{
    u8 thumb[8][32] = {0};
    for (int sp = 0; sp < num_type.height / 8; sp++) {

        for (int j = 0; j < num_type.width; j++) {
            u8 a = (num_type.pic)[num][sp * num_type.width + j];
            for (int k = 0; k < 8; k++) {
                thumb[k][j] = ((a << (7 - k)) % 0x0100) / 0x80;
            }
        }
        for (int k = 0; k < 8; k += speed) {
            Gui_Transform8T64();
            for (int i = y; i < y + num_type.height; i++) {
                for (int j = x; j < x + num_type.width; j++) {
                    Grames[i][j] = Grames[i + speed][j];
                }
            }
            for (int j = speed; j > 0; j--) {
                for (int i = 0; i < num_type.width; i++) {
                    Grames[y + num_type.height - j][i + x] = thumb[k + speed - j][i];
                }
            }

            Gui_Transform64T8();
            Gui_DrawGrame();
        }
    }
}