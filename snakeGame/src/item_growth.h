#ifndef _GROWTH_ITEM_
#define _GROWTH_ITEM_

#include <iostream>
#include <vector>
#include "item.cpp"

using namespace std;

class GrowthItem : public Item
{
private:
    int growth;
public:
    GrowthItem(pair<int, int>);
    ~GrowthItem();
};



#endif