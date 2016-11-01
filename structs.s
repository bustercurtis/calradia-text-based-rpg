#ifndef STRUCTS
#define STRUCTS
typedef enum {ARMOR, ONEHANDED, BOW, TWOHANDED, GOOD} Type;
typedef enum {INFANTRY, ARCHER, CAVALRY, HORSE_ARCHER, ALL} TroopType;
typedef struct
{
  float value;
  char *name;
  Type type;
} Item;
typedef struct
{
  TroopType type;
  double skill;
  char *name;
} Troop;
typedef struct
{
  Troop troops[100];
  double morale;
} Party;
typedef struct
{
  float x, y, maxhealth, xp, nextlevel, level, health, attack, onehanded, bow, twohanded, trade,
    persuasion, leadership, money, host;
  char *name;
  char graphic;
  Party party;
  Item inventory[64];
  Item activeitems[2];
  int commands[10];
} Character;
typedef struct
{
  float anticav, antiinfantry, antiarchers, quality, defensive, offensive;
  int melee;
  TroopType affects;
  char *name;
} BattleCommand;
#endif
