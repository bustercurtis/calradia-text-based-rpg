#include<stdio.h>
#include<string.h>
#include"print.h"
#include"characterInits.h"
void intro(Character *player)
{
  print("\n\n------------~<|CALRADIA|>~------------\n"
         "---------text based adventure---------\n\n"
         "You were born in this harsh land, long\n"
         "torn apart by kings, disease, famine,\n"
         "and most pertinently - war. Ever since\n"
         "the empire fell apart, the land hasn't\n"
         "seen peace and the is now dominated by\n"
         "several vying feudal kingdoms, all with\n"
         "their own claims to the old empire and\n"
         "its people. But first - who are you?\n\n");
  Item basicsword;
  basicsword.value = 1;
  basicsword.type = ONEHANDED;
  strcpy(basicsword.name, "Basic Sword");
  Item basicarmor;
  basicarmor.value = 1;
  basicarmor.type = ARMOR;
  strcpy(basicarmor.name, "Basic Armor");
  Item basicbow;
  basicbow.value = 1;
  basicbow.type = BOW;
  strcpy(basicbow.name, "Basic Bow");
  char choice1 = 0;
  char choice2 = 0;
  char choice3 = 0;
  char choice4 = 0;
  print("----------~<|INTRODUCTION|>~----------\n"
         "\nWhat is your name?\n");
  fgets(player->name, sizeof(player->name), stdin);
  strtok(player->name, "\n");
  print("\n\nYou were born the son of a...\n"
         "1. merchant\n2. baron\n3. hunter\n4. peasant\n");
  while(choice1 < 49 || choice1 > 52)
  {
    scanf("%c", &choice1);
  }
  print("\n\nIn your childhood, you were a...\n"
         "1. assistant in a shop\n2. military student\n3. thief\n4. peasant\n");
  while(choice2 < 49 || choice2 > 52)
  {
    scanf("%c", &choice2);
  }
  print("\n\nThings changed, as they always do, and in your adulthood you became a...\n"
         "1. merchant\n2. soldier\n3. courtier\n4. peasant\n");
  while(choice3 < 49 || choice3 > 52)
  {
    scanf("%c", &choice3);
  }
  print("\n\nAnd you, %s, are a...\n"
         "1. Sarranid\n2. Khergit\n3. Swadian\n4. Nord\n5. Vaegir\n", player->name);
  while(choice4 < 49 || choice4 > 53)
  {
    scanf("%c", &choice4);
  }
  switch(choice1)
  {
    case '1':
      player->trade += 2;
      player->money += 15;
      player->persuasion += 1;
      break;
    case '2':
      player->attack += 1;
      player->money += 20;
      player->leadership += 1;
      break;
    case '3':
      player->attack += 2;
      player->bow += 30;
      player->money += 5;
      break;
    case '4':
      player->maxhealth += 2;
      player->health += 2;
      player->onehanded += 10;
      player->bow += 10;
      player->twohanded += 10;
      player->persuasion += 2;
      break;
  }
  switch(choice2)
  {
    case '1':
      player->trade += 2;
      player->money += 10;
      player->persuasion += 1;
      break;
    case '2':
      player->attack += 2;
      player->onehanded += 20;
      player->bow += 20;
      player->twohanded += 20;
      player->leadership += 1;
      break;
    case '3':
      player->trade += 3;
      player->bow += 10;
      player->persuasion += 1;
      player->money += 15;
      break;
    case '4':
      player->onehanded += 10;
      player->bow += 10;
      player->persuasion += 1;
      player->money += 5;
      break;
  }
  switch(choice3)
  {
    case '1':
      player->trade += 2;
      player->money += 30;
      player->persuasion += 2;
      break;
    case '2':
      player->attack += 3;
      player->onehanded += 30;
      player->bow += 30;
      player->twohanded += 30;
      player->maxhealth += 5;
      player->health += 5;
      player->leadership += 2;
      player->activeitems[0] = basicsword;
      player->activeitems[1] = basicarmor;
      break;
    case '3':
      player->persuasion += 4;
      player->money += 20;
      player->leadership += 1;
      break;
    case '4':
      player->activeitems[0] = basicbow;
      player->onehanded += 10;
      player->bow += 10;
      player->persuasion += 2;
      player->money += 10;
      break;
  }
  switch(choice4)
  {
    case '1':
      player->onehanded += 20;
      player->persuasion += 1;
      break;
    case '2':
      player->bow += 50;
      break;
    case '3':
      player->onehanded += 20;
      player->twohanded += 20;
      player->money += 10;
      player->leadership += 1;
      break;
    case '4':
      player->twohanded += 20;
      player->bow += 20;
      player->maxhealth += 5;
      player->health += 5;
      break;
    case '5':
      player->twohanded += 40;
      player->trade += 1;
      break;
  }
  return;
}
