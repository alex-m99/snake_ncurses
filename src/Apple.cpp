#include <ncurses.h>
#include "Drawable.h"
#include "Apple.h"


Apple::Apple(int y, int x)
{
     this->y = y;
     this->x = x;
     this->icon = 'A';
 }
