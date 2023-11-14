#include <ncurses.h>
#include "Drawable.h"
#include "Empty.h"


Empty::Empty(int y, int x)
{
     this->y = y;
     this->x = x;
     this->icon = ' ';
 }
