#include <ncurses.h>
#include <iostream>
#include <vector>
#include <ctime>
#include "game_map.h"
#include "draw.h"

using namespace std;

// unit: ms
int tick = 500;

void InitGame();

int main()
{
    initscr();

    InitGame();

    // for (int i = 0; i < map.size(); i++)
    // {
    //     printw("[Map %d]\n", i);
    //     for (vector<short> x : map[i])
    //     {
    //         for (int y : x)
    //         {
    //             printw("%d ", y);
    //         }
    //         printw("\n");
    //     }
    //     refresh();
    //     getch();
    //     clear();
    // }

    Draw();

    endwin();
    return 0;
}

void InitGame()
{
    LoadMapFile();
    CreateMap(0);
}