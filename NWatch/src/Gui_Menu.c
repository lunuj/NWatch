/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2023-12-26 22:09:43
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2023-12-26 23:40:16
 * @FilePath: /NWatch/src/Gui_Menu.c
 * @Description: 
 * 
 * Copyright (c) 2023 by ${lunuj}, All Rights Reserved. 
 */
#include "Gui_Menu.h"

struct Gui_Menu
{
    const uint8_t * pic;
    const uint8_t * name;
    struct Gui_Menu * last;
    struct Gui_Menu * next;
} gui_menu;

void Gui_Menu_Init(){

}

void Gui_Menu_Sign(){
   
}
