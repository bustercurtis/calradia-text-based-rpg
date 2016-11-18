#ifndef CHARACTER_INITS
#define CHARACTER_INITS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structs.s"
#include"commands.h"
Character* initcharacter(float x, float y, float maxhealth, float health, float xp,
                        float nextlevel, float level, float attack, float onehanded, float bow, float twohanded,
                        float trade, float persuasion, float leadership, float money, float alive,
                        float faction, float host, char name[32], char graphic);
void initParty(Character *leader);
void initInventory(Character *player);
void initCommands(Character *player);
#endif
