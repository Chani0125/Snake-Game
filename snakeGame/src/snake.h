#ifndef _SNAKE_
#define _SNAKE_

#include<iostream>
#include<vector>

using namespace std;

/**
 * @param direction 0: N, 1: E, 2: S, 3: W
 * @param body      pair: {pos_x, pos_y}
 */
class Snake
{
private:
    bool alive;
    int direction;
    vector<pair<int,int>> body;
public:
    Snake();
    pair<int, int> GetHead();
    bool move();
    bool move(pair<int, int>);
    bool move(int direction);
    ~Snake();
};

#endif