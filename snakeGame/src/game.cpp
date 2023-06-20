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
#include "mission.h"

#define NUM_ITEM 3

using namespace std;

// unit: ms
int tick = 500;
int num_tick = 0;
int play_time = 0;

void InitGame();
Item* makeItem();
Gate* makeGate();
Mission* play_mission;
GameInfo* play_info;

void TestGame();

int main()
{
    InitGame();

    // TestGame();

    StartScreen();
    LoadingScreen();
    
    play_mission = new Mission();
    bool snake_live = true;

    while (snake_live)
    {   
        if (STAGE == 0)
            CreateMap(0);
        else
            CreateMap(false);
        
        Snake play_snake;
        vector<Item*> play_items(3, nullptr);
        Gate *play_gate = nullptr;
        play_info = new GameInfo();
        play_mission->SetMission();
        num_tick = 0;

        NewStage();

        SetGameWindow();

        while (true)
        {   
            if (!(snake_live = play_snake.move()))
            {
                GameOver();
                break;
            }

            if (num_tick == 0)
            {
                play_items[0] = makeItem();
            }
            else if (num_tick == 5 + (3 * 1000 / tick))
            {
                play_items[1] = makeItem();
            }
            else if (num_tick == 10 + (6 * 1000 / tick))
            {
                play_items[2] = makeItem();
                play_gate = makeGate();
            }

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

            if (play_gate != nullptr)
            {
                int gate_check = play_gate->Check(play_snake.GetHead(), play_snake.GetTail(), play_snake.Length());
                if (gate_check == -1)
                {
                    int dir = play_gate->GetDirection(play_snake.GetDirection());
                    if (!snake_live == play_snake.move(dir, play_gate->GetOutPos()))
                    {
                        GameOver();
                        break;
                    }
                }
                else if (gate_check == 0 || gate_check == -2)
                {
                    delete play_gate;
                    play_gate = makeGate();
                }
                if (gate_check == -2)
                    play_snake.Reduce();
                play_gate->Show();
            }
            
            play_mission->IsAchieve(*play_info);

            if (play_mission->isCleared())
            {
                snake_live = true;
                NextStage();
                play_time += tick;
                num_tick++;
                break;
            }
        
            ScreenUpdate();
            usleep(tick * 1000);
            play_time += tick;
            num_tick++;
        }

        delete play_info;
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

    int item_type = rand() % 3;
    switch (item_type)
    {
    case 0:
    case 1:
        ans = new GrowthItem(*it);
        break;
    case 2:
        ans = new PoisonItem(*it);
        break;
    default:
        break;
    }

    play_map_point[0].erase(it);

    return ans;
}

Gate* makeGate()
{
    auto it1 = play_map_point[1].begin();
    auto it2= play_map_point[1].begin();

    int tmp1 = rand() % play_map_point[1].size();
    int tmp2 = rand() % (play_map_point[1].size() - 1);
    tmp2 += (tmp2 >= tmp1);

    for (int i = 0; i < tmp1; i++) it1++;
    for (int i = 0; i < tmp2; i++) it2++;

    Gate* ans = new Gate(*it1, *it2);

    play_map_point[1].erase(it1);
    play_map_point[1].erase(it2);

    return ans;
}

void TestGame()
{

}