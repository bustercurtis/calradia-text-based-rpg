#ifndef CALC_CHECK
#define CALC_CHECK
#include<stdio.h>
#include <string.h>
#include"structs.s"
#include"print.h"
int checkParty(Party *party);
void addTroop(Party *party, Troop troop);
void showStats(Character *player);
void checkLevel(Character *player);
void levelup(Character *player);
void showInventory(Character *player);
int calcDamage(Character *player);
#endif

