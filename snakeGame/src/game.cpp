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

    // TestGame();

    StartScreen();

    LoadingScreen();

    while (true)
    {
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
    char element_print;
    for (int i = 0; i < MAP_H; i++)
    {
        for (int j = 0; j < MAP_W; j++)
        {
            switch (play_map[i][j])
            {
            case 0:
                element_print = ' ';
                break;
            case 1:
            case 2:
                element_print = '+';
                break;
            default:
                continue;
            }
                
            printf("%c ", element_print);
        }
        printf("\r\n");
    }

    getchar();
}