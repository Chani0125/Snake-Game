#include <ncurses.h>
#include <iostream>
#include <cstdlib>
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
void TestGame();

int main()
{
    InitGame();

    // TestGame();

    StartScreen();
    LoadingScreen();

    bool snake_live = true;
    while (true)
    {   
        // if (!snake_live)
        //     break;
        
        if (STAGE == 0)
            CreateMap(0);
        else
            CreateMap(false);
        
        Snake play_snake;
        vector<Item> play_items;
        vector<int> generate_item_time = {0, 10, 20};
        Gate play_gate;

        NewStage();

        while (true)
        {   

            if(!(snake_live = play_snake.move()))
            {
                GameOver();
                break;
            }
            
            ScreenUpdate();
            usleep(tick * 1000);
            play_time += tick;
        }


    }

    endwin();
    return 0;
}

void InitGame()
{
    srand(time(NULL));

    LoadMapFile();

    initscr();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    noecho();
    curs_set(0);
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