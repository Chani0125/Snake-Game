#ifndef _ITEM_
#define _ITEM_

#include <iostream>
#include <vector>

using namespace std;

class Item
{
protected:
    pair<int, int> pos;

public:
    Item(pair<int, int>);
    ~Item();
};

Item::Item(pair<int, int> pos) : pos(pos)
{
}

Item::~Item()
{
}



#endif