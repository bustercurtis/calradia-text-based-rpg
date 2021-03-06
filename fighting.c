#include"fighting.h"
int FOUGHT = 0;
int battle(Character *player, Character *enemy)
{
  int battling = 1;
  print("\n\nYou have encountered %s's party. They have %d troops.\n", enemy->name,
         checkParty(&enemy->party));
  if(checkParty(&enemy->party) > 5 && checkParty(&player->party) == 0)
  {
    print("\nAs you approach to fight the enemy, all %d of %s's men surround you.\nThere is no chance of victory"
          ", and you are quickly defeated.\n", checkParty(&enemy->party), enemy->name);
    print("\nBattle lost.\n");
    int death = rand() % 20;
    if(death == 7)
    {
      print("You lay there, sputtering for air through the blood pumping up your throat.\nYou feel your attackers"
             "loot your twitching body, and suddenly panic overtakes you as you realize\n that this is the last time"
             "you're going to open your eyes.\n\nYou died.\n");
    }
    else{return 0;}
  }
  if(checkParty(&enemy->party) > 5 && checkParty(&player->party) == 0)
  {
    print("\nAs you approach to fight the enemy, %s stands there, surrounded by your men.\nVictory is swift.\n"
          "\n", enemy->name);
    print("\nBattle won!\n");
    showStats(player);
    return 1;
  }
  else if(checkParty(&enemy->party) == 0 && checkParty(&player->party) == 0)
  {
    return fight(player, enemy);
  }
  else
  {
    print("\nYour men arrive at the battlefield and you see %s's party waiting on the other end.\n"
           "The time for battle has come.\n", enemy->name);
    if(!FOUGHT)
    {
      print("\nFIVE NEW COMMANDS: charge, scharge, skirmish, shield, cantabrian\n");
      for(int i = 0; i < 5; i++)
      {
	print("%s\n", player->unlockOrder[i].desc);
      }
      FOUGHT = 1;
    }
    while(battling)
    {
      print("\nYou must decide what the infantry will do...\n");
      char infCommand[16];
      scanf("%s", infCommand);
      print("%s", infCommand);
      if(checkCommand(player, infCommand, INFANTRY)){return 1;}
      
    }
  }
}
int fight(Character *player, Character *enemy)
{
  print("\n%s approaches you. Prepare for a fight...\n", enemy->name);
  cont();
  int fighting = 1;
  time_t t;
  int lead;
  srand((unsigned) time(&t));
  lead = rand() % 5;
  switch(lead)
  {
    case 0:
      print("\nYour eyes lock...only one man with honor will still stand.\n");
      break;
    case 1:
      print("\nYou focus on the man with extreme intensity...no move will go unnoticed.\n");
      break;
    case 2:
      print("\nYou circle eachother, waiting for an opportune time to strike.\n");
      if(checkParty(&(player->party)) > 0 && checkParty(&(enemy->party)) > 0)
      {
        print("Only once an arrow lands near your foot do you remember that this\nis a battle, not a duel.\n");
      }
      break;
    case 3:
      print("\nYou grip your %s tighter as the man inches closer.\n", player->activeitems[0].name);
      break;
    case 4:
      print("\nYou feel the feel the weight of your armor on your body.\n");
      break;
    case 5:
      print("\nThe thought of possible death eres in your mind as the"
             "\n man's %s becomes clearer.\n", enemy->activeitems[0].name);
      break;
  }
  while(fighting)
  {
    if(player->health < 0)
      {
      int randdeath = rand() % 20;
      if(randdeath == 7)
      {
        print("\nAs you fall to the ground you feel the blood in your\nneck throb and it becomes difficult to breathe.\n"
               "Suddenly, panic sets in as you realize that these are\nyour last moments.\n\nFinally, the pains stops and"
               " you are at peace.\n\n\nYou Died\n");
        cont();
        exit(0);
      }
      else
      {
        print("\nYou are knocked to the ground, unconscious.\nYour men panic.\n");
        cont();
        player->party.morale -= 10;
        return 0;
      }
    }
    char* fightchoice = (char*)(malloc(sizeof(char[16])));
    print("\n--Your Health--\n%g/%g\n\n--Enemy Health--\n%g/%g\n", player->health, player->maxhealth,
          enemy->health, enemy->maxhealth);
    print("\nThe time has come to plan your next move...\n");
    scanf("%s", fightchoice);
    if(!strncmp(fightchoice, "flee", 4))
    {
      print("\nYou run from the enemy, ");
      if(!checkParty(&player->party))
      {
        print("a shameful display of cowardice.\n");
        cont();
        return 0;
      }
      else
      {
        print("striking fear into the hearts of your men.\n");
        cont();
        player->party.morale -= 5;
        return 0;
      }
    }
    else if(!strncmp(fightchoice, "attack", 6))
    {
      if(player->health > 0)
      {
        int pdamage = calcDamage(player);
        print("\nYou attack with your %s, dealing %d damage.\n", player->activeitems[0].name, pdamage);
        enemy->health -= pdamage;
      }
      if(enemy->health > 0)
      {
        int edamage = calcDamage(enemy);
        player->health -= edamage;
        cont();
        print("\nYour enemy fights back with his %s, dealing %d damage!\n", enemy->activeitems[0].name, edamage);
      }
      else
      {
        float xpgained = 4*enemy->attack;
        player->xp += xpgained;
        print("\nYour enemy falls before you. You have won your fight.\n\n--Health--\n%g/%g\n\n--XP Gained--\n%gxp"
               "\n--XP--\n%g/%g\n", player->health, player->maxhealth, xpgained, player->xp, player->nextlevel);
        cont();
        return 1;
      }
    }
    else if(!strncmp(fightchoice, "block", 5))
    {
      int pdamage = (calcDamage(player) - 3);
      if(player->health > 0)
      {
        print("\nYou prepare to defend yourself.\n");
	cont();
        if(pdamage < 1)
        {
          pdamage = 1;
        }
        enemy->health -= pdamage;
      }
      if(enemy->health > 0)
      {
	print("\nYour enemy attacks you with his %s, ", enemy->activeitems[0].name);
	int edamage = calcDamage(enemy) - 5;
        if(edamage < 0)
	{
	  edamage = 0;
	  print("but you manage to \nblock all damage, dealing %d in return!\n", pdamage);
	}
	else
	{
	  print("and despite your block\nhe manages to \ndeal %d damage, and you deal %d in a counter.\n", edamage, pdamage);
        }
	player->health -= edamage;
     }
     else
     {
	print("\nYour enemy attacks you, but you block it and kill him in your counter!\n");
        float xpgained = 4*enemy->attack;
        player->xp += xpgained;
        print("\nYou have won your fight.\n\n--Health--\n%g/%g\n\n--XP Gained--\n%gxp"
               "--XP--\n%g/%g\n", player->health, player->maxhealth, xpgained, player->xp, player->nextlevel);
        cont();
        return 1;
      }
    }
    else
    {
      print("\nInvalid commmand. In your confusion, your enemy strikes.\n");
      int edamage = calcDamage(enemy);
      player->health -= edamage;
      cont();
      print("\nYour enemy fights back with his %s, dealing %d damage!\n", enemy->activeitems[0].name, edamage);
    }
  }
  return 1;
}
