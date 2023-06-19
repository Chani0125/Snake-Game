#include "snake.h"
#include "game_map.h"

#define NORTH   0
#define EAST    1
#define SOUTH   2
#define WEST    3

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

Snake::Snake()
{
    is_alive = true;
    is_eat_growth = false;
    // Set initial direction
    direction = SOUTH;
    // Make initial Head and Body
    for (int i = 0; i < 3; i++)
        body.push_back({5-i, 2});
}

Snake::~Snake()
{
}

Point Snake::GetHead() { return body.front(); }

bool Snake::GetAlive() { return is_alive; }

bool Snake::GetEatGrowth() { return is_eat_growth; }

int Snake::size() { return body.size(); }

bool Snake::move(Point next_pos)
{
    body.insert(body.begin(), next_pos);

    int next_pos_map = play_map[next_pos.x][next_pos.y];

    if (next_pos_map != 6)
        body.pop_back();

    // Case: Wall, Immune Wall, Snake Body
    if (next_pos_map == 1 || next_pos_map == 2 || next_pos_map == 4)
        is_alive = false;
    else if (next_pos_map == 5) // Case: Gate
    {

    }
    else if (next_pos_map == 6) // Case: Item Growth
    {

    }
    else if (next_pos_map == 7) // Case: Item Poison
    {
        body.pop_back();
        if (body.size() < 3)
            is_alive = false;
    }
    else if (next_pos_map == 8) // Case: Item Fast Timer
    {
        
    }
    else if (next_pos_map == 9) // Case: Item Slow Timer
    {

    }


    return is_alive;
}

bool Snake::move(int dir)
{
    int x = this->body.front().x;
    int y = this->body.front().y;
    if (dir > 4)
    {
        cout << "You input incorrect number over max size!";
        cout << "Don't worry. I fixed it!" << "\n";
        dir %= 4;
    }
    return move({x-dx[dir], y-dy[dir]});
}

bool Snake::move()
{
    return move(this->direction);
}
