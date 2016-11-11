#include "map.h"

void printMap(Tile ***map) //OK daddy
{
  char out = 0;

  for(int row = 0; map[row][0] != '\0'; row++)
  {
    for(int col = 0; map[row][col] != '\0'; col++)
    {
      switch(map[row][col]->terrain)
      {
        case Plain:
	  out = ' ';
	  break;
	case Forest:
	  out = '.';
	  break;
	case Hills:
	  out = '_';
	  break;
        default:
	  out = ' ';
	  break;
      }

      //overrides terrain type
      switch(map[row][col]->structure)
      {
        case Village:
	  out = '^';
	  break;
	case Castle:
	  out = '#';
	  break;
	default:
	  out = ' ';
	  break;
      }

      putchar(out);
    }
  }
}
