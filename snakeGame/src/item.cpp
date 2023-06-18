#include "item.h"
#include <iostream>
#include <vector>

using namespace std;

Item::Item(pair<int, int> pos)
{
    this->pos = pos;
}

Item::~Item()
{
}