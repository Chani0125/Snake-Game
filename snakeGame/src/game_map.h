#ifndef _GAME_MAP_
#define _GAME_MAP_

#include <vector>
#include <set>

using namespace std;

/*
0: Empty Space
1: Wall
2: Immune Wall
3: Snake Head
4: Snake Body
5: Item
6: Gate
*/
extern vector<vector<vector<int>>> map;
extern vector<vector<int>> game_map;

extern vector<int> unplayed_stage_num;
extern vector<int> played_stage_history;


int LoadMapFile();

int CreateMap(int map_num);
int CreateMap(bool is_played_map = true);

#endif