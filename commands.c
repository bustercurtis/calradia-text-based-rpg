#include"commands.h"
void displayCommands(Character *player)
{
  char **ret;
  for(int i = 0; i < (sizeof(player->commands)/sizeof(int)); i++)
  {
    if(player->commands[i])
    {
      ret[i] = player->unlockOrder[i].desc;
    }
  }
}
char **checkCommands(int *commands)
{
  char *gay = "fuck you";
  char **ret = &gay;
  return ret;
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
  strcpy(newCommand.name, name);
  return newCommand;
}
