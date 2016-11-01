#include"level.h"
void levelup(Character *player)
{
  int choice;
  print("\n\nWhich skill would you like to level up?\n\n1. Health\n2. Strength\n3. Trade\n4. Persuasion\n"
         "5. Leadership\n");
  scanf("%d", &choice);
  switch(choice){
    case 1:
      player->maxhealth += 5;
      player->health += 5;
      break;
    case 2:
      player->attack += 2;
      break;
    case 3:
      player->trade += 1;
      break;
    case 4:
      player->persuasion += 1;
      break;
    case 5:
      player->leadership += 1;
      break;
  }
  showStats(player);
  return;
}
