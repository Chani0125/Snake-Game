#ifndef _GROWTH_ITEM_
#define _GROWTH_ITEM_

#include <iostream>
#include <vector>
#include "item.cpp"

using namespace std;

class PoisonItem : public Item
{
private:

public:
    PoisonItem(pair<int, int>);
    ~PoisonItem();
};

PoisonItem::PoisonItem(pair<int, int> pos) : Item(pos)
{
}

PoisonItem::~PoisonItem()
{
}



#endif