#include"structs.s"
#include<stdlib.h>
#include<string.h>
#ifndef ITEMS
#define ITEMS

typedef enum {BASIC_SWD} Weapon;

Item *getWeapon(Weapon weapon);

#endif
