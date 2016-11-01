#include "items.h"

Item *getWeapon(Weapon choice)
{
  Item *weapon = (Item*)malloc(sizeof(Item));

  switch(choice)
  {
    case BASIC_SWD:
      weapon->value = 1;
      weapon->type = ONEHANDED;
      weapon->name = "Basic Sword";
      break;
  }

  return weapon;
}
