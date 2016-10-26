#include"characterInits.h"
Character* initcharacter(float x, float y, float maxhealth, float health, float xp,
                        float nextlevel, float level, float attack, float onehanded, float bow, float twohanded,
                        float trade, float persuasion, float leadership, float money, float alive, float faction, 
                        float host, char name[32], char *graphic)
{
  Character *player = (Character*)(malloc(sizeof(Character)));
  player->x = x;
  player->y = y;
  player->maxhealth = maxhealth;
  player->xp = xp;
  player->nextlevel = nextlevel;
  player->level = level;
  player->health = health;
  player->attack = attack;
  player->onehanded = onehanded;
  player->bow = bow;
  player->twohanded = twohanded;
  player->trade = trade;
  player->persuasion = persuasion;
  player->leadership = leadership;
  player->money = money;
  player->alive = alive;
  player->faction = faction;
  player->host = host;
  strcpy(player->name, name);
  player->graphic = graphic;
  return player;
}

void initinventory(Character *character)
{
  Item empty;
  empty.taken = 0;
  for(int i = 0; i < 400; i++)
  {
    character->inventory[i] = empty;
  }
  Item fists;
  fists.type = TWOHANDED;
  strcpy(fists.name, "fists");
  fists.damage = 0;
  character->activeitems[0] = fists;
  Item noarmor;
  noarmor.type = ARMOR;
  strcpy(noarmor.name, "no armor");
  noarmor.armor = 0;
  character->activeitems[1] = noarmor;
  return;
}

void initparty(Character *leader)
{
  Party party;
  Troop defaulttroop;
  party.morale = 50;
  defaulttroop.name[0] = 'i';
  Troop bandit;
  strcpy(bandit.name, "Bandit");
  bandit.skill = 2;
  switch((int)leader->host){
    case 0:
      for(int i = 0; i < 100; i++)
      {
        party.troops[i] = defaulttroop;
      }
      break;
    case 1:
      if(leader->faction == 1)
      {
        for(int i = 0; i < 20; i++)
        {
          party.troops[i] = bandit;
        }
      }
      break;
  }
  leader->party = party;
}
