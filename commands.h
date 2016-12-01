#ifndef COMMANDS
#define COMMANDS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structs.s"
#include"print.h"
char **displayCommands(Character *player);
int checkCommand(Character *player, char *command);
BattleCommand createCommand(float anticav, float antiinfantry, float antiarchers, float quality, 
			    float defensive, float offensive, int melee, TroopType affects, char *name, char *desc);
#endif
