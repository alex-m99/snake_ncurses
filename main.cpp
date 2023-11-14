#include <ncurses.h>
#include <queue>
#include <iostream>
#include "src/Drawable.h"
#include "src/Board.h"
#include "src/Apple.h"
#include "src/Empty.h"
#include "src/Snake.h"
#include "src/Scoreboard.h"
#include "src/Time.h"
#include "src/SnakeGame.h"

#define BOARD_DIM 12
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5

int main(int argc, char **argv)
{

    initscr();
    refresh();

    noecho();

    curs_set(0);

    SnakeGame game(BOARD_ROWS, BOARD_COLS, 200);

    while(!game.isOver())
    {
        game.processInput();

        game.updateState();

        game.redraw();
    }
   

    //getch();
    endwin();

    std::cout << "You scored: " << game.getScore() << " points!" << std::endl;

    return 0;
}