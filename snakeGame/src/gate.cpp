#include "gate.h"
#include <iostream>

using namespace std;

Gate::Gate(/* args */)
{
}

Gate::Gate(int x1, int y1, int x2, int y2)
{
    pos1.x = x1; pos1.y = y1;
    pos2.x = x2; pos2.y = y2;
}

Gate::~Gate()
{
}
