#ifndef _SNAKE_
#define _SNAKE_

#include "point.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * @param is_alive      snake state
 * @param is_eat_growth check snake ate growth item in this turn
 * @param direction     0: N, 1: E, 2: S, 3: W
 * @param body          pair: {pos_x, pos_y}
 */
class Snake
{
private:
    bool is_alive;
    bool is_eat_growth;
    int direction;
    vector<Point> body;
public:
    Snake();
    ~Snake();

    // getter
    Point GetHead();
    bool GetAlive();
    bool GetEatGrowth();

    int size();

    bool move();
    bool move(Point next_pos);
    bool move(int direction);
    
    void InteractMap(bool is_short = true);

};

#endif