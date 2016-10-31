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
int calcdamage(Character *player)
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
  int damage = ((player->attack + player->activeitems[0].damage)/2)*(1 + weaponmod/100);
  return damage;
}
