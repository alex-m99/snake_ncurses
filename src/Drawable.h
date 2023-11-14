#ifndef DRAWABLE_H
#define DRAWABLE_H

class Drawable
{
    public:
        Drawable();
        Drawable(int y, int x, chtype ch);
        int getX();
        int getY();
        chtype getIcon();

    protected:
        int y, x;
        chtype icon;
};

#endif