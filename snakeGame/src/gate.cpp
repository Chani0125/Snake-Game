#include "gate.h"
#include "game_map.h"

using namespace std;

extern int tick;

Gate::Gate() {}

Gate::Gate(int x1, int y1, int x2, int y2) : Gate({x1, y1}, {x2, y2}) {}

Gate::Gate(Point pos1, Point pos2) : pos1(pos1), pos2(pos2)
{
    time = (5 * 1000 / tick) + 20 + 1;
    Show();
}

Gate::~Gate()
{
    play_map_point[1].insert(pos1);
    play_map_point[1].insert(pos2);
    Hide();
}

bool Gate::Check(Point snake_pos)
{
    if (snake_pos == pos1)
    {
        snake_passing = true;
    }
    else if (snake_pos == pos2)
    {
        snake_passing = true;
    }

    if (!snake_passing)
        time--;
        
    return time;
}

void Gate::Show()
{
    play_map[pos1.x][pos1.y] = play_map[pos2.x][pos2.y] = 5;
}

void Gate::Hide()
{
    play_map[pos1.x][pos1.y] = play_map[pos2.x][pos2.y] = 1;
}

void Gate::Hide(Point snake_pos)
{
    Hide();
}
