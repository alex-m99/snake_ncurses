#ifndef SNAKEGAME_H
#define SNAKEGAME_H

//controller class

class SnakeGame
{
    public:
        SnakeGame(int height, int width, int speed);
        ~SnakeGame();
        void initialize();
        void processInput();
        void updateState();
        void redraw();
        bool isOver();
        int getScore();
    private:
        Board board;
        bool game_over;
        Apple *apple;
        Snake snake;
        Scoreboard scoreboard;
        int score;
        void createApple();
        void eatApple();
        void handleNextPiece(SnakePiece next);
};

#endif