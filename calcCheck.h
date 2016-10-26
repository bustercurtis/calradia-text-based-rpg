#ifndef CALC_CHECK
#define CALC_CHECK
#include<stdio.h>
#include"structs.s"
#include"print.h"
int checkparty(Party *party);
void showstats(Character *player);
void checklevel(Character *player);
void levelup(Character *player);
void showinventory(Character *player);
int calcdamage(Character **player);
#endif

