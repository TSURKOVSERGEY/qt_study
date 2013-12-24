#include "cpu_item.h"


CpuItem::CpuItem()
{
}

CpuItem::CpuItem(const QList<QVariant> data) : BaseItem(data,BaseItem::pItem)
{
    BaseItem::pItem->childItems.append(this);
}

void CpuItem::PushItemPointer(void)
{
    BaseItem::pItem = this;
}

void CpuItem::PullItemPointer(void)
{
    BaseItem::pItem = pItem->parent();
}
