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


    // printw("[Play Map %d]\n", played_stage_history.back());
    // mvwprintw(stdscr, 0, 0, "[Play Map %d]\n", played_stage_history.back());

    for(int i = 0; i < play_map.size()-1; i++){
        for(int j = 0; j < play_map[i].size()-1; j++){
            wprintw(playing_map, "%d", play_map[i][j]);
        }
        // wprintw(playing_map, "\n");
    }

    refresh();
    delwin(playing_map);
    getch();
}