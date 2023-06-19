#ifndef _GAME_MAP_
#define _GAME_MAP_

#include <vector>
#include <set>
#include "point.h"

#define MAP_H       play_map.size()
#define MAP_W       play_map[0].size()
#define PLAYING_MAP played_stage_history.back()
#define STAGE       played_stage_history.size()

using namespace std;

/**
 * 0: Empty Space
 * 1: Wall
 * 2: Immune Wall
 * 3: Snake Head
 * 4: Snake Body
 * 5: Gate
 * 6: Item Growth
 * 7: Item Poison
 * 8: Item Fast Timer
 * 9: Item Slow Timer
 */
extern vector<vector<vector<short>>> game_map;
extern vector<vector<short>> play_map;
extern vector<set<Point>> play_map_point;

extern vector<int> unplayed_stage_num;
extern vector<int> played_stage_history;

int LoadMapFile();

int CreateMap(int map_num);
int CreateMap(bool is_played_map = true);

#endif