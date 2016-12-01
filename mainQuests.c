#include"mainQuests.h"
int brotherKidnapped(Character *player)
{
  /*
  Troop peasant;
  peasant.skill = 1;
  for(int i = 0; i < 5; i++){
    addTroop(&(player->party), peasant);
  }
  print("\nThe merchant thanks you, and you walk out of the house together.\n");
  cont();
  print("You walk down to the town square, where a group of 5 peasants are\ndrinking together. The merchant approaches them.\n");
  print("Merchant of Dhirim: 'I found you boys a leader.'\n");
  cont();
  if(player->attack > 4)
  {
    print("Swadian Peasant: 'Looks like a good enough warrior to me.'\n");
    cont();
    print("Merchant of Dhirim: 'Indeed. Now, to arms. We're going to save Trenad.'\n");
    cont();
  }
  else
  {
    print("Swadian Peasant: 'Doesn't look like a leader to me.'\n");
    cont();
    print("Merchant of Dhirim: 'I couldn't care less what he looks like to you.\nHe's a solid lad, and he's going to help us"
          " get Trenad back.\nNow, get off your asses. We're leaving.\n");
    cont();
  }
  print("The merchant waves you off and wishes you the best of luck as you \nleave Dhirim. You follow the 5 men to the bandit"
        " lair where they \nbelieve Trenad is.\n");
  cont();
  print("You only realize what you've gotten into when you see the walls\nand heads that"
	" adorn them.\n");
  cont();
  print("Swadian Peasant: 'There they are. We're gonna have to take 'em head on.'\n");
  cont();
  */
  Character *kidnapper = initcharacter(15,15,20,20,0,0,0,2,0,0,0,0,0,0,0,1,1,0, "Kidnapper", 'c');
  Troop kidnapperHenchman;
  initParty(kidnapper);
  initInventory(kidnapper);
  kidnapperHenchman.skill = 0;
  for(int i = 0; i < 5; i++)
  {
    addTroop(&(kidnapper->party), kidnapperHenchman);
  }
  int won = battle(player, kidnapper);
  return 1;
}
