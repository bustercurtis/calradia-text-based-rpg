#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<stdarg.h>
#include"intro.h"
#include"print.h"
#include"characterInits.h"
#include"fighting.h"
#include"calcCheck.h"
#include"cont.h"
void die(Character *player);
int main()
{
  Character *player = (Character*)malloc(sizeof(initcharacter(15,15,20,20,0,100,1,3,10,10,10,1,1,1,0,1,0,0,"Player",'x'))); 
  player = initcharacter(15,15,20,20,0,100,1,3,10,10,10,1,1,1,0,1,0,0,"Player",'x');
  initParty(player);
  initInventory(player);
  intro(player);
  showInventory(player);
  showStats(player);
  Character *introbandit = (Character*)malloc(sizeof(initcharacter(15,15,20,20,0,0,0,2,0,0,0,0,0,0,0,1,1,0, "Robber", 'c')));
  introbandit = initcharacter(15,15,20,20,0,0,0,2,0,0,0,0,0,0,0,1,1,0, "Robber", 'c');
  initInventory(introbandit);
  initParty(introbandit);
  print("\nAre you ready to start your adventure, %s?\n", player->name);
  cont();
  print("\nIt's late at night as you enter Dhirim.\nThe streets are deserted, and there's a distinctly cold breeze.\n"
         "Suddenly you hear a blade rasping from its scabard.\nBefore you understand what's happening, he has demanded"
         " your purse.\n\nTHREE NEW COMMANDS: flee, attack, block\nattack: basic attack against enemy\nflee: flee the battle\n"
	 "block: defend up to 5 points of \ndamage and deal a small amount in a counterattack\n");
  cont();
  int won = battle(player, introbandit);
  if(!won)
  {
    print("\nYour plans for adventure throughout Calradia\nare cut short by first person you meet.\nAfter looting your "
           "body, he leaves you in the street to bleed out.\n\nYou died.\n");
  }
  print("\nA merchant, who apparently witnessed the whole thing,\nsteps out into the street and helps you into\n"
	"his home. He gives you food and water, and tells \nyou his proposition.\n\nHis brother, he tells you,"
	"has been kidnapped and he needs you to \nraise some men to fight the bandit party.\n\nDo you accept? (y/n)\n");
  char response;
  while(response != 'y' || response != 'n')
  {
    scanf("%c", &response);
  }
  if(response == 'n')
  {
    print("\nThe merchant, disappointed, lets you out and wishes you luck.\n");
  }
  else
  {
    //brotherKidnapped();
  }
  Troop peasant;
  peasant.skill = 1;
  addTroop(&(player->party), peasant);
  free(player);
  free(introbandit);
}
