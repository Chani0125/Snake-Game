#include "game_map.h"
#include "trim.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

#define FILENAME(n) "./map/map" + to_string(n) + ".txt"

using namespace std;

vector<vector<vector<short>>> game_map;
vector<vector<short>> play_map;
vector<set<Point>> play_map_point(2, set<Point>());

vector<int> unplayed_stage_num;
vector<int> played_stage_history;

/**
 * @brief   Loading all .txt file in ./map directory to make game_map
 * 
 * @return  Number of Opened File
 */
int LoadMapFile()
{
    int file_num = 0;
    ifstream file;

    file.open(FILENAME(file_num));
    
    while(file.is_open())
    {
        // Check Correct File
        if (file.eof())
        {
            file_num++;
            continue;
        }

        // x: Map Height, y: Map Width
        int x = 0, y = 0;
        string map_str_line;
        vector<vector<short>> tmp_map;

        // Load Initial Text and Size
        getline(file, map_str_line);
        map_str_line = trim(map_str_line);
        y = map_str_line.length();

        vector<short> tmp_map_line(y, 2);

        // Save Initial Line
        for (int i = 0; i < y; i++)
            tmp_map_line[i] = map_str_line[i] - '0';
        tmp_map.push_back(tmp_map_line); x++;

        // Load until End of File
        while (!file.eof())
        {
            getline(file, map_str_line);
            map_str_line = trim(map_str_line);
            // Save Line
            for (int i = 0; i < y; i++)
                tmp_map_line[i] = map_str_line[i] - '0';
            tmp_map.push_back(tmp_map_line); x++;
        }

        // Save Map Info
        game_map.push_back(tmp_map);
        unplayed_stage_num.push_back(file_num);

        // Open New File
        file.close();
        file.open(FILENAME(++file_num));
    }

    return file_num;
}

/**
 * @brief           Load saved game_map to play_map selected by map_num
 * 
 * @param map_num   Select game_map by number
 */
int CreateMap(int map_num)
{
    if (map_num >= game_map.size())
    {
        cout << "You input incorrect number over max size!";
        cout << "Don't worry. I fixed it!" << "\n";
        map_num %= game_map.size();
    }

    play_map.resize(game_map[map_num].size(), vector<short>(game_map[map_num].size(), 2));
    copy(game_map[map_num].begin(), game_map[map_num].end(), play_map.begin());

    for (int i = 0; i <= 1; i++)
    {
        play_map_point[i] = set<Point>();
        for (int x = 0; x < MAP_H; x++)
            for (int y = 0; y < MAP_W; y++)
                if (play_map[x][y] == i)
                    play_map_point[i].insert(Point(x, y));
    }

    played_stage_history.push_back(map_num);
    unplayed_stage_num.erase(remove(unplayed_stage_num.begin(), unplayed_stage_num.end(), map_num), unplayed_stage_num.end());

    return map_num;
}

/**
 * @brief               Load saved game_map randomly to play_map
 * 
 * @param is_played_map True(default): load, False: In unplayed game_map, load
 */
int CreateMap(bool is_played_map)
{
    int map_num;
    srand(time(NULL));
    if (is_played_map)
        map_num = rand() % game_map.size();
    else
    {
        if (unplayed_stage_num.size() > 0)
        {
            auto it = unplayed_stage_num.begin() + (rand() % unplayed_stage_num.size());
            map_num = *it;
        }
        else
        {
            cout << "You played all stage!" << "\n";
            map_num = rand() % game_map.size();
        }
    }
    return CreateMap(map_num);
}
