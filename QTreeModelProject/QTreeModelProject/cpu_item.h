#ifndef CPU_ITEM_H
#define CPU_ITEM_H

#include "base_item.h"
#include <QXmlAttributes>

class CpuItem : public BaseItem
{
public:
    CpuItem();
    CpuItem(const QList<QVariant> data);

    virtual void PushItemPointer(void);
    virtual void PullItemPointer(void);


};

#endif // CPU_ITEM_H
