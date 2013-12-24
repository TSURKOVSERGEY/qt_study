#include "desktop_item.h"


DesktopItem::DesktopItem()
{
}

DesktopItem::DesktopItem(const QList<QVariant> data) : BaseItem(data,BaseItem::pItem)
{
    BaseItem::pItem->childItems.append(this);
}

void DesktopItem::PushItemPointer(void)
{
    BaseItem::pItem = this;
}

void DesktopItem::PullItemPointer(void)
{
    BaseItem::pItem = pItem->parent();
}
