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
         " your purse.\n\nTWO NEW COMMANDS: flee, attack\nattack: basic attack against enemy\nflee: flee the battle\n");
  cont();
  int won = battle(player, introbandit);
  if(!won)
  {
    print("\nYour plans for adventure throughout Calradia\nare cut short by first person you meet.\nAfter looting your "
           "body, he leaves you in the street to bleed out.\n\nYou died.\n");
  }
  free(player);
  free(introbandit);
}
