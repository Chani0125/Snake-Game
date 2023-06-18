#include "draw.h"
#include "game_map.h"
#include <ncurses.h>
#include <iostream>

using namespace std;

void Draw()
{   
    

    start_color();
    
    WINDOW *playing_map = subwin(stdscr, play_map.size(), play_map[0].size(), 5, 5);
    init_pair(1, COLOR_RED, COLOR_WHITE);
    box(playing_map, 0, 0);
    attron(COLOR_PAIR(1));
    wbkgd(playing_map, COLOR_PAIR(1));

    WINDOW *score_board = subwin(stdscr, play_map.size()/2-3, play_map[0].size()/2+5, 5, 7+play_map[0].size());
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    attron(COLOR_PAIR(2));
    wbkgd(score_board, COLOR_PAIR(2));

    WINDOW *mission_board = subwin(stdscr, play_map.size()/2-3, play_map[0].size()/2+5, 5+play_map.size()/2, 7+play_map[0].size());
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    attron(COLOR_PAIR(2));
    wbkgd(mission_board, COLOR_PAIR(2));



    for(auto x : play_map){
        for(int y : x){
            if(y >= 0)
            wprintw(playing_map, "%d", y);
        }
        wprintw(playing_map, "\n");
    }

    wprintw(score_board, "current score");

    wprintw(mission_board, "body length\n");
    wprintw(mission_board, "growth\n");
    wprintw(mission_board, "poison\n");
    wprintw(mission_board, "gate\n");

    refresh();
    delwin(playing_map);
    getch();
}