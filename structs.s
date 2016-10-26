#ifndef STRUCTS
#define STRUCTS
typedef enum {ARMOR, ONEHANDED, BOW, TWOHANDED, GOOD} Type;
typedef struct
{
  float damage, armor;
  int taken;
  char name[32];
  Type type;
} Item;
typedef struct
{
  double skill;
  char name[32];
} Troop;
typedef struct
{
  Troop troops[100];
  double morale;
} Party;
typedef struct
{
  float x, y, maxhealth, xp, nextlevel, level, health, attack, onehanded, bow, twohanded, trade,
    persuasion, leadership, money, alive, visible, faction, host;
  char name[32];
  char *graphic;
  Party party;
  Item inventory[400];
  Item activeitems[2];
} Character;
#endif
