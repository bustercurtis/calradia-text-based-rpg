#include"mainQuests.h"
int brotherKidnapped(Character *player)
{
  print("\nThe merchant thanks you, and you walk out of the house together.\n");
  cont();
  print("You walk down to the town square, where a group of 5 peasants are\ndrinking together. The merchant approaches them.\n");
  print("Merchant of Dhirim: 'I found you boys a leader.'\n");
  if(player->attack > 4)
  {
    print("Swadian Peasant: 'Looks like a good enough warrior to me.'\n");
    print("Merchant of Dhirim: 'Indeed. Now, to arms. We're going to save Trenad.'\n");
  }
  else
  {
    print("Swadian Peasant: 'Doesn't look like a warrior to me.'\n");
    print("Merchant of Dhirim: 'I couldn't care less what he looks like to you. He's a solid\nlad, and he's going to help us"
          "get Trenad back.\nNow, get off your asses. We're leaving.\n");
  }
  cont();
  print("The merchant waves you off and wishes you the best of luck as you leave Dhirim.\nYou follow the 5 men to the bandit"
        "lair where they believe Trenad is.\nYou only realize what you've gotten into when you see the walls\nand heads that"
	"adorn them.\n");
  cont();
  print("Swadian Peasant: 'There they are. We're gonna have to take 'em head on.'\n");
  
  cont();
  int won = battle(
