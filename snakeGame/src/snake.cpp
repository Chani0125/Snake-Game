#include "snake.h"
#include "game_map.h"

#define NORTH   0
#define EAST    1
#define SOUTH   2
#define WEST    3

Snake::Snake()
{
    body.push_back({5, 3});
    body.push_back({4, 3});
    body.push_back({3, 3});
    direction = 2;
    alive = true;
}

pair<int, int> Snake::GetHead()
{
    return body.front();
}



bool Snake::move(pair<int, int> nextHead)
{
    body.insert(body.begin(), nextHead);
    body.pop_back();

    if(play_map[GetHead().first][GetHead().second] == 1){
        return false;
    }else{
        return true;
    }
}

bool Snake::move(int direction)
{
    switch (direction)
    {
    case 1:
        return move({this->GetHead().first-1, this->GetHead().second});
    case 2:
        return move({this->GetHead().first, this->GetHead().second+1});
    case 3:
        return move({this->GetHead().first+1, this->GetHead().second});
    case 4:
        return move({this->GetHead().first, this->GetHead().second-1});   
    }
    return false;
}

bool Snake::move()
{
    return move(this->direction);
}

Snake::~Snake()
{
}