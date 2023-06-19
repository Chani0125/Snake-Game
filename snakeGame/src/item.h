#ifndef _ITEM_
#define _ITEM_

#include "point.h"
#include <iostream>
#include <vector>

using namespace std;

class Item
{
protected:
    Point pos;
    int time;
public:
    Item(Point pos);
    Item();
    ~Item();
    void eaten();
};


#endif