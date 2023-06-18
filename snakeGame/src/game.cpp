#include <ncurses.h>
#include <iostream>
#include <vector>
#include <ctime>
#include "game_map.h"

using namespace std;

// unit: ms
int tick = 500;

void InitGame();

int main()
{
    initscr();

    InitGame();

    for (int i = 0; i < map.size(); i++)
    {
        printw("[Map %d]\n", i);
        for (vector<short> x : map[i])
        {
            for (int y : x)
            {
                printw("%d ", y);
            }
            printw("\n");
        }
        refresh();
        getch();
        clear();
    }

    int map_num = CreateMap();

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

    endwin();
    return 0;
}

void InitGame()
{
    LoadMapFile();
    CreateMap(0);
}