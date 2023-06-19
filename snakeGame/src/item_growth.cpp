#include "item_growth.h"

GrowthItem::GrowthItem(Point pos) : Item(pos)
{
    item_type = 6;
    Show();
}

GrowthItem::~GrowthItem() {}
