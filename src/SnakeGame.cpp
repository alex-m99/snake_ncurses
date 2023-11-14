#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <queue>
#include "Drawable.h"
#include "Board.h"
#include "Apple.h"
#include "Empty.h"
#include "Snake.h"
#include "Scoreboard.h"
#include "SnakeGame.h"

SnakeGame::SnakeGame(int height, int width, int speed)
{
    board = Board(height, width, speed);
    int sb_row = board.getStartRow() + height;
    int sb_col = board.getStartCol();
    scoreboard = Scoreboard(width, sb_row, sb_col);
    initialize();
}
SnakeGame::~SnakeGame()
{
    delete apple;
}

void SnakeGame::initialize()
{
    apple = NULL;
    board.initialize();
    score = 0;
    scoreboard.initialize(score);
    game_over = false;
    srand(time(NULL));

    snake.setDirection(Snake::down);

    handleNextPiece(SnakePiece(1, 1));
    handleNextPiece(snake.nextHead());
    handleNextPiece(snake.nextHead());
    snake.setDirection(Snake::right);
    handleNextPiece(snake.nextHead());

    if (apple == NULL)
    {
        createApple();
    }
}

void SnakeGame::processInput()
{
    chtype input = board.getInput();

    int old_timeout = board.getTimeout();

    switch (input)
    {
    case KEY_UP:
    case 'w':
        snake.setDirection(Snake::up);
        break;

    case KEY_DOWN:
    case 's':
        snake.setDirection(Snake::down);
        break;

    case KEY_RIGHT:
    case 'd':
        snake.setDirection(Snake::right);
        break;

    case KEY_LEFT:
    case 'a':
        snake.setDirection(Snake::left);
        break;

    case 'p':
        board.setTimeout(-1);
        while (board.getInput() != 'p')
            ;

        board.setTimeout(old_timeout);
        break;

    default:
        break;
    }
}

void SnakeGame::updateState()
{

    handleNextPiece(snake.nextHead());

    if (apple == NULL)
    {
        createApple();
    }
}

void SnakeGame::redraw()
{
    board.refresh();
    scoreboard.refresh();
}

bool SnakeGame::isOver()
{
    return game_over;
}

void SnakeGame::createApple()
{
    int y, x;
    board.getEmptyCoordinates(y, x);
    apple = new Apple(y, x);
    board.add(*apple);
}

void SnakeGame::handleNextPiece(SnakePiece next)
{
    if(apple != NULL)
    {
        switch (board.getCharAt(next.getY(), next.getX()))
        {
            case 'A':
                eatApple();
                break;
            
            case ' ':
            {
                int emptyRow = snake.tail().getY();
                int emptyCol = snake.tail().getX();
                board.add(Empty(emptyRow, emptyCol));
                snake.removePiece();
                break;
            }
            default:
                game_over = true;
                break;
        }
    }
   
    board.add(next);
    snake.addPiece(next);
}

void SnakeGame::eatApple()
{
    delete apple;
    apple = NULL;
    score += 100;
    scoreboard.updateScore(score);
}

int SnakeGame::getScore()
{
    return score;
}