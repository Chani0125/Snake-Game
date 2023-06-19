#include <ncurses.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <unistd.h>
#include "game_map.h"
#include "draw.h"
#include "snake.h"
#include "item.h"
#include "gate.h"

#define NUM_ITEM 3

using namespace std;

// unit: ms
int tick = 500;
int play_time = 0;

void InitGame();
void SetGame();
void TestGame();

int main()
{
    InitGame();

    Snake play_snake;
    vector<Item> play_items;
    // Gate play_gate;

    SetGame();

    // TestGame();

    StartScreen();
    LoadingScreen();

    while (true)
    {   
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

    initscr();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    noecho();
    curs_set(0);
}

void SetGame()
{

}

void TestGame()
{
    keypad(stdscr, true);

    mvprintw(10, 25, "Press Key");
    refresh();
    usleep(tick * 3000);

    clear();
    int key = getch();
    switch (key)
    {
    case KEY_UP:
        mvprintw(10, 25, "You Press Key: UP");
        break;
    case KEY_DOWN:
        mvprintw(10, 25, "You Press Key: DOWN");
        break;
    case KEY_LEFT:
        mvprintw(10, 25, "You Press Key: LEFT");
        break;
    case KEY_RIGHT:
        mvprintw(10, 25, "You Press Key: RIGHT");
        break;
    default:
        mvprintw(10, 25, "You Press Key: NONE");
        break;
    }
    refresh();

    usleep(tick * 3000);
}