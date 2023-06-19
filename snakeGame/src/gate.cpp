#include "gate.h"

using namespace std;

Gate::Gate() {}

Gate::Gate(int x1, int y1, int x2, int y2)
{
    pos1 = {x1, y1};
    pos2 = {x2, y2};
}

Gate::Gate(Point pos1, Point pos2) : pos1(pos1), pos2(pos2) {}

Gate::~Gate()
{
}
