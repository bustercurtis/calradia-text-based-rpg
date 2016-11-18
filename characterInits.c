#include"characterInits.h"
Character* initcharacter(float x, float y, float maxhealth, float health, float xp,
                        float nextlevel, float level, float attack, float onehanded, float bow, float twohanded,
                        float trade, float persuasion, float leadership, float money, float alive, float faction, 
                        float host, char name[32], char graphic)
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
  player->host = host;
  strcpy(player->name, name);
  player->graphic = graphic; //TODO char* to char in argument list, remove cast
  return player;
}

void initInventory(Character *character)
{
  Item empty;
  strcpy(empty.name, "Empty");
  for(int i = 0; i < 64; i++) //TODO use a MACRO for inventory size
  {
    character->inventory[i] = empty;
  }
  Item fists;
  fists.type = TWOHANDED;
  strcpy(fists.name, "fists");
  fists.value = 0;
  character->activeitems[0] = fists;
  Item noarmor;
  noarmor.type = ARMOR;
  strcpy(noarmor.name, "no armor");
  noarmor.value = 0;
  character->activeitems[1] = noarmor;
  return;
}

void initParty(Character *leader)
{
  Party party;
  party.morale = 50;
  Troop empty;
  empty.skill = -1;
  Troop bandit;
  strcpy(bandit.name, "Bandit");
  bandit.skill = 2;
  switch((int)leader->host){
    case 0:
      for(int i = 0; i < 100; i++)
      {
        party.troops[i] = empty;
      }
      break;
    case 1:
      if(0) //TODO faction #1
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
void initCommands(Character *player)
{
  BattleCommand basicCharge = createCommand(1, 1, 1, 0, 0, 1, 1, ALL, "charge", "charge - Basic charge");
  BattleCommand shockCharge = createCommand(0, 2, 3, 1, 0, 2, 1, CAVALRY, "scharge", "scharge - Cavalry charge in basic" 		"formation");
  BattleCommand shieldWall = createCommand(2, 2, 1, 1, 2, 0, 1, INFANTRY, "shield", "shield - Infantry form defensive" 		"shieldwall");
  BattleCommand cantabrian = createCommand(2, 3, 0, 1, 0, 0, 0, HORSE_ARCHER, "cantabrian", "cantabrian - Horse archers"
	"ride in circles and fire arrows");
  BattleCommand skirmish = createCommand(2, 1, 2, 1, 1, 0, 0, ARCHER, "skirmish", "skirmish - Archers fire arrows from a" 		"distance");
  BattleCommand schiltron = createCommand(3, 3, 0, 2, 3, 0, 1, INFANTRY, "schiltron", "schiltron - Infantry form tight defensive"
	"spear formation");
  BattleCommand feign = createCommand(0, 3, 3, 2, 0, 3, 1, CAVALRY, "feign", "feign - Cavalry pretend to charge then flee to" 		"tempt foes into attacking, then turn around and charge");
  BattleCommand deployStakes = createCommand(3, 2, 1, 2, 2, 0, 0, ARCHER, "stakes", "stakes - Archers drive stakes into" 		"the ground to gore enemy horses as they charge");
  BattleCommand parthian = createCommand(2, 3, 1, 2, 1, 0, 0, HORSE_ARCHER, "parthian", "parthian - Horse archers ride away from" 		"the enemy but face backwards and fire");
  BattleCommand heroicCharge = createCommand(2, 3, 3, 3, 1, 3, 1, INFANTRY, "charge", "charge - Infantry charge in a solid"
	"formation");
  BattleCommand couch = createCommand(3, 3, 3, 3, 0, 3, 1, CAVALRY, "couch", "couch - Cavalry couch lances and charge");
  BattleCommand ambush = createCommand(3, 3, 2, 3, 2, 2, 0, ARCHER, "ambush", "ambush - Archers hide in scrub and forest to"
	"surprise attack the enemy as they approach");
  BattleCommand caracole = createCommand(2, 2, 2, 3, 3, 3, 0, HORSE_ARCHER, "caracole", "caracole - Horse archers push forth"
	"and discharge, then retreat and repeat");
  BattleCommand unlockOrder[12] = {shockCharge, shieldWall, cantabrian, skirmish, schiltron, feign, deployStakes, parthian,
	heroicCharge, couch, ambush, caracole};
  player->unlockOrder = unlockOrder;
}
