#include "game_map.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

#define FILENAME(n) "./map/map" + to_string(n) + ".txt"

using namespace std;

vector<vector<vector<short>>> map;
vector<vector<short>> play_map;

vector<int> unplayed_stage_num;
vector<int> played_stage_num;

int LoadMapFile()
{
    int file_num = 0;
    ifstream file;

    file.open(FILENAME(file_num));
    
    while(file.is_open())
    {
        if (file.eof())
        {
            file_num++;
            continue;
        }

        int x = 0, y = 0;
        string map_str_line;
        vector<vector<short>> tmp_map;

        getline(file, map_str_line);
        y = map_str_line.length();

        vector<short> tmp_map_line(y, 2);

        for (int i = 0; i < y; i++)
            tmp_map_line[i] = map_str_line[i] - '0';
        tmp_map.push_back(tmp_map_line); x++;

        while (!file.eof())
        {
            getline(file, map_str_line);
            for (int i = 0; i < y; i++)
                tmp_map_line[i] = map_str_line[i] - '0';
            tmp_map.push_back(tmp_map_line); x++;
        }

        map.push_back(tmp_map);
        unplayed_stage_num.push_back(file_num);

        file.close();
        file.open(FILENAME(++file_num));
    }

    return file_num;
}

int CreateMap(int map_num)
{
    if (map_num >= map.size())
    {
        cout << "You "
        map_num %= map.size();
    }
    play_map.resize(map[map_num].size(), vector<short>(map[map_num].size(), 2));
    copy(map[map_num].begin(), map[map_num].end(), play_map.begin());
    played_stage_num.push_back(map_num);
    return map_num;
}

int CreateMap(bool is_played_map)
{
    int map_num;
    srand(time(NULL));
    if (is_played_map)
        map_num = rand() % map.size();
    else
    {
        if (unplayed_stage_num.size() > 0)
        {
            auto it = unplayed_stage_num.begin() + (rand() % unplayed_stage_num.size());
            map_num = *it;
            unplayed_stage_num.erase(it);
        }
        else
        {
            cout << "You played all stage!" << "\n";
            map_num = rand() % map.size();
        }
    }
    return CreateMap(map_num);
}
