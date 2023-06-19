#include "item.h"
#include <iostream>
#include <vector>

using namespace std;

Item::Item(Point pos) : pos(pos) {}

Item::Item()
{
}

Item::~Item()
{
}

void Item::eaten()
{
    this->~Item();
}
