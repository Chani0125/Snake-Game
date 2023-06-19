#ifndef _GATE_
#define _GATE_

#include <iostream>
#include "point.h"

using namespace std;

class Gate
{
private:
    Point pos1, pos2;
public:
    Gate();
    Gate(int x1, int y1, int x2, int y2);
    ~Gate();
};

#endif