#include "item.h"
#include "game_map.h"
#include <iostream>
#include <vector>

using namespace std;

extern int tick;

Item::Item(Point pos) : pos(pos)
{
    time = (5 * 1000 / tick) + 20 + 1;
}

Item::Item() {}

Item::~Item() {}

bool Item::Check(Point snake_pos)
{
    if (snake_pos == pos)
        return 0;
    return --time;
}

void Item::Show()
{
    play_map[pos.x][pos.y] = item_type;
}

void Item::Hide()
{
    play_map[pos.x][pos.y] = game_map[PLAYING_MAP][pos.x][pos.y];
}

void Item::Hide(Point snake_pos)
{
    if (snake_pos == pos)
        play_map[pos.x][pos.y] = 3;
    else
        Hide();
}