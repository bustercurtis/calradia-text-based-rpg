#ifndef STRUCTS
#define STRUCTS
#define MAX_CHAR_PER_TILE 4
typedef enum {ARMOR, ONEHANDED, BOW, TWOHANDED, GOOD} Type;
typedef enum {INFANTRY, ARCHER, CAVALRY, HORSE_ARCHER, ALL} TroopType;
typedef struct
{
  float value;
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
  float anticav, antiinfantry, antiarchers, quality, defensive, offensive;
  int melee;
  TroopType affects;
  char *name, *desc;
} BattleCommand;
typedef struct
{
  float x, y, maxhealth, xp, nextlevel, level, health, attack, onehanded, bow, twohanded, trade,
    persuasion, leadership, money, host;
  char name[32];
  char graphic;
  Party party;
  Item inventory[64];
  Item activeitems[2];
  int commands[13];
  BattleCommand unlockOrder[13];
} Character;
typedef enum {Plain, Forest, Hills} Terrain;
typedef enum {None, Village, Castle} Structure;
typedef struct {
  Terrain terrain;
  Structure structure;
  Character characters[MAX_CHAR_PER_TILE];
} Tile;
#endif
