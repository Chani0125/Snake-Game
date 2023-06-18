#ifndef _SNAKE_
#define _SNAKE_

#include<iostream>
#include<vector>

using namespace std;

class Snake
{
private:
    bool alive;
    int direction; // 1,2,3,4 - north, east, south, west
    vector<pair<int,int>> body; //row,col
public:
    Snake(/* args */);
    pair<int, int> getHead();
    bool move();
    bool move(pair<int, int>);
    bool move(int direction);
    ~Snake();
};

#endif