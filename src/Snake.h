#ifndef SNAKE_H
#define SNAKE_H

class SnakePiece : public Drawable
{
    public:
        SnakePiece();
        SnakePiece(int y, int x);

};

class Snake
{

    public:
        Snake();
        void addPiece(SnakePiece piece);
        void removePiece();
        SnakePiece tail();
        SnakePiece head();
        enum Direction
        {
            up = -1 ,
            down = 1,
            left = -2,
            right = 2
        };
        Direction getDirection();
        void setDirection(Direction d);
        SnakePiece nextHead();
    
    private:
        std::queue<SnakePiece> prev_pieces;
        Direction cur_direction;
    
  
};

#endif