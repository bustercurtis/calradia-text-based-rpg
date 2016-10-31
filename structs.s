#ifndef STRUCTS
#define STRUCTS
typedef enum {ARMOR, ONEHANDED, BOW, TWOHANDED, GOOD} Type;
typedef enum {INFANTRY, ARCHER, CAVALRY, HORSE_ARCHER, ALL} TroopType;
typedef struct
{
  float damage, armor;
  int taken;
  char name[32];
  Type type;
} Item;
typedef struct
{
  TroopType type;
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
typedef struct
{
  float againstcav, againstinfantry, againstarchers, quality, defensive, offensive;
  int melee;
  TroopType affects;
  char name[32];
} BattleCommand;
#endif
