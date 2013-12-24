#include "base_item.h"

BaseItem::BaseItem()
{
}

BaseItem::BaseItem(const QList<QVariant> data,void* pVitem) : TreeItem(data,(TreeItem*)pVitem)
{
}

void BaseItem::PushItemPointer(void)
{
}

void BaseItem::PullItemPointer(void)
{
}
