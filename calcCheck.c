#include"calcCheck.h"
int checkparty(Party *party)
{
  int size = 0;
  for(int i = 0; i < 100; i++)
  {
    if(party->troops[i].name[0] != 'i')
    {
      size++;
    }
  }
  return size;
}

void showstats(Character *player)
{
  print("\n\n-----<|Stats|>-----\n%s, Level %g\nXP: %g/%g\nHealth: %g/%g\nStrength: %g\nTrade: %g\nPersuasion: %g\n"
         "Leadership: %g\n--Weapon Skills--\nOne Handed: %g\nBow: %g\nTwo Handed: %g\n", player->name, player->level,
         player->xp, player->nextlevel, player->health, player->maxhealth, player->attack, player->trade, player->persuasion,
         player->leadership, player->onehanded, player->bow, player->twohanded);
  return;
}
void checklevel(Character *player)
{
  if(player->xp >= player->nextlevel)
  {
    player->level++;
    showstats(player);
    levelup(player);
  }
  return;
}
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
  return;
}
void showinventory(Character *player)
{
  print("\n\n----Active Items----\nWeapon: %s\nArmor: %s\n\n----Inventory----\n", player->activeitems[0].name,
         player->activeitems[1].name);
  int emptynum = 0;
  for(int i = 0; i < 400; i++)
  {
    if(player->inventory[i].taken)
    {
      print("%s\n", player->inventory[i].name);
    }
    emptynum++;
  }
  if(emptynum == 400)
  {
    print("Empty");
  }
  print("\n");
  return;
}
int calcdamage(Character **player)
{
  double weaponmod = 0;
  if((*player)->activeitems[0].type == BOW)
  {
    weaponmod = (*player)->bow;
  }
  if((*player)->activeitems[0].type == ONEHANDED)
  {
    weaponmod = (*player)->onehanded;
  }
  if((*player)->activeitems[0].type == TWOHANDED)
  {
    weaponmod = (*player)->twohanded;
  }
  int damage = (((*player)->attack + (*player)->activeitems[0].damage)/2)*(1 + weaponmod/100);
  return damage;
}
