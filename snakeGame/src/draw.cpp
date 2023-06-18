#include "draw.h"
#include "game_map.h"
#include <ncurses.h>
#include <iostream>

using namespace std;

void Draw()
{   
    clear();
    printw("[Play Map %d]\n", played_stage_history.back());
    for (vector<short> x : play_map)
    {
        for (int y : x)
        {
            printw("%d ", y);
        }
        printw("\n");
    }
    refresh();
    getch();
}