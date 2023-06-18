#ifndef _POISON_ITEM_
#define _POISON_ITEM_

#include <iostream>
#include <vector>
#include "item.h"

using namespace std;

class PoisonItem : public Item
{
private:
    int poison;
public:
    PoisonItem(pair<int, int>);
    ~PoisonItem();
};


#endif