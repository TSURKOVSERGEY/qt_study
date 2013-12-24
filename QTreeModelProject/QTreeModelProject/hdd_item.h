#ifndef HDD_ITEM_H
#define HDD_ITEM_H

#include "base_item.h"
#include <QXmlAttributes>

class HddItem : public BaseItem
{
public:
    HddItem();
    HddItem(const QList<QVariant> data);

    virtual void PushItemPointer(void);
    virtual void PullItemPointer(void);


};

#endif // HDD_ITEM_H
