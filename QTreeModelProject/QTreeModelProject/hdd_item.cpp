#include "hdd_item.h"

HddItem::HddItem()
{
}

HddItem::HddItem(const QList<QVariant> data) : BaseItem(data,BaseItem::pItem)
{
    BaseItem::pItem->childItems.append(this);
}

void HddItem::PushItemPointer(void)
{
    BaseItem::pItem = this;
}

void HddItem::PullItemPointer(void)
{
    BaseItem::pItem = pItem->parent();
}
