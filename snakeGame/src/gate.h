#ifndef _GATE_
#define _GATE_

#include <iostream>
#include "point.h"

using namespace std;

class Gate
{
private:
    Point pos1, pos2;
    int time;
    int in_gate_num;
    bool snake_passing = false;
    int out_dir;
public:
    Gate();
    Gate(int x1, int y1, int x2, int y2);
    Gate(Point pos1, Point pos2);
    ~Gate();

    int Check(Point snake_head_pos, Point snake_tail_pos, int snake_len);
    void Show();
    void Hide();
    void Hide(Point snake_pos);

    int GetDirection(int snake_dir);
    Point GetOutPos();
};

#endif