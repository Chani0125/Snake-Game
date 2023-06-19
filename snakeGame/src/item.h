#ifndef _ITEM_
#define _ITEM_

#include "point.h"
#include <iostream>
#include <vector>

using namespace std;

class Item
{
protected:
    int item_type = 0;
    Point pos;
    int time;
public:
    Item(Point pos);
    Item();
    ~Item();
    
    bool Check(Point snake_pos);
    void Show();
    void Hide();
    void Hide(Point snake_pos);
};

#endif