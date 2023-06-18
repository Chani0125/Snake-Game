#include <ncurses.h>
#include <iostream>
#include <vector>
#include <ctime>
#include "game_map.h"

using namespace std;

// unit: ms
int tick = 500;

int main()
{
    initscr();

    LoadMapFile();

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

    printw("[Play Map %d]\n", map_num);
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

    // int num = 0;
    // LoadMapFile();

    // cout << "[Map Test]" << "\n\n";

    // for (vector<vector<short>> m : map)
    // {
    //     cout << "[Map " << num++ << "]" << "\n";
    //     for (vector<short> x : m)
    //     {
    //         for (int y : x)
    //         {
    //             cout << y << " ";
    //         }
    //         cout << "\n";
    //     }
    //     cout << "\n";
    // }

    // int e;

    // do
    // {
    //     int map_num = CreateMap(false);
    //     cout << "[Play Map " << map_num << "]" << "\n";
    //     for (vector<short> x : play_map)
    //     {
    //         for (int y : x)
    //         {
    //             cout << y << " ";
    //         }
    //         cout << "\n";
    //     }
    //     cout << "\n";

    //     cin >> e;
    // } while (e);

    // return 0;
}
