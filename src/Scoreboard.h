#ifndef SCOREBOARD_H
#define SCOREBOARD_H

class Scoreboard
{
    public:
        Scoreboard();
        Scoreboard(int width, int y, int x);
        void initialize(int initial_score);
        void updateScore(int score);
        void clear();
        void refresh();
    private:
        WINDOW *score_win;
};

#endif