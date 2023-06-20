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

int Gate::Check(Point snake_head_pos, Point snake_tail_pos, int snake_len)
{
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    if (snake_passing)
    {
        if (in_gate_num == 1)
        {
            if (snake_tail_pos == pos2 + Point(dx[out_dir], dy[out_dir]))
            {
                return -2;
            }
        }
        else if (in_gate_num == 2)
        {
            if (snake_tail_pos == pos1 + Point(dx[out_dir], dy[out_dir]))
            {
                return -2;
            }
        }
    }
    else
    {
        if (snake_head_pos  == pos1)
        {
            snake_passing = true;
            in_gate_num = 1;
            return -1;
        }
        else if (snake_head_pos == pos2)
        {
            snake_passing = true;
            in_gate_num = 2;
            return -1;
        }
        else
        {
            time--;
        }
    }
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

int Gate::GetDirection(int snake_dir)
{
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    int tmp_map_info;
    if (in_gate_num == 1)
    {
        for (int i = snake_dir; i < snake_dir+4; i++)
        {
            if (0 <= pos2.x+dx[i%4] && pos2.x+dx[i%4] < MAP_H && 0 <= pos2.y+dy[i%4] && pos2.y+dy[i%4] < MAP_W)
            {
                tmp_map_info = play_map[pos2.x+dx[i%4]][pos2.y+dy[i%4]];
                if (Point(pos2.x+dx[i%4], pos2.y+dy[i%4]) == pos1)
                    continue;
                if (tmp_map_info != 1 && tmp_map_info != 2 && tmp_map_info != 5)
                {
                    return (out_dir = i%4);
                }
            }
        }
    }
    else if (in_gate_num == 2)
    {
        for (int i = snake_dir; i < snake_dir+4; i++)
        {
            if (0 <= pos1.x+dx[i%4] && pos1.x+dx[i%4] < MAP_H && 0 <= pos1.y+dy[i%4] && pos1.y+dy[i%4] < MAP_W)
            {
                tmp_map_info = play_map[pos1.x+dx[i%4]][pos1.y+dy[i%4]];
                if (Point(pos1.x+dx[i%4], pos1.y+dy[i%4]) == pos2)
                    continue;
                if (tmp_map_info != 1 && tmp_map_info != 2 && tmp_map_info != 5)
                {
                    return (out_dir = i%4);
                }
            }
        }
    }

    return 0;
}

Point Gate::GetOutPos()
{
    if (in_gate_num == 1)
        return pos2;
    else if (in_gate_num == 2)
        return pos1;
    return Point();
}