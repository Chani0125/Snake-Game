#ifndef _GROWTH_ITEM_
#define _GROWTH_ITEM_

#include <iostream>
#include <vector>
#include "item.h"

using namespace std;

class GrowthItem : public Item
{
private:
    int growth;
public:
    GrowthItem(Point pos);
    ~GrowthItem();
};



#endif