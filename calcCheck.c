#include"calcCheck.h"
int checkParty(Party *party)
{
  int size = 0;
  for(int i = 0; i < 100; i++)
  {
    if(party->troops[i].skill != -1)
    {
      size++;
    }
  }
  return size;
}

void showStats(Character *player)
{
  print("\n\n-----<|Stats|>-----\n%s, Level %g\nXP: %g/%g\nHealth: %g/%g\nAttack: %g\nTrade: %g\nPersuasion: %g\n"
         "Leadership: %g\n--Weapon Skills--\nOne Handed: %g\nBow: %g\nTwo Handed: %g\n", player->name, player->level,
         player->xp, player->nextlevel, player->health, player->maxhealth, player->attack, player->trade, player->persuasion,
         player->leadership, player->onehanded, player->bow, player->twohanded);
  return;
}
void checkLevel(Character *player)
{
  if(player->xp >= player->nextlevel)
  {
    player->level++;
    showStats(player);
    levelup(player);
  }
  return;
}
void showInventory(Character *player)
{
  print("\n\n----Active Items----\nWeapon: %s\nArmor: %s\n\n----Inventory----\n", player->activeitems[0].name,
         player->activeitems[1].name);
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j< 8; j++)
    {
      print("%s  ", player->inventory[(i*8 + j)].name);
    }
    print("\n");
  }
  print("\n");
  return;
}
int calcDamage(Character *player)
{
  double weaponmod = 0;
  if(player->activeitems[0].type == BOW)
  {
    weaponmod = player->bow;
  }
  if(player->activeitems[0].type == ONEHANDED)
  {
    weaponmod = player->onehanded;
  }
  if(player->activeitems[0].type == TWOHANDED)
  {
    weaponmod = player->twohanded;
  }
  int damage = ((player->attack + player->activeitems[0].value)/2)*(1 + weaponmod/100);
  return damage;
}
