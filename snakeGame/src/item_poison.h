#ifndef _POISON_ITEM_
#define _POISON_ITEM_

#include <iostream>
#include <vector>
#include "item.h"

using namespace std;

class PoisonItem : public Item
{
private:
public:
    PoisonItem(Point pos);
    ~PoisonItem();
};


#endif