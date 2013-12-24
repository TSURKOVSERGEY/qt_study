#include "room_item.h"


RoomItem::RoomItem()
{
}


RoomItem::RoomItem(const QList<QVariant> data) : BaseItem(data,BaseItem::pItem)
{
    BaseItem::pItem->childItems.append(this);
}

void RoomItem::PushItemPointer(void)
{
    BaseItem::pItem = this;
}

void RoomItem::PullItemPointer(void)
{
    BaseItem::pItem = pItem->parent();
}
