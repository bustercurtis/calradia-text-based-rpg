#include"commands.h"
BattleCommand shockCharge = createCommand(0, 2, 3, 1, 0, 2, 1, CAVALRY, "scharge", "scharge - Cavalry charge in basic formation");
BattleCommand shieldWall = createCommand(2, 2, 1, 1, 2, 0, 1, INFANTRY, "shield", "shield - Infantry form defensive shieldwall");
BattleCommand cantabrian = createCommand(2, 3, 0, 1, 0, 0, 0, HORSE_ARCHER, "cantabrian", "cantabrian - Horse archers"
                                                                                          "ride in circles and fire arrows");
BattleCommand skirmish = createCommand(2, 1, 2, 1, 1, 0, 0, ARCHER, "skirmish", "skirmish - Archers fire arrows from a distance");
BattleCommand schiltron = createCommand(3, 3, 0, 2, 3, 0, 1, INFANTRY, "schiltron", "schiltron - Infantry form tight defensive"
										    "spear formation");
BattleCommand feign = createCommand(0, 3, 3, 2, 0, 3, 1, CAVALRY, "feign", "feign - Cavalry pretend to charge then flee to tempt"
									   "foes into attacking, then turn around and charge");
BattleCommand deployStakes = createCommand(3, 2, 1, 2, 2, 0, 0, ARCHER, "stakes", "stakes - Archers drive stakes into the ground"
										  "to gore enemy horses as they charge");
BattleCommand parthian = createCommand(2, 3, 1, 2, 1, 0, 0, HORSE_ARCHER, "parthian", "parthian - Horse archers ride away from"
										      "the enemy but face backwards and fire");
BattleCommand heroicCharge = createCommand(2, 3, 3, 3, 1, 3, 1, INFANTRY, "charge", "charge - Infantry charge in a solid"
										    "formation");
BattleCommand couch = createCommand(3, 3, 3, 3, 0, 3, 1, CAVALRY, "couch", "couch - Cavalry couch lances and charge");
BattleCommand ambush = createCommand(3, 3, 2, 3, 2, 2, 0, ARCHER, "ambush", "ambush - Archers hide in scrub and forest to"
								            "surprise attack the enemy as they approach");
BattleCommand caracole = createCommand(2, 2, 2, 3, 3, 3, 0, HORSE_ARCHER, "caracole", "caracole - Horse archers push forth"
										      "and discharge, then retreat and"
										      "repeat");
BattleCommand unlockOrder[12] = {};
void displayCommands(Character *player)
{
  char **ret;
  for(int i = 0; i < (sizeof(commands)/sizeof(int)); i++)
  {
    if(commands[i])
    {
      ret[i] = unlockOrder[i].desc;
    }
  }
}
char **checkCommands(int *commands)
{
}
BattleCommand createCommand(float anticav, float antiinfantry, float antiarchers, float quality, 
			    float defensive, float offensive, int melee, TroopType affects, char *name, char *desc)
{
  BattleCommand newCommand;
  newCommand.anticav = anticav;
  newCommand.antiinfantry = antiinfantry;
  newCommand.antiarchers = antiarchers;
  newCommand.quality = quality;
  newCommand.defensive = defensive;
  newCommand.offensive = offensive;
  newCommand.melee = melee;
  newCommand.affects = affects;
  newCommand.name = name;
  return newCommand;
}
