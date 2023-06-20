#include "snake.h"
#include "game_map.h"
#include <ncurses.h>

#define NORTH   0
#define EAST    1
#define SOUTH   2
#define WEST    3
#define HEAD    body.front()
#define TAIL    body.back()

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

Snake::Snake()
{
    is_alive = true;
    is_eat_growth = false;
    // Set initial direction
    direction = EAST;
    // Make initial Head and Body
    for (int i = 0; i < 3; i++)
        body.insert(body.begin(), Point(2, 2 + i));
    Show();
}

Snake::~Snake()
{
}

Point Snake::GetHead() { return body.front(); }

Point Snake::GetTail() { return body.back(); }

int Snake::GetDirection() { return direction; }

int Snake::Length() { return body.size(); }

bool Snake::GetAlive() { return is_alive; }

bool Snake::GetEatGrowth() { return is_eat_growth; }

int Snake::size() { return body.size(); }

/**
 * @brief Move snake
 * 
 * @param next_pos  Next position of snake
 * @return true     Snake is Alive
 * @return false    Snake is Dead
 */
bool Snake::move(Point next_pos, bool reduce)
{
    int next_pos_map = play_map[next_pos.x][next_pos.y];

    body.insert(body.begin(), next_pos);

    Hide();

    if (reduce == true && next_pos_map != 6)
    {
        body.pop_back();
    }

    switch (next_pos_map)
    {
    // Case: Wall, Immune Wall, Snake Body
    case 1:
    case 2:
    case 4:
        is_alive = false;
        break;
    
    // Case: Gate
    case 5:
        break;
    
    // Case: Item Growth
    case 6:
        break;
    
    // Case: Item Poison
    case 7:
        body.pop_back();
        break;
    
    // Case: Item Fast Timer
    case 8:
        break;
    
    // Case: Item Slow Timer
    case 9:
        break;
    
    default:
        break;
    }

    Show();
    
    if (body.size() < 3)
        is_alive = false;
    
    return is_alive;
}

bool Snake::move(int dir)
{
    int x = body.front().x;
    int y = body.front().y;
    if (dir > 4)
    {
        cout << "You input incorrect number over max size!";
        cout << "Don't worry. I fixed it!" << "\n";
        dir %= 4;
    }
    direction = dir;
    return move({x+dx[dir], y+dy[dir]});
}

bool Snake::move(int dir, Point t_pos)
{
    direction = dir;
    return move({t_pos.x+dx[dir], t_pos.y+dy[dir]}, false);
}

bool Snake::move()
{
    switch (getch())
    {
    case KEY_UP:
        direction = NORTH;
        break;
    case KEY_DOWN:
        direction = SOUTH;
        break;
    case KEY_LEFT:
        direction = WEST;
        break;
    case KEY_RIGHT:
        direction = EAST;
        break;
    default:
        break;
    } 
    return move(direction);
}

void Snake::Reduce()
{
    Hide();
    body.pop_back();
    Show();
}

void Snake::Hide()
{
    for (auto it = body.begin(); it != body.end(); it++)
    {
        play_map[(*it).x][(*it).y] = game_map[PLAYING_MAP][(*it).x][(*it).y];

        for (int i = 0; i <= 1; i++)
            if (play_map[(*it).x][(*it).y] == i)
                play_map_point[i].insert(Point((*it).x, (*it).y));
    }

}

void Snake::Show()
{
    for (auto it = body.begin(); it != body.end(); it++)
    {
        play_map[(*it).x][(*it).y] = 4;

        for (int i = 0; i <= 1; i++)
            play_map_point[i].erase(Point((*it).x, (*it).y));
    }
    play_map[HEAD.x][HEAD.y] = 3;
}