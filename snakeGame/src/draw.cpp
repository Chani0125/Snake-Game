#include "draw.h"
#include "game_map.h"
#include "mission.h"
#include <ncurses.h>
#include <unistd.h>
#include <iostream>

#define START_H 1
#define START_W 2
#define MAIN_GAME_H (MAP_H+2)
#define MAIN_GAME_W (MAP_W*2+3)
#define BOARD_W 32

using namespace std;

extern int tick;
extern int play_time;
extern int num_tick;

extern Mission *play_mission;
extern GameInfo* play_info;

WINDOW *playing_map, *score_board, *mission_board;

void ScreenUpdate()
{
    clear();

    // SetGameWindow();
    ScreenMap();
    ScreenBoard();

    // refresh();

    getch();
}

void SetGameWindow()
{
    start_color();

    playing_map = subwin(stdscr, (MAIN_GAME_H), (MAIN_GAME_W), (START_H), (START_W));
    // init_pair(1, COLOR_RED, COLOR_WHITE);
    // box(playing_map, 0, 0);
    // attron(COLOR_PAIR(1));
    // wbkgd(playing_map, COLOR_PAIR(1));

    score_board = subwin(stdscr, (MAIN_GAME_H / 2 - (1 - (MAIN_GAME_H % 2)) + 2), (BOARD_W), (START_H), (START_W + MAIN_GAME_W + 2));
    // init_pair(2, COLOR_BLACK, COLOR_GREEN);
    // attron(COLOR_PAIR(2));
    // wbkgd(score_board, COLOR_PAIR(2));

    mission_board = subwin(stdscr, (MAIN_GAME_H / 2 - 2), (BOARD_W), (START_H + (MAIN_GAME_H / 2) + (MAIN_GAME_H % 2) + 2), (START_W + MAIN_GAME_W + 2));
    // init_pair(2, COLOR_BLACK, COLOR_GREEN);
    // attron(COLOR_PAIR(2));
    // wbkgd(mission_board, COLOR_PAIR(2));
}

void ScreenMap(char snake_head)
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
                element_print = '@';
                break;
            case 3:
                element_print = snake_head;
                break;
            case 4:
                element_print = 'o';
                break;
            case 5:
                element_print = 'G';
                break;
            case 6:
                element_print = '+';
                break;
            case 7:
                element_print = '-';
                break;
            default:
                continue;
            }
            mvwprintw(playing_map, i+1, j*2+1, " %c", element_print);

            // mvwprintw(playing_map, i+1, j*2+1, " %d", play_map[i][j]);
        }
    }
}

void ScreenBoard()
{
    ScreenScoreBoard();
    ScreenMissionBoard();
}

void ScreenScoreBoard()
{
    mvwprintw(score_board, 1, 2, "[Score Board]");

    mvwprintw(score_board, 3, 2, "STAGE        : %d", STAGE);
    mvwprintw(score_board, 4, 2, "TICK         : %d ms", tick);
    mvwprintw(score_board, 5, 2, "Play Time    : %d s", play_time / 1000);
    mvwprintw(score_board, 6, 2, "Stage Time   : %d s", tick * num_tick / 1000);

    mvwprintw(score_board, 8, 2, "Body Length  : %d / %d", play_info->body_len, play_info->max_body_len);
    mvwprintw(score_board, 9, 2, "Eaten Growth : %d", play_info->n_growth);
    mvwprintw(score_board, 10, 2, "Eaten Poison : %d", play_info->n_poison);
    mvwprintw(score_board, 11, 2, "Use Gate     : %d", play_info->n_gate);
}

void ScreenMissionBoard()
{
    mvwprintw(mission_board, 1, 2, "[Mission - STAGE %d]", STAGE);

    mvwprintw(mission_board, 3, 2, "Body Length  : %d", play_mission->goal.body_len); mvwprintw(mission_board, 3, 21, "(%c)", play_mission->achieve[0] ? 'v' : ' ');
    mvwprintw(mission_board, 4, 2, "Eaten Growth : %d", play_mission->goal.n_growth); mvwprintw(mission_board, 4, 21, "(%c)", play_mission->achieve[1] ? 'v' : ' ');
    mvwprintw(mission_board, 5, 2, "Eaten Poison : %d", play_mission->goal.n_poison); mvwprintw(mission_board, 5, 21, "(%c)", play_mission->achieve[2] ? 'v' : ' ');
    mvwprintw(mission_board, 6, 2, "Use Gate     : %d", play_mission->goal.n_gate  ); mvwprintw(mission_board, 6, 21, "(%c)", play_mission->achieve[3] ? 'v' : ' ');
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
    mvprintw(10, 25, "        Snake Game");
    mvprintw(11, 25, "Press UP key to continue.");
    refresh();
    while(getch() != KEY_UP);
}

void NewStage()
{
    clear();
    SetGameWindow();

    ScreenMap();
    ScreenBoard();
    
    mvwprintw(playing_map, MAP_H/2-2, MAP_W-15, " ############################### ");
    mvwprintw(playing_map, MAP_H/2-1, MAP_W-15, " #                             # ");
    mvwprintw(playing_map, MAP_H/2,   MAP_W-15, " #          STAGE %03d          # ", STAGE);
    mvwprintw(playing_map, MAP_H/2+1, MAP_W-15, " #  Press RIGHT key to start.  # ");
    mvwprintw(playing_map, MAP_H/2+2, MAP_W-15, " #                             # ");
    mvwprintw(playing_map, MAP_H/2+3, MAP_W-15, " ############################### ");

    refresh();

    while(getch() != KEY_RIGHT);
}


void NextStage()
{
    clear();
    SetGameWindow();

    ScreenMap();
    ScreenBoard();
    
    mvwprintw(playing_map, MAP_H/2-2, MAP_W-15, " ############################### ");
    mvwprintw(playing_map, MAP_H/2-1, MAP_W-15, " #                             # ");
    mvwprintw(playing_map, MAP_H/2,   MAP_W-15, " #        STAGE CLEAR!!        # ");
    mvwprintw(playing_map, MAP_H/2+1, MAP_W-15, " #  Press UP key to continue.  # ");
    mvwprintw(playing_map, MAP_H/2+2, MAP_W-15, " #                             # ");
    mvwprintw(playing_map, MAP_H/2+3, MAP_W-15, " ############################### ");

    refresh();

    while(getch() != KEY_UP);
}

void GameOver()
{
    clear();
    SetGameWindow();

    ScreenMap('X');
    ScreenBoard();
    
    mvwprintw(playing_map, MAP_H/2-2, MAP_W-15, " ############################### ");
    mvwprintw(playing_map, MAP_H/2-1, MAP_W-15, " #                             # ");
    mvwprintw(playing_map, MAP_H/2,   MAP_W-15, " #         GAME OVER!!         # ");
    mvwprintw(playing_map, MAP_H/2+1, MAP_W-15, " #    Press UP key to exit.    # ");
    mvwprintw(playing_map, MAP_H/2+2, MAP_W-15, " #                             # ");
    mvwprintw(playing_map, MAP_H/2+3, MAP_W-15, " ############################### ");

    refresh();
    
    usleep(tick * 1000);
    while(getch() != KEY_UP);
}