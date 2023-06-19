#include "item_poison.h"

PoisonItem::PoisonItem(Point pos) : Item(pos)
{
    item_type = 7;
    Show();
}

PoisonItem::~PoisonItem() {}
