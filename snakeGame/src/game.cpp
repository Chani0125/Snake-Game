#include <ncurses.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <unistd.h>
#include <unistd.h>
#include "game_map.h"
#include "draw.h"
#include "snake.h"
#include "item.h"

#define NUM_ITEM 3

using namespace std;

// unit: ms
int tick = 500;
int play_time = 0;

void InitGame();
void SetGame();

int main()
{
    initscr();

    InitGame();

    Snake play_snake;
    vector<Item> play_items;

    SetGame();

    while (true)
    {
        Draw();
        usleep(tick * 1000);
        play_time += tick;
    }

    endwin();
    return 0;
}

void InitGame()
{
    LoadMapFile();
    CreateMap(0);
}

void SetGame()
{

}