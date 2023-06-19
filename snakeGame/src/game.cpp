#include <ncurses.h>
#include <iostream>
#include <vector>
#include <ctime>
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
void TestGame();

int main()
{
    initscr();

    InitGame();

    Snake play_snake;
    vector<Item> play_items;

    SetGame();

    TestGame();

    // StartScreen();
    // LoadingScreen();

    int key;
    while (true)
    {   
        // clear();
        // key = getch();
        // switch (key)
        // {
        // case KEY_UP:
        //     printw("You Press Key: UP\n");
        //     break;
        // case KEY_DOWN:
        //     printw("You Press Key: DOWN\n");
        //     break;
        // case KEY_LEFT:
        //     printw("You Press Key: LEFT\n");
        //     break;
        // case KEY_RIGHT:
        //     printw("You Press Key: RIGHT\n");
        //     break;
        // default:
        //     break;
        // }
        ScreenUpdate();
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