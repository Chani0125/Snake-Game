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
#include "item_growth.h"
#include "item_poison.h"
#include "gate.h"

#define NUM_ITEM 3

using namespace std;

// unit: ms
int tick = 500;
int num_tick = 0;
int play_time = 0;

void InitGame();
Item* makeItem();

void TestGame();

int main()
{
    InitGame();

    // TestGame();

    StartScreen();
    LoadingScreen();

    // TODO: Item 생성

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
        vector<Item*> play_items(3, nullptr);
        // vector<int> generate_item_time = {0, 10, 20};
        Gate play_gate;
        num_tick = 0;

        NewStage();

        SetGameWindow();

        while (true)
        {   
            if (!snake_live == play_snake.move())
            {
                GameOver();
                break;
            }

            if (num_tick == 0)
                play_items[0] = makeItem();
            else if (num_tick == 10 + (3 * 1000 / tick))
                play_items[1] = makeItem();
            else if (num_tick == 20 + (6 * 1000 / tick))
                play_items[2] = makeItem();

            for (int i = 0; i < 3; i++)
            {
                if (play_items[i] == nullptr)
                    break;
                if(play_items[i]->Check(play_snake.GetHead()) == false)
                {   
                    play_items[i]->Hide(play_snake.GetHead());
                    delete play_items[i];
                    play_items[i] = makeItem();
                }
            }

            ScreenUpdate();
            usleep(tick * 1000);
            play_time += tick;
            num_tick++;
        }

        tick = ((tick - 50) * (STAGE / 2 + 4) / (STAGE / 2 + 5)) + 50;
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

Item* makeItem()
{
    auto it = play_map_point[0].begin();
    int tmp = rand() % play_map_point[0].size();
    for (int i = 0; i < tmp; i++) it++;

    Item* ans = nullptr;

    int item_type = rand() % 2;
    switch (item_type)
    {
    case 0:
        ans = new GrowthItem(*it);
        break;
    case 1:
        ans = new PoisonItem(*it);
        break;
    default:
        break;
    }

    // play_map[(*it).x][(*it).y] = 6 + item_type;

    play_map_point[0].erase(it);

    return ans;
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