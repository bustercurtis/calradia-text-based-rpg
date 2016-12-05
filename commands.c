#include"commands.h"
char **displayCommands(Character *player)
{
  char **ret;
  for(int i = 0; i < (sizeof(player->commands) / sizeof(int)); i++)
  {
    if(player->commands[i])
    {
      ret[i] = player->unlockOrder[i].desc;
    }
  }
  return ret;
}
int checkCommand(Character *player, char *command)
{
  for(int i = 0; i < (sizeof(player->commands) / sizeof(int)); i++)
  {
    char *curr = player->unlockOrder[i].name;
    if(!strncmp(curr, command, (int)(sizeof(curr) / sizeof(char))) && player->commands[i])
    {
      return 1;
    }
  }
  return 0;
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
  newCommand.desc = desc;
  return newCommand;
}
