#ifndef BOARD_H
#define BOARD_H

//view class

class Board
{
    public:
        Board();
        Board(int height, int width, int speed); 
        void initialize(); //method that initializes the game board by using all of the other methods
        void addBorder(); //adds the border to the game window
        void addAt(int y, int x, chtype ch);//adds char at y x coordinates
        void add(Drawable drawable);
        chtype getInput(); //gets char input from game window
        void getEmptyCoordinates(int &y, int &x);
        chtype getCharAt(int y, int x); //returns whatever char is at coord y x
        void clear(); //clears the window and adds the border
        void refresh(); //refreshes the window
        void setTimeout(int timeout);
        int getTimeout();
        int getStartRow();
        int getStartCol();
    
    private:
        WINDOW *board_win;
        int height, width, start_row, start_col;
        int timeout;
        void construct(int heignt, int width, int speed);

};

#endif