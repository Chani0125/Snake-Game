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
    bool snake_passing = false;
public:
    Gate();
    Gate(int x1, int y1, int x2, int y2);
    Gate(Point pos1, Point pos2);
    ~Gate();

    bool Check(Point snake_pos);
    void Show();
    void Hide();
    void Hide(Point snake_pos);
};

#endif