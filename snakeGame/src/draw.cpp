#include "draw.h"
#include "game_map.h"
#include <ncurses.h>
#include <unistd.h>
#include <iostream>

#define START_H 2
#define START_W 4
#define MAIN_GAME_H (MAP_H+2)
#define MAIN_GAME_W (MAP_W*2+3)
#define BOARD_W 32

using namespace std;

void ScreenUpdate()
{
    clear();

    start_color();

    WINDOW *playing_map = subwin(stdscr, (MAIN_GAME_H), (MAIN_GAME_W), (START_H), (START_W));
    init_pair(1, COLOR_RED, COLOR_WHITE);
    box(playing_map, 0, 0);
    attron(COLOR_PAIR(1));
    wbkgd(playing_map, COLOR_PAIR(1));

    WINDOW *score_board = subwin(stdscr, (MAIN_GAME_H / 2 - (1 - (MAIN_GAME_H % 2))), (BOARD_W), (START_H), (START_W + MAIN_GAME_W + 2));
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    attron(COLOR_PAIR(2));
    wbkgd(score_board, COLOR_PAIR(2));

    WINDOW *mission_board = subwin(stdscr, (MAIN_GAME_H / 2), (BOARD_W), (START_H + (MAIN_GAME_H / 2) + (MAIN_GAME_H % 2)), (START_W + MAIN_GAME_W + 2));
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    attron(COLOR_PAIR(2));
    wbkgd(mission_board, COLOR_PAIR(2));

    char element_print;
    for (int i = 0; i < MAP_H; i++)
    {
        // wmove(playing_map, 1 + i, 2);
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
            
            // wprintw(playing_map, "%c", play_map[i][j] + '0');
            mvwprintw(playing_map, i+1, j*2+1, " %c", element_print);
        }
        // wprintw(playing_map, "\n");
    }

    wprintw(score_board, "current score");

    wprintw(mission_board, "body length\n");
    wprintw(mission_board, "growth\n");
    wprintw(mission_board, "poison\n");
    wprintw(mission_board, "gate\n");

    refresh();

    getch();
}

void LoadingScreen()
{
    for (int i = 0; i < 2; i++)
    {
        for (int y = 0; y < 4; y++)
        {
            clear();
            mvprintw(10, 35, "Loading");
            for (int x = 0; x < y; x++)
            {
                printw(".");
            }
            printw("\n");
            refresh();
            usleep(125 * 1000);
        }
    }
}

void StartScreen()
{
    clear();
    mvprintw(10, 25, "         Snake Game");
    mvprintw(11, 25, "Press any key to continue.");
    refresh();
    getch();
}