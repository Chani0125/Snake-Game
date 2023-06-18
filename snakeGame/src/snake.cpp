#include "snake.h"
#include "game_map.h"

Snake::Snake(/* args */)
{
    body.push_back({5,3});
    body.push_back({4,3});
    body.push_back({3,3});
    direction = 3;
    alive = true;
}

pair<int, int> Snake::getHead()
{
    return body.front();
}

bool Snake::move(pair<int, int> nextHead)
{
    body.insert(body.begin(), nextHead);
    body.pop_back();

    if(play_map[getHead().first][getHead().second] == 1){
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
        return move({this->getHead().first-1, this->getHead().second});
    case 2:
        return move({this->getHead().first, this->getHead().second+1});
    case 3:
        return move({this->getHead().first+1, this->getHead().second});
    case 4:
        return move({this->getHead().first, this->getHead().second-1});   
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